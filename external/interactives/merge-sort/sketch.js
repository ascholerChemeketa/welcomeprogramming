// p5.js version of Merge Sort that steps like a recursive algorithm (visual call stack)

let list = [];
let tempList = [];

// Visual call stack of frames representing recursive calls
// Frame shape: { start, end, mid, stage: 'split'|'merge', next: 'left'|'right'|'mergeInit', i, j, k }
let frames = [];


function setup() {
  const cnv = createCanvas(600, 500);
  cnv.parent('sketch-holder');
  strokeWeight(2);
  textFont('Consolas, monospace');
  textAlign(CENTER, TOP);

  mergeSortResetLarge();
}

function draw() {
  background(255);
  stroke('#000000');
  fill('#677915');

  drawBars();
  drawCurrentFrameOverlay();
  drawTempForFrame();
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
  let xOffset = 29;
  // if (list.length === 32) {
  //   xOffset = 0;
  // }
  const xstart = (width - unitWidth * list.length) / 2 + xOffset;

  const max = getMax(list);
  stroke('#000000');
  textSize(14);
  // Current active frame for shading and merge progress
  const f = frames.length ? frames[frames.length - 1] : null;

  for (let i = 0; i < list.length; i++) {
    // Decide the value to render for this index
    let renderVal = list[i];
    const boxSize = (h * renderVal) / max;
    // shade by halves when a current frame exists
    let colorVal = 210;
    if (f) {
      let curMid = Math.floor((f.start + f.end) / 2);
      if (i >= f.start && i <= f.end) {
        colorVal = i <= curMid ? 192 : 235;
      } else {
        colorVal = 230;
      }
    }

    if (f && f.stage && i >= f.start && i <= f.end && f.stage === 'copy') {
        colorVal = '#818181';
    }

    //but override if merging to show next choices and progress
    if (f && f.stage === 'merge') {
      if (i >= f.start && i < f.k) {
        colorVal = '#818181';
      }
      if (i === f.i && f.i <= f.mid) {
        colorVal = '#9db9d3';
      } else if (i === f.j && f.j <= f.end) {
        colorVal = '#689260ff';
      }
    }

    fill(colorVal);
    rect(i * unitWidth + xstart, starth - boxSize, unitWidth, boxSize + 1);
    noStroke();
    fill(0, 102, 153);
    if (renderVal > 0 && list.length === 8) text(renderVal, xstart + (i + 0.5) * unitWidth, starth - boxSize - 15);

    if(list.length === 8)
    text(i, xstart + (i + 0.5) * unitWidth, starth + 5);
    stroke('#000000');
  }
  fill(0);
  noStroke();
  textAlign(RIGHT, TOP);
  text('list', xstart - 5, starth - h/2);
  if(list.length === 8)
  text('index', xstart - 5, starth + 5);
}

function drawCurrentFrameOverlay() {
  const f = frames.length ? frames[frames.length - 1] : null;
  if (!f) return;
  const h = height * 0.25;
  const starth = height - 21;
  const w = width - 61;
  const unitWidth = w / list.length;
  let xOffset = 29;
  // if (list.length === 32) {
  //   xOffset = 0;
  // }
  const xstart = (width - unitWidth * list.length) / 2 + xOffset;


  // Outline current frame range
  stroke('#ee2222');
  noFill();
  if(list.length === 8)
  rect(f.start * unitWidth + xstart, starth - h - 20, (f.end - f.start + 1) * unitWidth, h + 40);
  else
  rect(f.start * unitWidth + xstart, starth - h - 1, (f.end - f.start + 1) * unitWidth, h+2);
  stroke('#000000');

  // Status text
  fill(0);
  textAlign(LEFT, TOP);
  
  noStroke();
  let curY = 25;
  if (f.stage === 'split')
    text(`Sorting range [${f.start}..${f.end}]`, 10, 10);
  else if (f.stage === 'copy')
    text(`Copying temp back to list in range [${f.start}..${f.end}]`, 10, 10);
  else if (f.stage === 'merge') {
    text(`Merging range [${f.start}..${f.mid}] and [${f.mid + 1}..${f.end}]`, 10, 10);
    text(`  into [${f.start}..${f.end}] in temp`, 10, 25);
    curY += 15;
  }

  if(f.stage === 'split' && f.start === f.end) {
    text(`(size 1 segment; returning)`, 10, curY);
  } else if(f.stage === 'split') {
    if( f.next === 'left') {
      text(`(Split left half)`, 10, curY);
    }
    else if( f.next === 'right') {
      text(`(left half done; Split right half next)`, 10, curY);
    } else if( f.next === 'mergeInit') {
      text(`(right half done; next merge)`, 10, curY);
    }
  }

  // Draw call stack
  let callY = 10;
  text('Call Stack:', width - 250, callY);
  callY += 15;
  for (let i = 0; i < frames.length; i++) {
    const cf = frames[i];
    let cfStageText = 'Sorting';
    text(`${cfStageText} range [${cf.start}..${cf.end}]`, width - 250, callY);
    callY += 15;
  }
  if (frames.length > 0) {
    let lastFrame = frames[frames.length - 1];
    if (lastFrame.stage === 'merge') {
      text(`Merging range [${lastFrame.start}..${lastFrame.end}]`, width - 250, callY);
    }
  }

}

function drawTempForFrame() {
  const f = frames.length ? frames[frames.length - 1] : null;
  if (!f) return;
  // if (!f || (f.stage !== 'merge' && f.stage !== 'copy')) return;
  const h = height * 0.25;
  const starth = height * 0.68;
  const w = width - 61;
  const unitWidth = w / list.length;
  let xOffset = 29;
  // if (list.length === 32) {
  //   xOffset = 0;
  // }
  const xstart = (width - unitWidth * list.length) / 2 + xOffset;
  const max = getMax(list);

  textSize(14);
    fill('#000000');
    noStroke();

  textAlign(RIGHT, TOP);
  text('temp', xstart - 5, starth - h/2);

  for (let i = 0; i < list.length; i++) {
    let val = tempList[i];
    if (f.stage !== 'merge' || (i < f.start || i >= f.k)) {
      val = 3; // outside current merge range
    }
    const boxSize = (h * val) / max;
    let colorVal = ('#FFF');
    stroke('#000000');
    fill(colorVal);
    rect(i * unitWidth + xstart, starth - boxSize - 20, unitWidth, Math.max(0, boxSize));
    if(f.stage === 'merge') {
      noStroke();
      if( i < f.start || i >= f.k) {
        fill(192);
        
        textAlign(CENTER, TOP);
        if(list.length === 8)
          text('?', (i + 0.5) * unitWidth + xstart, starth - boxSize / 2 - 35);
        else
          text('?', (i + 0.5) * unitWidth + xstart, starth - boxSize / 2 - 50);
      } else {
        fill(0, 102, 153);
        text(val, (i + 0.5) * unitWidth + xstart, starth - boxSize - 35);
      }
    } else {
      noStroke();
        textAlign(CENTER, TOP);
      fill(192);
        if(list.length === 8)
          text('?', (i + 0.5) * unitWidth + xstart, starth - boxSize / 2 - 35);
        else
          text('?', (i + 0.5) * unitWidth + xstart, starth - boxSize / 2 - 50);
    }
    stroke('#000000');
  }
}

function mergeSortReset() {
  list = new Array(8);
  for (let i = 0; i < list.length; i++) list[i] = i + 1;
  shuffleList();
  tempList = new Array(list.length).fill(0);
  frames = [];
  const start = 0, end = list.length - 1;
  const mid = Math.floor((start + end) / 2);
  frames.push({ start, end, mid, stage: 'split', next: 'left', i: start, j: mid + 1, k: start });
}

function mergeSortResetLarge() {
  list = new Array(32);
  for (let i = 0; i < list.length; i++) list[i] = i + 1;
  shuffleList();
  tempList = new Array(list.length).fill(0);
  frames = [];
  const start = 0, end = list.length - 1;
  const mid = Math.floor((start + end) / 2);
  frames.push({ start, end, mid, stage: 'split', next: 'left', i: start, j: mid + 1, k: start });
}

function shuffleList() {
  for (let i = 0; i < list.length; i++) {
    const index = int(random(list.length));
    const temp = list[index];
    list[index] = list[i];
    list[i] = temp;
  }
}

// One recursive-style step; returns true when fully sorted
function mergeSortStep() {
  if (frames.length === 0) return true; // done

  const f = frames[frames.length - 1];

  if (f.stage === 'split') {
    if (f.start >= f.end) {
      // Leaf: do not show a size-1 merge; immediately return to parent
      frames.pop();
      return frames.length === 0; // continue unless all done
    }

    if (f.next === 'left') {
      const mid = Math.floor((f.start + f.end) / 2);
      frames.push({ start: f.start, end: mid, mid, stage: 'split', next: 'left', i: f.start, j: mid + 1, k: f.start });
      f.next = 'right';
      return false;
    }

    if (f.next === 'right') {
      const mid = Math.floor((f.start + f.end) / 2);
      frames.push({ start: mid + 1, end: f.end, mid: Math.floor((mid + 1 + f.end) / 2), stage: 'split', next: 'left', i: mid + 1, j: f.end + 1, k: mid + 1 });
      f.next = 'mergeInit';
      return false;
    }

    if (f.next === 'mergeInit') {
      const mid = Math.floor((f.start + f.end) / 2);
      f.mid = mid;
      f.i = f.start;
      f.j = mid + 1;
      f.k = f.start;
      f.stage = 'merge';
      tempList = new Array(list.length).fill(0);
      return false;
    }
  }

  // Merge stage for frame f
  if (f.stage === 'merge') {
    if (f.i <= f.mid && f.j <= f.end) {
      if (list[f.i] <= list[f.j]) {
        tempList[f.k++] = list[f.i++];
      } else {
        tempList[f.k++] = list[f.j++];
      }
      return false;
    }
    if (f.i <= f.mid) {
      tempList[f.k++] = list[f.i++];
      return false;
    }
    if (f.j <= f.end) {
      tempList[f.k++] = list[f.j++];
      return false;
    }

    // Merge finished: schedule a dedicated copy-back step
    f.stage = 'copy';
    for (let p = f.start; p <= f.end; p++) {
      list[p] = tempList[p];
    }
    return false;
  }

  // Copy-back stage as its own full step
  if (f.stage === 'copy') {
    for (let p = f.start; p <= f.end; p++) {
      list[p] = tempList[p];
    }
    frames.pop();
    return frames.length === 0; // true if everything finished
  }

  return false;
}

// expose for HTML
window.mergeSortReset = mergeSortReset;
window.mergeSortResetLarge = mergeSortResetLarge;
window.mergeSortStep = mergeSortStep;