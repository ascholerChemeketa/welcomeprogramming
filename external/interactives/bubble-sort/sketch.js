// p5.js version of the Bubble Sort (non-adaptive) interactive

let listLen = 10;
let list = new Array(listLen);

// bubble sort indices
let passIdx = 0;   // completed passes; also size of sorted suffix
let curj = 0;      // current inner-loop index comparing j and j+1
let adaptive = false;      // adaptive mode toggle
let didSwapInPass = false; // tracks if any swap occurred during current pass
const xOffset = 45;

function setup() {
  const cnv = createCanvas(600, 400);
  cnv.parent('sketch-holder');
  strokeWeight(2);
  textFont('Consolas, monospace');

  // initialize list with 1..n
  for (let i = 0; i < list.length; i++) {
    list[i] = i + 1;
  }

  bubbleReset();
}

function draw() {
  background(255);
  drawBars();
}

function getMax(arr) {
  let max = arr[0];
  for (let i = 1; i < arr.length; i++) {
    if (max < arr[i]) max = arr[i];
  }
  return max;
}

function drawBars() {
  const h = height * 0.6;
  const w = width - 60;
  const unitWidth = w / list.length;
  const max = getMax(list);

  // stroke('#000000');
  textSize(14);
  textAlign(CENTER, BASELINE);

  for (let i = 0; i < list.length; i++) {
    stroke('#000000');
    // sorted suffix grows from the end: last passIdx elements are done
    if (i >= list.length - passIdx) {
      fill('#ffffff'); // sorted
    } else {
      fill('#C0C0C0'); // unsorted
    }
    rect(i * unitWidth + xOffset, height - ((list[i] + 1) / max) * h, unitWidth, ((list[i] + 1) / max) * h - 20);
    noStroke();

    fill(0, 102, 153);
    text(list[i], (i + 0.5) * unitWidth + xOffset, height - ((list[i] + 1) / max) * h - 7);
    text(i, (i + 0.5) * unitWidth + xOffset, height - 5);
  }


  drawSingleBars();

  fill(0);
  textAlign(LEFT, BASELINE);
  text('index', 5, height - 5);
  text(`i = ${passIdx} (pass number)`, 10, 15);
  text(`j = ${curj} (current comparison index)`, 10, 30);
  if(adaptive) {  
    text(`didSwap = ${didSwapInPass} (whether a swap occurred in this pass)`, 10, 45);
  }
}

function drawSingleBars() {
  const h = height * 0.6;
  const w = width - 60;
  const unitWidth = w / list.length;
  const max = getMax(list);

  textAlign(LEFT, BASELINE);
  // messages and highlights for current pair (j, j+1)
  const limit = Math.max(0, list.length - 2 - passIdx); // last j index that compares j and j+1
  if (passIdx < list.length - 1) {
    if (curj <= limit) {
      fill(0);
      text(`Compare indices j=${curj} and j+1=${curj + 1}`, 10, 75);
      if (list[curj] > list[curj + 1]) {
        text('They are out of order; will swap.', 10, 90);
      } else {
        text('They are in order; no swap.', 10, 90);
      }

      // highlight current pair
      stroke('#000000');
      fill('#9db9d3');
      rect(curj * unitWidth + xOffset, height - ((list[curj] + 1) / max) * h, unitWidth, ((list[curj] + 1) / max) * h - 20);
      stroke('#9db9d3');
      fill('#fff');
      rect((curj + 1) * unitWidth + xOffset, height - ((list[curj + 1] + 1) / max) * h, unitWidth, ((list[curj + 1] + 1) / max) * h - 20);
      noStroke();
    } else {
      fill(0);
      text('End of inner pass: the largest of this pass has bubbled to the end.', 10, 75);
      if (adaptive && !didSwapInPass) {
        text('No swaps occurred in this pass; the list is sorted.', 10, 90);
      }
    }
  }
}

function bubbleReset() {
  shuffleList();
  passIdx = 0;
  curj = 0;
  didSwapInPass = false;
}

function bubbleResetMostlySorted() {
  list = [1, 10, 2, 3, 4, 5, 8, 6, 7, 9];
  passIdx = 0;
  curj = 0;
  didSwapInPass = false;
}

function shuffleList() {
  for (let i = 0; i < list.length; i++) {
    const index = int(random(list.length));
    const temp = list[index];
    list[index] = list[i];
    list[i] = temp;
  }
}

// returns true when sorted, else false (non-adaptive: completes all passes)
function bubbleStep() {
  // all passes completed
  if (passIdx >= list.length - 1) return true;

  const limit = list.length - 2 - passIdx;
  // start of a new pass: reset swap tracker
  if (curj === 0) {
    didSwapInPass = false;
  }

  if (curj <= limit) {
    // compare and swap adjacent pair if out of order
    if (list[curj] > list[curj + 1]) {
      const tmp = list[curj];
      list[curj] = list[curj + 1];
      list[curj + 1] = tmp;
      didSwapInPass = true;
    }
    curj++;
    return false;
  } else {
    // end of inner loop: one more largest element placed at end
    passIdx++;
    curj = 0;
    // adaptive early exit: if no swaps occurred in this pass, the list is sorted
    if (adaptive && !didSwapInPass) {
      passIdx = list.length - 1;
      return true;
    }
    didSwapInPass = false;
    return passIdx >= list.length - 1;
  }
}

// expose for HTML buttons
window.bubbleReset = bubbleReset;
window.bubbleResetMostlySorted = bubbleResetMostlySorted;
window.bubbleStep = bubbleStep;
window.bubbleSetAdaptive = function(enabled) { adaptive = !!enabled; };
