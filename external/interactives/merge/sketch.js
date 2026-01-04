// p5.js version of the Merge interactive (left/right choices)

let listLen = 8;
let list = new Array(listLen);
let tempList = new Array(listLen).fill(0);

let mergeStart = 0;
let mergeEnd = listLen - 1;
let mergeMid = Math.floor((mergeStart + mergeEnd) / 2);
let mergeI = mergeStart;         // current index in left half
let mergeJ = mergeMid + 1;       // current index in right half
let mergeTarget = mergeStart;    // current write index in tempList

let errorMsg = '';
const xOffset = 30;

function setup() {
  let docWidth = document.getElementById('sketch-holder').offsetWidth;
  const cnv = createCanvas(docWidth, 400);
  cnv.parent('sketch-holder');
  strokeWeight(2);
  textFont('Consolas, monospace');
  textAlign(CENTER, TOP);

  // initialize sequential values (we will distribute between halves)
  for (let i = 0; i < list.length; i++) {
    list[i] = i + 1;
  }

  mergeReset();
  requestResize();
}

function draw() {
  background(255);
  drawSourceBars();
  drawMergedBars();

  // error message
  if (errorMsg) {
    fill('#ee2222');
    text('Wrong list!', width / 2, 15);
  }
}

function getMax(arr) {
  let max = arr[0];
  for (let i = 1; i < arr.length; i++) {
    if (arr[i] > max) max = arr[i];
  }
  return max;
}

function drawSourceBars() {
  const h = height * 0.3;
  const starth = height * .5;
  const w = width - 60;
  const unitWidth = w / list.length;
  const xstart = (width - unitWidth * list.length) / 2;

  const max = getMax(list);
  stroke('#000000');
  textSize(14);

  for (let i = 0; i < list.length; i++) {
    // if (i === mergeMid + 1) xstart += unitWidth; // visual gap between halves

    stroke('#000000');
    const boxSize = (h * list[i]) / max;
    let colorVal = ('#FFF');
    if (i < mergeI || (i > mergeMid && i < mergeJ))
      colorVal = '#818181ff';
    fill(colorVal);
    rect(i * unitWidth + xstart, starth - boxSize, unitWidth, boxSize + 1);

    // highlight current candidates
    if (i === mergeI || i === mergeJ) {
      if( i == mergeI && mergeI <= mergeMid)
      fill('#9db9d3');
    else if (i == mergeJ)
      fill('#689260ff');

      rect(i * unitWidth + xstart, starth - boxSize, unitWidth, boxSize + 1);
    }

    noStroke();
    fill('#000000');
    text(list[i], xstart + (i + 0.5) * unitWidth, starth - boxSize - 15);
    text(i, xstart + (i + 0.5) * unitWidth, starth + 5);
  }

  // labels
  textAlign(LEFT, TOP);
      fill('#000000');
  text(`nextLeft = ${mergeI}`, 25, 0);
      // fill('#689260ff');
  text(`nextRight = ${mergeJ}`, 25, 15);
  text(`mergeLocation = ${mergeTarget}`, 25, 30);
}

function drawMergedBars() {
  const h = height * 0.35;
  const starth = height - 20;
  const w = width - 60;
  const unitWidth = w / list.length;
  const xstart = (width - unitWidth * list.length) / 2;

  const max = getMax(list);
  textSize(14);

  for (let i = 0; i < tempList.length; i++) {
    const val = tempList[i];
    const boxSize = (h * val) / max;
    fill('#FFF');
    stroke('#000000');
    rect(i * unitWidth + xstart, starth - boxSize - 20, unitWidth, Math.max(0, boxSize));
    noStroke();
    fill(0, 102, 153);
    // if (val > 0) {
      text(val, (i + 0.5) * unitWidth + xstart, starth - boxSize - 35);
      text(i, (i + 0.5) * unitWidth + xstart, starth -15);
    //}
  }
}

function mergeReset() {
  // clear temp list
  tempList = new Array(list.length).fill(0);

  // distribute increasing values between left and right halves randomly
  let iVal = 1;
  let j = 0;
  let k = Math.floor(list.length / 2);
  while (j < Math.floor(list.length / 2) || k < list.length) {
    if (j >= Math.floor(list.length / 2)) {
      list[k++] = iVal++;
    } else if (k >= list.length) {
      list[j++] = iVal++;
    } else {
      if (Math.floor(random(2)) === 0) {
        list[k++] = iVal++;
      } else {
        list[j++] = iVal++;
      }
    }
  }

  mergeStart = 0;
  mergeEnd = list.length - 1;
  mergeMid = Math.floor((mergeStart + mergeEnd) / 2);
  mergeI = mergeStart;
  mergeJ = mergeMid + 1;
  mergeTarget = mergeStart;
  errorMsg = '';
}

function isDone() {
  return (mergeJ > mergeEnd && mergeI > mergeMid);
}

function mergeTakeLeft() {
  // done is success
  if (mergeJ > mergeEnd && mergeI > mergeMid) return true;

  if (mergeJ > mergeEnd || (mergeI <= mergeMid && list[mergeI] <= list[mergeJ])) {
    tempList[mergeTarget] = list[mergeI];
    mergeTarget++;
    mergeI++;
    return true;
  }
  return false;
}

function mergeTakeRight() {
  // done is success
  if (mergeJ > mergeEnd && mergeI > mergeMid) return true;

  if (mergeI > mergeMid || (mergeJ <= mergeEnd && list[mergeJ] <= list[mergeI])) {
    tempList[mergeTarget] = list[mergeJ];
    mergeTarget++;
    mergeJ++;
    return true;
  }
  return false;
}

// expose for HTML
window.mergeReset = mergeReset;
window.mergeTakeLeft = mergeTakeLeft;
window.mergeTakeRight = mergeTakeRight;