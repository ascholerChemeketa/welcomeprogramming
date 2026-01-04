// p5.js version of the Selection Sort interactive

let listLen = 10;
let list = new Array(listLen);

// selection sort indices
let curi = 0;      // current position to place the minimum
let curj = 1;      // current scanning index
let minIndex = 0;  // current minimum index in the unsorted region
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

  selectionReset();
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
    if (i < curi) {
      // already sorted prefix
      fill('#ffffff');
    } else {
      // unsorted region
      fill('#C0C0C0');
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
  text(`i = ${curi} (start of unsorted region)`, 10, 15);
  if(curi === curj) {
    // cheat a little to show where j starts
    text(`j = ${curj + 1} (scan index)`, 10, 30);
  } else {  
    text(`j = ${curj} (scan index)`, 10, 30);
  }
  text(`minIndex = ${minIndex} (index of current minimum)`, 10, 45);
}

function drawSingleBars() {
  const h = height * 0.6;
  const w = width - 60;
  const unitWidth = w / list.length;
  const max = getMax(list);

  textAlign(LEFT, BASELINE);
  if (curi < list.length) {
    if (curj === curi) {
        fill(0);
        text(`Pass ${curi + 1}: Find smallest remaining value to place in index ${curi}.`, 10, 75);
        text(`Assume it has smallest value.`, 10, 90);
        text('Use j to count through unsorted region', 10, 105);
    }
    else if (curj < list.length) {
      fill(0);
      text(`Compare values at j (${curj}) and minIndex (${minIndex})`, 10, 75);
      if (list[curj] < list[minIndex]) {
        text(`New minimum found at index ${curj}. Update minIndex to ${curj}.`, 10, 90);
      }
      else {
        text(`No new minimum found`, 10, 90);
      }
    } else {
      fill(0);
      text('End of scan reached.', 10, 75);
      text(`Swap items at indexes i (${curi}) and minIndex (${minIndex})`, 10, 90);
    }

    stroke('#000000');
    fill('#96c170');
    rect(curi * unitWidth + xOffset, height - ((list[curi] + 1) / max) * h, unitWidth, ((list[curi] + 1) / max) * h - 20);
    noStroke();

    if (curi !== minIndex) {
      stroke('#000000');
      fill('#9db9d3');
      rect(minIndex * unitWidth + xOffset, height - ((list[minIndex] + 1) / max) * h, unitWidth, ((list[minIndex] + 1) / max) * h - 20);
      noStroke();
    }

    // current scan j highlighted blue if within bounds
    if (curj < list.length) {
      stroke('#9db9d3');
      fill('#fff');
      let tempj = curj;
      if (curj === curi) {
        // cheat a little to show where j starts
        tempj = curj + 1;
      }
      rect(tempj * unitWidth + xOffset, height - ((list[tempj] + 1) / max) * h, unitWidth, ((list[tempj] + 1) / max) * h - 20);
      noStroke();
    }
  }
}

function selectionReset() {
  shuffleList();
  curi = 0;
  minIndex = 0;
  curj = 0;
}

function selectionResetMostlySorted() {
  list = [1, 3, 4, 2, 5, 7, 8, 6, 9, 10];
  curi = 0;
  minIndex = 0;
  curj = 0;
}

function shuffleList() {
  for (let i = 0; i < list.length; i++) {
    const index = int(random(list.length));
    const temp = list[index];
    list[index] = list[i];
    list[i] = temp;
  }
}

// returns true when sorted, else false
function selectionStep() {
  // if sorted prefix has reached end, we're done
  if (curi >= list.length - 1) return true;

  // scan to find minimum in [curi..end)
  if (curj < list.length) {
    if (list[curj] < list[minIndex]) {
      minIndex = curj;
    }
    curj++;
    return false;
  }

  // end of scan: swap min into position curi
  const tmp = list[curi];
  list[curi] = list[minIndex];
  list[minIndex] = tmp;

  // move boundary forward and reset scan
  curi++;
  minIndex = curi;
  curj = curi;

  // check if we just finished
  return curi >= list.length - 1;
}

// expose for HTML buttons
window.selectionReset = selectionReset;
window.selectionResetMostlySorted = selectionResetMostlySorted;
window.selectionStep = selectionStep;
