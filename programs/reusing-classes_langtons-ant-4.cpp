#include <iostream>

// GridCanvas and Cell need to be defined elsewhere.  They should have
// appropriate methods.
class GridCanvas {};

class Cell {};

class Langton {
private:
  GridCanvas* grid;
  int xpos;
  int ypos;
  int head; // 0=North, 1=East, 2=South, 3=West
public:
  Langton(int rows, int cols):
      grid(new GridCanvas(rows, cols, 10)), xpos(rows / 2), ypos(cols / 2),
      head(0) {
  }

  ~Langton() {
    delete grid;
  }

  void update() {
    flipCell();
    moveAnt();
  }

private:
  void flipCell() {
    Cell* cell = grid->getCell(xpos, ypos);
    if (cell->isOff()) {
      head = (head + 1) % 4; // turn right
      cell->turnOn();
    } else {
      head = (head + 3) % 4; // turn left
      cell->turnOff();
    }
  }

  void moveAnt() {
    if (head == 0) {
      ypos -= 1;
    } else if (head == 1) {
      xpos += 1;
    } else if (head == 2) {
      ypos += 1;
    } else {
      xpos -= 1;
    }
  }
};