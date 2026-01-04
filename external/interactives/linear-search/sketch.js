let numVals = 10;
let numbers = new Array(numVals);
let isKeySet = false;
let keyInUse = 0;
let done = false;
let coloredBarIndex = -1;

function setup() {
  const cnv = createCanvas(700, 400);
  cnv.parent('sketch-holder');
  strokeWeight(2);
  textFont('Consolas, monospace');
  // randomSeed(second() + millis());

  linearSearchReset();
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
  const h = height * 0.80;
  const w = width - 75;
  const unitWidth = w / numbers.length;
  const max = getMax(numbers);
  const xOffset = 15;

  textSize(14);
  textFont('Consolas, monospace');
  textAlign(CENTER, BASELINE);

  for (let i = 0; i < numbers.length; i++) {
    fill('#e2e2e2ff'); // dim gray
    const barHeight = ((numbers[i] + 1) / max) * h;
    rect(i * unitWidth + 30 + xOffset, height - barHeight, unitWidth, barHeight - 20);

    fill(0, 102, 153);
    // value labels
    textAlign(CENTER, CENTER);
    text(numbers[i], (i + 0.5) * unitWidth + xOffset, height - ((numbers[i] + 1) / max) * h - 7, unitWidth);
    // index labels
    text(i , (i + 0.5) * unitWidth + xOffset, height - 10, unitWidth);
  }

  // axis label
  fill(0);
  textAlign(LEFT, CENTER);
  text('index', 0, height - 11);

  // status text
  fill('#000000');
  if (isKeySet) {
    text(`Search for key ${keyInUse}`, 10, 15);
    text(`currentIndex: ${coloredBarIndex}`, 10, 30);
  }

  // highlighted bar
  fill('#9db9d3');
  if (coloredBarIndex >= 0 && coloredBarIndex < numbers.length) {
    const i = coloredBarIndex;
    rect(i * unitWidth + 30 + xOffset, height - ((numbers[i] + 1) / max) * h, unitWidth, ((numbers[i] + 1) / max) * h - 20);
  }
}

// Shuffle and reset state
function linearSearchReset() {
  isKeySet = false;
  coloredBarIndex = -1;
  done = false;
  
  for (let i = 0; i < numbers.length; i++) {
    numbers[i] = 5 * (i + 1) + int(random(5));
  }

  // shuffle numbers (Fisher-Yates style)
  for (let i = 0; i < numbers.length; i++) {
    const index = int(random(numbers.length));
    const tmp = numbers[index];
    numbers[index] = numbers[i];
    numbers[i] = tmp;
  }
}

// public wrappers for buttons
window.linearSearchReset = linearSearchReset;
window.getKeyP5 = function() { return keyInUse; };

// Step function: returns index (>=0) when found, -1 for keep searching, -2 when not found
function linearSearchStep(key) {
  if (!isKeySet) {
    isKeySet = true;
    keyInUse = key;
  }

  if (done) return coloredBarIndex >= numbers.length ? -2 : coloredBarIndex;

  coloredBarIndex++;

  if (coloredBarIndex >= numbers.length) {
    done = true; // found
    return -2; // out of range, not found
  }

  if (numbers[coloredBarIndex] === keyInUse) {
    done = true; // found
    return coloredBarIndex;
  } else {
    return -1; // keep searching
  }
}

window.linearSearchStep = linearSearchStep;
