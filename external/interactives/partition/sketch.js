// p5.js interactive partition (Hoare-style pointers, user-driven)

let list = [];
let finalized = [];

// Partition state
let pivotIndex = 0;
let pivotValue = 0;
let i = 0;
let j = 0;
let finished = false;
let lastMessage = '';

function setup() {
  const cnv = createCanvas(600, 250);
  cnv.parent('sketch-holder');
  strokeWeight(2);
  textFont('Consolas, monospace');
  textSize(14);
  textAlign(CENTER, TOP);

  partitionReset();
}

function draw() {
  background(255);
  stroke('#000000');
  fill('#677915');

  drawBars();
  drawOverlay();
}

function getMax(arr) {
  let max = arr[0];
  for (let k = 1; k < arr.length; k++) {
    if (arr[k] > max) max = arr[k];
  }
  return max;
}

function drawBars() {
  const h = height * 0.5;
  const starth = height - 20;
  const w = width - 60;
  const unitWidth = w / list.length;
  const xOffset = 30;
  const xstart = (width - unitWidth * list.length) / 2 + xOffset - 1;

  const max = getMax(list);
  stroke('#000000');
  textSize(14);

  for (let idx = 0; idx < list.length; idx++) {
    const val = list[idx];
    const boxSize = (h * val) / max;
    let colorVal = 235;

    if (finalized[idx]) colorVal = '#FFFFFF';
    if (idx === pivotIndex) colorVal = '#ff9900';
    if (!finished) {
      if (idx === i) colorVal = '#9db9d3';
      if (idx === j) colorVal = '#689260';
      if (i === j && idx === i) colorVal = '#83A69A';
    } else {
      if (idx === j) colorVal = '#ff9900';
      if (idx === 0) colorVal = 235;
    }

    fill(colorVal);
    rect(idx * unitWidth + xstart, starth - boxSize, unitWidth, boxSize + 1);
    noStroke();
    fill(0, 102, 153);
  textAlign(CENTER, TOP);
    text(val, xstart + (idx + 0.5) * unitWidth, starth - boxSize - 15);
    text(idx, xstart + (idx + 0.5) * unitWidth, starth + 5);
    stroke('#000000');
  }

  fill(0);
  noStroke();
  textAlign(RIGHT, TOP);
  text('index', xstart - 5, starth + 5);
}

function drawOverlay() {
  const h = height * 0.35;
  const starth = height - 20;
  const w = width - 60;
  const unitWidth = w / list.length;
  const xstart = (width - unitWidth * list.length) / 2;


  // Status text
  fill(0);
  textAlign(LEFT, TOP);
  let y = 10;
  noStroke();
  const status = finished ? 'Done (pivot placed)' : 'Interactive Partition';
  text(`${status}`, 10, y); y += 15;
  text(`Pivot value: ${pivotValue} (index ${pivotIndex})`, 10, y); y += 15;
  text(`i (leftIndex): ${i}`, 10, y); y += 15;
  text(`j (rightIndex): ${j}`, 10, y); y += 15;
  if (lastMessage) { text(lastMessage, 10, y); y += 15; }
}

function shuffleList() {
  for (let k = 0; k < list.length; k++) {
    const idx = int(random(list.length));
    const temp = list[idx];
    list[idx] = list[k];
    list[k] = temp;
  }
}

// Public API
function partitionReset() {
  list = new Array(16);
  for (let k = 0; k < list.length; k++) list[k] = k + 1;
  shuffleList();
  finalized = new Array(list.length).fill(false);
  // Ensure pivot index is 0, with a pivot value between 5 and 11
  // Find a candidate in the shuffled list with value in [5, 11]
  let candidateIdx = -1;
  for (let idx = 0; idx < list.length; idx++) {
    const v = list[idx];
    if (v >= 5 && v <= 11) { candidateIdx = idx; break; }
  }
  if (candidateIdx === -1) {
    // Fallback should never happen with values 1..16, but guard anyway
    candidateIdx = 0;
  }
  // Move that candidate to index 0
  if (candidateIdx !== 0) {
    const tmp = list[0];
    list[0] = list[candidateIdx];
    list[candidateIdx] = tmp;
  }
  pivotIndex = 0;
  pivotValue = list[pivotIndex];
  i = pivotIndex + 1;
  j = list.length - 1;
  finished = false;
  lastMessage = '';
}

function partitionIncrementLeft() {
  if (finished) { lastMessage = 'Partition already done'; return; }
  if (i > j) { lastMessage = 'Invalid: pointers crossed (i > j)'; return; }
  if (i >= j  + 1) { lastMessage = 'Invalid: partition is done'; return; }
  if (list[i] >= pivotValue) { lastMessage = `Invalid: list[i]=${list[i]} ≥ pivot=${pivotValue}`; return; }
  i = i + 1;
  lastMessage = `i incremented to ${i}`;
}

function partitionDecrementRight() {
  if (finished) { lastMessage = 'Partition already done'; return; }
  if (i > j) { lastMessage = 'Invalid: pointers crossed (i > j)'; return; }
  if (j <= i  - 1) { lastMessage = 'Invalid: partition is done'; return; }
  if (list[j] <= pivotValue) { lastMessage = `Invalid: list[j]=${list[j]} ≤ pivot=${pivotValue}`; return; }
  j = j - 1;
  lastMessage = `j decremented to ${j}`;
}

function partitionSwap() {
  if (finished) { lastMessage = 'Partition already done'; return; }
  if (i > j) { lastMessage = 'Invalid: cannot swap when i > j'; return; }
  // Valid swap only when list[i] is on wrong side (>= pivot) and list[j] on wrong side (<= pivot)
  if (!(list[i] >= pivotValue && list[j] <= pivotValue)) {
    lastMessage = `Invalid: need list[i] ≥ pivot and list[j] ≤ pivot (have ${list[i]} and ${list[j]})`;
    return;
  }
  const tmp = list[i];
  list[i] = list[j];
  list[j] = tmp;
  lastMessage = `Swapped indices i=${i} and j=${j}`;
}

function partitionDone() {
  if (finished) { lastMessage = 'Already done'; return; }
  if (i <= j) { lastMessage = 'Invalid: cannot finish until i > j'; return; }
  // Final pivot swap with j
  const tmp = list[pivotIndex];
  list[pivotIndex] = list[j];
  list[j] = tmp;
  finalized[j] = true;
  finished = true;
  lastMessage = `Pivot placed at index ${j}. Partition done.`;
  window.parent.postMessage({ subject: 'SPLICE.reportScoreAndState', score: 1, state: {} }, '*');
}

// Expose for HTML
window.partitionReset = partitionReset;
window.partitionIncrementLeft = partitionIncrementLeft;
window.partitionDecrementRight = partitionDecrementRight;
window.partitionSwap = partitionSwap;
window.partitionDone = partitionDone;