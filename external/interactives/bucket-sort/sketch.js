// p5.js interactive: Bucket/Counting Sort for Students by Class Standing

// Student shape: { name: string, standing: 'Fr'|'So'|'Jr'|'Sr' }
let students = [];
let output = [];

// Counting arrays/objects
let counts = { Fr: 0, So: 0, Jr: 0, Sr: 0 };         // frequency per standing
let startIndex = { Fr: 0, So: 0, Jr: 0, Sr: 0 };     // starting index in output per standing (by order)
let nextPos = { Fr: 0, So: 0, Jr: 0, Sr: 0 };        // moving pointer per standing during placement

// Order of collection (ascending by default: Freshman -> Senior)
let collectOrder = ['Fr', 'So', 'Jr', 'Sr'];

// State machine
// Phases: 'count' -> 'prefix' -> 'place' -> 'done'
let phase = 'count';
let countIndex = 0;     // index into students during counting
let prefixIdx = 0;      // index into collectOrder during prefix computation
let runningSum = 0;     // accumulator during prefix computation
let placeIndex = 0;     // index into students during placement
let lastPlacedOutputIndex = -1; // for highlighting during placement

// Visual config
const boxH = 40;       // a bit taller to allow two lines of text
const namePad = 0;
const cellW = 40;     // narrower item width since standing is below name now
const swatchW = 0;    // width of colored standing swatch

function setup() {
  const cnv = createCanvas(700, 450);
  cnv.parent('sketch-holder');
  strokeWeight(2);
  textFont('Consolas, monospace');
  textAlign(LEFT, CENTER);

  bucketReset();
}

function draw() {
  background(255);
  drawUI();
}

function bucketReset() {
  const possibleNames = [
    'Ava','Ben','Cara','Dan','Eli','Fay','Gus','Hana','Ian','Jia','Kai','Lia',
    'Max','Nia','Oli','Pia','Quin','Raj','Sia','Tao'
  ];
  const stands = ['Fr','So','Jr','Sr'];

  // Make a small list of 10 students
  students = [];
  for (let i = 0; i < 10; i++) {
    const nm = possibleNames[i % possibleNames.length];
    const st = stands[int(random(stands.length))];
    students.push({ name: nm, standing: st });
  }

  // Shuffle students to randomize names assignment
  for (let i = 0; i < students.length; i++) {
    const j = int(random(students.length));
    const t = students[i];
    students[i] = students[j];
    students[j] = t;
  }

  // Reset structures
  counts = { Fr: 0, So: 0, Jr: 0, Sr: 0 };
  startIndex = { Fr: 0, So: 0, Jr: 0, Sr: 0 };
  nextPos = { Fr: 0, So: 0, Jr: 0, Sr: 0 };
  output = new Array(students.length).fill(null);

  // Reset state
  phase = 'count';
  countIndex = 0;
  prefixIdx = 0;
  runningSum = 0;
  placeIndex = 0;
  lastPlacedOutputIndex = -1;
}

function bucketSetOrder(mode) {
  // mode: 'asc' or 'desc'
  collectOrder = mode === 'desc' ? ['Sr','Jr','So','Fr'] : ['Fr','So','Jr','Sr'];
  // For simplicity and clarity, restart the interactive when order changes
  bucketReset();
}

// Advance one step; returns true when completely done
function bucketStep() {
  if (phase === 'done') return true;

  if (phase === 'count') {
    if (countIndex < students.length) {
      const s = students[countIndex];
      counts[s.standing] += 1;
      countIndex++;
      return false;
    }
    // move to prefix computation
    phase = 'prefix';
    prefixIdx = 0;
    runningSum = 0;
    return false;
  }

  if (phase === 'prefix') {
    if (prefixIdx < collectOrder.length) {
      const key = collectOrder[prefixIdx];
      startIndex[key] = runningSum;
      runningSum += counts[key];
      prefixIdx++;
      if (prefixIdx === collectOrder.length) {
        // initialize nextPos from startIndex when done
        for (const k of ['Fr','So','Jr','Sr']) nextPos[k] = startIndex[k];
      }
      return false;
    }
    // move to placing phase
    phase = 'place';
    placeIndex = 0;
    lastPlacedOutputIndex = -1;
    return false;
  }

  if (phase === 'place') {
    if (placeIndex < students.length) {
      const s = students[placeIndex];
      const key = s.standing;
      const pos = nextPos[key];
      output[pos] = s;
      lastPlacedOutputIndex = pos;
      nextPos[key] = pos + 1;
      startIndex[key] = pos + 1;
      placeIndex++;
      if (placeIndex === students.length) {
        phase = 'done';
        students = output.slice();
        return true;
      }
      return false;
    }
    phase = 'done';
    students = output.slice();
    return true;
  }

  return false;
}

// Drawing helpers
const colorForStanding = {
  'Fr': '#a3d57e48',
  'So': '#8ecae648',
  'Jr': '#c661f448',
  'Sr': '#e76f5148'
};

function drawUI() {
  let y = 0;
  fill(0);
  textSize(16);
  textAlign(LEFT, TOP);
  text(`Bucket Sort (by class standing)`, 12, y); y += 22;
  textSize(13);
  let phaseText = '';
  if (phase === 'count') {
    phaseText = `Count: tally items in each bucket\n`;
    if(countIndex < students.length)
    phaseText += `Item at ${countIndex} increases count for ${students[countIndex].standing} (bucket number ${collectOrder.indexOf(students[countIndex].standing)})`;
    else {
      phaseText += `All items counted.`;
    }
  }
  else if (phase === 'prefix') {
    phaseText = `Calculate starting indexes.`;
    if(prefixIdx < collectOrder.length) {
      phaseText += `\nAt index ${prefixIdx}. runningSum is ${runningSum}. Updates to make:`;
      phaseText += `\n  startIndex[${prefixIdx}] = runningSum    //(will become ${runningSum})`;
      phaseText += `\n  runningSum += counts[${prefixIdx}]       //(will become ${runningSum + counts[collectOrder[prefixIdx]]})`;
    } else {
      phaseText += `\nAll starting indexes set.`;
    }
  } else if (phase === 'place') {
    phaseText = `Place: move students directly to output using starts`;
    if(placeIndex < students.length) {
      phaseText += `\nPlacing student from index ${placeIndex} (${students[placeIndex].name}, ${students[placeIndex].standing}).\n  They belong in bucket number ${collectOrder.indexOf(students[placeIndex].standing)}.`;
      phaseText += ` So index in output will be startIndex[${collectOrder.indexOf(students[placeIndex].standing)}] = ${nextPos[students[placeIndex].standing]}`;
      phaseText += `\n  Then increment startIndex[${collectOrder.indexOf(students[placeIndex].standing)}]`;
    }
  } 
  else phaseText = 'Done';
  text(phaseText, 12, y); y += 8;

  // Source row
  y += 75;
  const sourceY = y;
  const activeSrcIdx = (phase === 'count') ? countIndex : (phase === 'place' ? placeIndex : -1);
  drawLabeledRow('Source', students, 12, sourceY, activeSrcIdx);
  y += boxH + 24;

  // Counts and Starts section
  const countsY = y + 10;
  y = drawCountsAndStarts(12, countsY);
  // Draw an arrow during counting from current source to its counts box
  if (phase === 'count' && countIndex < students.length) {
    drawCountArrow(12, sourceY, countsY, countIndex, students[countIndex].standing);
  }
  if (phase === 'prefix' && prefixIdx < collectOrder.length) {
    //drawPrefixArrow(12, countsY, prefixIdx);
  }
  y += 18;

  // Output row
  const activeOutIdx = (phase === 'place') ? lastPlacedOutputIndex : -1;
  drawLabeledRow('Output', output, 12, y, activeOutIdx, true);
}

function drawLabeledRow(label, arr, x0, y, activeIndex, isOutput=false) {
  // label
  fill(0); textSize(14); text(label + ':', x0, y + boxH/2);
  const xStart = x0 + 70;
  stroke('#333');
  for (let i = 0; i < arr.length; i++) {
    const x = xStart + i * (cellW);
    const s = arr[i];
    const isActive = (activeIndex >= 0 && i === activeIndex);
    drawStudentBox(x, y, cellW, s, isActive);
    // index below
    noStroke(); fill('#444'); textSize(12); textAlign(CENTER, TOP);
    text(i, x + cellW/2, y + boxH + 2);
    textAlign(LEFT, CENTER);
  }
}

function drawCountsAndStarts(x0, y0) {
  const labels = ['Fr','So','Jr','Sr'];
  const xStart = x0 + 150;
  const rowGap = 50;

  // Counts row
  fill(0); textSize(14); text(`Counts:`, x0, y0 + boxH/2);
  const yCounts = y0;
  for (let c = 0; c < labels.length; c++) {
    const key = labels[c];
    const x = xStart + c * (cellW);
    let isActive = (phase === 'count' && countIndex < students.length && students[countIndex].standing === key)
    || (phase === 'prefix' && prefixIdx === c);
    drawMetricBox(x, yCounts, cellW, `${counts[key]}`, `${c}\n(${key})`, key, isActive);
  }

  // Starts row (by collect order)
  const yStarts = yCounts + boxH + rowGap;
  fill(0); textSize(14); text(`Starting indexes:`, x0, yStarts + boxH/2);
  // if(phase === 'prefix' && prefixIdx < collectOrder.length) {
  //   text(`runningSum ${runningSum}`, x0, yStarts + boxH/2 + 20);
  //   text(`startIndex ${startIndex[collectOrder[prefixIdx]]} = ${startIndex[collectOrder[prefixIdx]]}`, x0, yStarts + boxH/2 + 35);
  // }
  for (let c = 0; c < collectOrder.length; c++) {
    const key = collectOrder[c];
    const x = xStart + c * (cellW);
    const isActive = (phase === 'prefix' && c === prefixIdx);
    drawMetricBox(x, yStarts, cellW, `${startIndex[key]}`, `${c}\n(${key})`, key, isActive);
  }

  return yStarts + boxH + rowGap; // new y
}

function drawMetricBox(x, y, w, textValue, label, key, highlight=false) {
  stroke(highlight ? '#0077ffff' : '#666');

  const c = colorForStanding[key] || '#ddd';
   fill(c);
  rect(x, y, w, boxH);
  noStroke();
  // label
  fill('#111'); textSize(13); textAlign(CENTER, CENTER);
  text(textValue, x + cellW/2, y + boxH/2);
  textSize(12);
  textAlign(CENTER, TOP);
  text(label, x + cellW/2, y + boxH + 1);
  textAlign(LEFT, CENTER);
}

// Draw an arrow from the current source item to the corresponding counts box for its standing
function drawCountArrow(x0, srcY, countsY, srcIndex, standing) {
  const labels = ['Fr','So','Jr','Sr'];
  const xStart = x0 + 70;

  const sx = xStart + srcIndex * (cellW) + cellW / 2;
  const sy = srcY + boxH;

  const cIndex = labels.indexOf(standing);
  if (cIndex < 0) return;
  const cx = xStart + cIndex * (cellW) + 80 + cellW / 2;
  const cy = countsY - 5;

  drawArrow(sx, sy, cx, cy, '#0077ffff');
}

function drawPrefixArrow(x0, countsY, prefixIdx) {
  const xStart = x0 + 150;
  const sx = xStart + (prefixIdx) * (cellW) + cellW / 2;
  const sy = countsY + boxH;
  const cx = sx + cellW;
  const cy = countsY + boxH + 40 - 5;
  drawArrow(sx, sy, cx, cy, '#0077ffff');
}

function drawArrow(x1, y1, x2, y2, color = '#0077ffff') {
  push();
  stroke(color);
  fill(color);
  line(x1, y1, x2, y2);
  const angle = atan2(y2 - y1, x2 - x1);
  const head = 8;
  translate(x2, y2);
  rotate(angle);
  noStroke();
  triangle(0, 0, -head, 3, -head, -3);
  pop();
}

function drawStudentBox(x, y, w, student, highlight=false) {
  stroke(highlight ? '#0077ffff' : '#333');
  // fill('#fff');
  // rect(x, y, w, boxH);

  if (student) {
    const c = colorForStanding[student.standing] || '#ddd';
    // standing color swatch on the left
    // noStroke(); fill(c);
    // rect(x+1, y+1, swatchW, boxH-2);
    fill(c);
    rect(x, y, w, boxH);

    // name on first line, standing on second line
    const tx = x + cellW/2;// + swatchW + namePad;
    const nameY = y + boxH/2 - 7;
    const standY = y + boxH/2 + 7;

    textAlign(CENTER, CENTER);
    noStroke();
    fill('#111');
    textSize(13);
    text(`${student.name}`, tx, nameY);
    textSize(12); fill('#333');
    text(`${student.standing}`, tx, standY);
    textAlign(LEFT, CENTER);
  } else {
    // empty
    noStroke(); fill('#eee'); textSize(12); textAlign(CENTER, CENTER);
    text('-', x + w/2, y + boxH/2);
    textAlign(LEFT, CENTER);
  }
}

// Expose controls for HTML
window.bucketReset = bucketReset;
window.bucketStep = bucketStep;
window.bucketSetOrder = bucketSetOrder;
