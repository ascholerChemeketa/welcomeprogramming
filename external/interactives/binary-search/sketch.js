let numVals = 10;
let numbers = new Array(numVals);
let isKeySet = false;
let keyInUse = 0;
let done = false;

let low = 0;
let high = numbers.length - 1;
let mid = Math.floor((low + high) / 2);

function setup() {
  const cnv = createCanvas(700, 400);
  cnv.parent('sketch-holder');
  strokeWeight(2);
  textFont('Consolas, monospace');

  binarySearchReset();
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
  const xOffset = 45;

  textSize(14);
  textFont('Consolas, monospace');
  textAlign(CENTER, BASELINE);

  // base bars (white)
  for (let i = 0; i < numbers.length; i++) {
    fill('#4b4242ff');
    const barHeight = ((numbers[i] + 1) / max) * h;
    rect(i * unitWidth + xOffset, height - 20 - barHeight, unitWidth, barHeight);
    fill(0, 102, 153);
    text(numbers[i], (i + 0.5) * unitWidth + xOffset, height - 25 - barHeight);
    text(i, (i + 0.5) * unitWidth + xOffset, height - 5);
  }

  // range bars (gray) for indices low..high
  for (let i = low; i <= high; i++) {
    fill('#e2e2e2ff');
    const barHeight = ((numbers[i] + 1) / max) * h;
    rect(i * unitWidth + xOffset, height - 20 - barHeight, unitWidth, barHeight);
  }

  
  // status text and highlight mid
  if (isKeySet) {
    fill('#000000');
    textAlign(LEFT, TOP);
    text(`Search for key ${keyInUse}`, 10, 15);
    text(`Current low index: ${low}`, 10, 30);
    text(`Current high index: ${high}`, 10, 45);
    text(`Middle index: floor((${low} + ${high}) / 2) = ${mid}`, 10, 75);

    if (low > high) {
      text('Low index is higher than high index - value is not present!', 10, 90);
    } else {
      if (numbers[mid] < keyInUse) {
        text(`Middle value = ${numbers[mid]}\n  ...too low, update low index to ${mid + 1}`, 10, 90);
      }
      if (numbers[mid] > keyInUse) {
        text(`Middle value = ${numbers[mid]}\n  ...too high, update high index to ${mid - 1}`, 10, 90);
      }
      if (numbers[mid] === keyInUse) {
        text('Value found at middle index', 10, 90);
      }

      // highlight mid bar
      fill('#9db9d3');
      const barHeight = ((numbers[mid] + 1) / max) * h;
      rect((mid) * unitWidth + xOffset, height - 20 - barHeight, unitWidth, barHeight);
    }
  }


  // for (let i = 0; i < numbers.length; i++) {
  //   fill('#e2e2e2ff'); // dim gray
  //   const barHeight = ((numbers[i] + 1) / max) * h;
  //   rect(i * unitWidth + 30 + xOffset, height - barHeight, unitWidth, barHeight - 20);

  //   fill(0, 102, 153);
  //   // value labels
  //   textAlign(CENTER, CENTER);
  //   text(numbers[i], (i + 0.5) * unitWidth + xOffset, height - ((numbers[i] + 1) / max) * h - 7, unitWidth);
  //   // index labels
  //   text(i , (i + 0.5) * unitWidth + xOffset, height - 10, unitWidth);
  // }

  // axis label
  fill(0);
  textAlign(LEFT, CENTER);
  text('index', 0, height - 11);

  // status text
  // fill('#000000');
  // if (isKeySet) {
  //   text(`Search for key ${keyInUse}`, 10, 15);
  //   text(`currentIndex: ${coloredBarIndex}`, 10, 30);
  // }


}

// Shuffle and reset state
function binarySearchReset() {
  isKeySet = false;
  coloredBarIndex = -1;
  done = false;
  low = 0;
  high = numbers.length - 1;
  mid = Math.floor((low + high) / 2);
  randomSeed(42);
  for (let i = 0; i < numbers.length; i++) {
    numbers[i] = 5 * (i + 1) + int(random(5));
  }
}

// public wrappers for buttons
window.binarySearchReset = binarySearchReset;
window.getKeyBS = function() { return keyInUse; };

// Step function: returns index (>=0) when found, -1 for keep searching, -2 when not found
function binarySearchStep(key) {
  if (!isKeySet) {
    isKeySet = true;
    keyInUse = key;
  } else {
    if (done) return mid;

    if (low > high) return -2; // out of range

    if (keyInUse === numbers[mid]) {
      done = true;
      return mid;
    } else if (keyInUse > numbers[mid]) {
      low = mid + 1; // discard lower half
      mid = Math.floor((low + high) / 2);
      if (low > high) return -2;
      return -1;
    } else { // keyInUse < numbers[mid]
      high = mid - 1; // discard upper half
      mid = Math.floor((low + high) / 2);
      if (low > high) return -2;
      return -1;
    }
  }
}

window.binarySearchStep = binarySearchStep;
