// p5.js version of the Insertion Sort interactive

let listLen = 10;
let list = new Array(listLen);

let curi = 1;
let curj = 1;
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

  insertionReset();
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
    if (i <= curi || curi === list.length - 1) {
      fill('#ffffff');
    } else {
      fill('#C0C0C0'); // dim gray
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
  // fill('#9db9d3');
  text(`i = ${curi} (current item starting location)`, 10, 15);
  text(`j = ${curj} (current item current location)`, 10, 30);
}

function drawSingleBars() {
  const h = height * 0.6;
  const w = width - 60;
  const unitWidth = w / list.length;
  const max = getMax(list);

  textAlign(LEFT, BASELINE);
  if (curj === 0 || list[curj] > list[curj - 1]) {

    if( curj !== 0 ) {
      
    fill(0);
    text(`Current item is larger than value index ${curj - 1} (${list[curj - 1]})`, 10, 60);
    text(`Current item done`, 10, 75);
    stroke('#9db9d3');
    fill('#ffffff');
    rect((curj - 1) * unitWidth + xOffset, height - ((list[curj - 1] + 1) / max) * h, unitWidth, ((list[curj - 1] + 1) / max) * h - 20);
    } else {
      
    fill(0);
    text('Current item reached index 0', 10, 60);
    text(`Current item done`, 10, 75);
    }

    stroke('#000000');
    fill('#9db9d3');
    rect(curj * unitWidth + xOffset, height - ((list[curj] + 1) / max) * h, unitWidth, ((list[curj] + 1) / max) * h - 20);
    noStroke();
  }
  else if (curj < list.length) {
    fill(0);
    let curY = 60;
    if(curi === curj) {
      text(`Starting pass ${curi}`, 10, curY);
      curY += 15;
    }
    text(`Current item is smaller than value at index ${curj - 1} (${list[curj - 1]})`, 10, curY);
    curY += 15;
    text(`Current item swaps left`, 10, curY);

    stroke('#9db9d3');
    fill('#ffffff');
    rect((curj - 1) * unitWidth + xOffset, height - ((list[curj - 1] + 1) / max) * h, unitWidth, ((list[curj - 1] + 1) / max) * h - 20);

    stroke('#000000');    
    fill('#9db9d3');
    rect(curj * unitWidth + xOffset, height - ((list[curj] + 1) / max) * h, unitWidth, ((list[curj] + 1) / max) * h - 20);
    noStroke();
  }
}

function insertionReset() {
  shuffleList();
  curi = 1;
  curj = 1;
}

function insertionResetMostlySorted() {
  list = [1, 3, 4, 2, 5, 7, 8, 6, 9, 10];
  curi = 1;
  curj = 1;
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
function insertionStep() {
  if (curi === -1) { curi = 1; curj = 1; return false; }
  if (curi === list.length) return true; // sorted

  if (curj === 0 || list[curj] >= list[curj - 1]) {
    // done with this item
    curi++;
    curj = curi;
  } else {
    // slide left
    const temp = list[curj];
    list[curj] = list[curj - 1];
    list[curj - 1] = temp;
    curj--;
  }

  return false;
}

// expose for HTML buttons
window.insertionReset = insertionReset;
window.insertionResetMostlySorted = insertionResetMostlySorted;
window.insertionStep = insertionStep;
