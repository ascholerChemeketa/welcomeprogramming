// p5.js in-place quicksort interactive (Hoare partition; recursive via explicit call stack)

let list = [];
let finalized = [];
// Visual call stack frames for quicksort
// Frame: { start, end, stage: 'init'|'scanLeft'|'scanRight'|'swapPair'|'advanceAfterSwap'|'partitionDone', i, j, pivotIndex, pivotValue }
let frames = [];
let callStack = [];

function setup() {
  const cnv = createCanvas(600, 400);
  cnv.parent('sketch-holder');
  strokeWeight(2);
  textFont('Consolas, monospace');
  textAlign(CENTER, TOP);

  let ordered = window.quicksortOrdered || false;
  if (ordered) {
    quickSortResetSorted();
  } else {
    quickSortReset();
  }
}

function draw() {
  background(255);
  stroke('#000000');
  fill('#677915');

  drawBars();
  drawCurrentFrameOverlay();
}

function getMax(arr) {
  let max = arr[0];
  for (let i = 1; i < arr.length; i++) {
    if (arr[i] > max) max = arr[i];
  }
  return max;
}

function drawBars() {
  const h = height * .25;
  const starth = height - 20;
  const w = width - 61;
  const unitWidth = w / list.length;
  let xOffset = 30;

  const xstart = (width - unitWidth * list.length) / 2 + xOffset;

  const max = getMax(list);
  stroke('#000000');
  textSize(14);
  // Current active frame for shading and partition progress
  const f = frames.length ? frames[frames.length - 1] : null;

  for (let i = 0; i < list.length; i++) {
    // Decide the value to render for this index
    let renderVal = list[i];
    const boxSize = (h * renderVal) / max;

    let colorVal = 210;
    // finalized indices: locked in place (white)
    if (finalized[i]) colorVal = '#FFFFFF';
    if (f) {
      // Highlight pivot and pointers during Hoare partition
      if (f.stage === 'init' || f.stage === 'scanLeft' || f.stage === 'scanRight' || f.stage === 'swapPair' || f.stage === 'partitionDone' || f.stage === 'advanceAfterSwap') {
        const pivotIdx = f.pivotIndex;
        if (i === pivotIdx) colorVal = '#ff9900'; // pivot
        if (typeof f.i === 'number' && i === f.i) colorVal = '#9db9d3'; // left pointer
        if (typeof f.j === 'number' && i === f.j) colorVal = '#689260'; // right pointer
        if (i === f.i && f.i === f.j) colorVal = '#83A69A'; // both pointers
      }
    }

    textAlign(CENTER, TOP);
    fill(colorVal);
    rect(i * unitWidth + xstart, starth - boxSize, unitWidth, boxSize + 1);
    noStroke();
    fill(0, 102, 153);
    if (renderVal > 0 && list.length === 16) text(renderVal, xstart + (i + 0.5) * unitWidth, starth - boxSize - 15);

    if (list.length === 16) {
      textAlign(CENTER, TOP);
      text(i, xstart + (i + 0.5) * unitWidth, starth + 5);
    }
    stroke('#000000');
  }
  fill(0);
  noStroke();
  textAlign(RIGHT, TOP);
  if (list.length === 16)
    text('index', xstart - 5, starth + 5);
}

function drawCurrentFrameOverlay() {
  const f = frames.length ? frames[frames.length - 1] : null;
  if (!f) return;
  const h = height * 0.25 + 1;
  const starth = height - 21;
  const w = width - 60;
  const unitWidth = w / list.length;
  let xOffset = 29;

  const xstart = (width - unitWidth * list.length) / 2 + xOffset;


  // Outline current frame range
  stroke('#ee2222');
  noFill();
  if (list.length === 16)
    rect(f.start * unitWidth + xstart, starth - h - 20, (f.end - f.start + 1) * unitWidth, h + 40);
  else
    rect(f.start * unitWidth + xstart, starth - h + 2, (f.end - f.start + 1) * unitWidth, h + 2);
  stroke('#000000');

  // Status text
  fill(0);
  textAlign(LEFT, TOP);

  let textY = 10;
  noStroke();
  let stageText = 'Partitioning';
  if (f.stage === 'partitionDone') stageText = 'Partition done';
  text(`${stageText} range [${f.start}..${f.end}]`, 10, textY);
  textY += 15;

  if(f.start === f.end) {
    textY += 15;
    text(`Single element range, no action needed`, 10, textY);
    textY += 15;
    text(`Return start index as final pivot location`, 10, textY);
    textY += 15;
  }
  else if (['scanLeft', 'scanRight', 'swapPair', 'partitionDone', 'advanceAfterSwap'].includes(f.stage)) {
    text(`Pivot value: ${f.pivotValue} (index ${f.pivotIndex})`, 10, textY);
    textY += 15;
    text(`i (left index): ${f.i}`, 10, textY);
    textY += 15;
    text(`j (right index): ${f.j}`, 10, textY);
    textY += 15;
  }



  let substageText = '';
  if (f.stage === 'scanLeft') substageText = `Scanning from left for value > pivot (${f.pivotValue})`;
  if (f.stage === 'scanRight') substageText = `Scanning from right for value < pivot (${f.pivotValue})`;
  if (f.stage === 'swapPair') {
    if (f.i <= f.j)
      substageText = `Swapping pair at i=${f.i} and j=${f.j}`;
    else {
      textY += 15;
      substageText = `Swapping elements at pivot=${f.pivotIndex}`;
      text(`${substageText}`, 10, textY);
      substageText = `  and j=${f.j} to complete partition`;
    }
  }
  if (f.stage === 'advanceAfterSwap') substageText = 'Increase i and decrease j after swap';

  if (substageText !== '') {
    textY += 15;
    text(`${substageText}`, 10, textY);
    textY += 15;
  }
  if ((f.stage === 'scanLeft' || f.stage === 'scanRight') && f.i > f.j) {
    textY += 15;
    text(`i is greater than j, stop partition`, 10, textY);
    textY += 15;
  }
  else if (f.stage === 'scanLeft' && list[f.i] >= f.pivotValue) {
    textY += 15;
    text(`Found value ${list[f.i]} >= pivot`, 10, textY);
    textY += 15;
  }
  else if (f.stage === 'scanRight' && list[f.j] <= f.pivotValue) {
    textY += 15;
    text(`Found value ${list[f.j]} <= pivot`, 10, textY);
    textY += 15;
  }

  if (f.stage === 'partitionDone' && f.start < f.end) {
    textY += 15;
    text(`Done with partition.. `, 10, textY);
    textY += 15;
    text(`return j (${f.j}) as pivot location`, 10, textY);
    textY += 15;
  }

  // Draw call stack
  let callY = 10;
  text('Call Stack:', width - 250, callY);
  callY += 15;
  for (let i = 0; i < callStack.length; i++) {
    const cf = callStack[i];
    let cfStageText = 'Quicksort';
    text(`${cfStageText} [${cf.start}..${cf.end}]`, width - 250, callY);
    callY += 15;
  }
  // if (frames.length > 0) {
  //   let lastFrame = frames[frames.length - 1];
  //   if (lastFrame.stage === 'swapPair') {
  //     text(`Swapping i,j in [${lastFrame.start}..${lastFrame.end}]`, width - 250, callY);
  //   } else if (lastFrame.stage === 'advanceAfterSwap') {
  //     text(`Advancing pointers in [${lastFrame.start}..${lastFrame.end}]`, width - 250, callY);
  //   }
  // }

}
// Quicksort doesn't use a temp array; no secondary row needed

function quickSortReset() {
  list = new Array(16);
  for (let i = 0; i < list.length; i++) list[i] = i + 1;
  shuffleList();
  frames = [];
  finalized = new Array(list.length).fill(false);
  const start = 0, end = list.length - 1;
  frames.push({ start, end, stage: 'init' });
  callStack = [];
  callStack.push({ start, end });
}

function quickSortResetLarge() {
  list = new Array(32);
  for (let i = 0; i < list.length; i++) list[i] = i + 1;
  shuffleList();
  frames = [];
  finalized = new Array(list.length).fill(false);
  const start = 0, end = list.length - 1;
  frames.push({ start, end, stage: 'init' });
  callStack = [];
  callStack.push({ start, end });
}

function quickSortResetSorted() {
  list = new Array(16);
  for (let i = 0; i < list.length; i++) list[i] = i + 1;

  frames = [];
  finalized = new Array(list.length).fill(false);
  const start = 0, end = list.length - 1;
  frames.push({ start, end, stage: 'init' });
  callStack = [];
  callStack.push({ start, end });
}

function shuffleList() {
  for (let i = 0; i < list.length; i++) {
    const index = int(random(list.length));
    const temp = list[index];
    list[index] = list[i];
    list[i] = temp;
  }
}

// One quicksort step (Hoare partition); returns true when fully sorted
function quickSortStep() {

  if (frames.length === 0) return true; // done
  const f = frames[frames.length - 1];

  // // Skip ranges of size 0 or 1
  if (f.stage !== 'partitionDone' && f.start >= f.end) {
    f.stage = 'partitionDone';
    finalized[f.start] = true;
    return false;
  }
  else if (f.stage === 'init') {
    if (callStack.length == 0 || callStack[callStack.length -1].start !== f.start || callStack[callStack.length -1].end !== f.end)
      callStack.push({ start: f.start, end: f.end });
    f.pivotIndex = f.start;
    f.pivotValue = list[f.pivotIndex];
    f.i = f.start + 1;
    f.j = f.end;
    f.stage = 'scanLeft';
    return false;
  }

  else if (f.stage === 'scanLeft') {
    if (list[f.i] < f.pivotValue && f.j >= f.i) {
      f.i++;
      return false;
    } else {
      f.stage = 'scanRight';
      return false;
    }
  }

  else if (f.stage === 'scanRight') {
    if (list[f.j] > f.pivotValue && f.j >= f.i) {
      f.j--;
      return false;
    } else {
      f.stage = 'swapPair';
      return false;
    }
  }

  else if (f.stage === 'swapPair') {
    if (f.i <= f.j) {
      const tmp = list[f.i];
      list[f.i] = list[f.j];
      list[f.j] = tmp;
      // Separate the pointer advancement into its own step
      f.stage = 'advanceAfterSwap';
      return false;
    } else {
      const tmp = list[f.pivotIndex];
      list[f.pivotIndex] = list[f.j];
      list[f.j] = tmp;
      // Pivot now fixed at index j
      finalized[f.j] = true;
      f.stage = 'partitionDone';
      return false;
    }
  }

  else if (f.stage === 'advanceAfterSwap') {
    // Advance pointers after a completed swap
    f.i++;
    f.j--;
    f.stage = 'scanLeft';
    return false;
  }

  else if (f.stage === 'partitionDone') {
    // After final pivot swap, pivot at j is locked; recurse on [start..j-1] and [j+1..end]
    const leftStart = f.start, leftEnd = f.j - 1;
    const rightStart = f.j + 1, rightEnd = f.end;
    frames.pop();
    // Push right then left so left runs next
    if (rightStart <= rightEnd) {
      frames.push({ start: rightStart, end: rightEnd, stage: 'init' });
      if (leftStart > leftEnd ) {
        // this will be next call
        callStack.push({ start: rightStart, end: rightEnd });
      }
    }
    if (leftStart <= leftEnd ) {
      frames.push({ start: leftStart, end: leftEnd, stage: 'init' });
      callStack.push({ start: leftStart, end: leftEnd });
    }

    //quick ugly call stack management
    let done = true;
    for(let i = f.start; i <= f.end; i++) {
      if(!finalized[i]) {
        done = false;
        break;
      }
    }
    if(done) {
      while(callStack.length > 0 && finalized[callStack[callStack.length -1].end]) {
        callStack.pop();
      }
      let call = callStack[callStack.length -1];
      callStack.pop();
      let frame = frames[frames.length -1];
      if (frame && (frame.start !== call.start || frame.end !== call.end)) {
        callStack.push({start: frame.start, end: frame.end}); 
      }
    }

    return frames.length === 0;
  }

  return false;
}

// also expose explicit quicksort names
window.quickSortReset = quickSortReset;
window.quickSortResetLarge = quickSortResetLarge;
window.quickSortStep = quickSortStep;
window.quickSortResetSorted = quickSortResetSorted;