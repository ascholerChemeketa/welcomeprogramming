#include <iostream>
// GridCanvas needs to be defined elsewhere.  It should have methods to set and
// get cell values.
class GridCanvas {};
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
    // Implementation to flip the cell at xpos, ypos
  }
  void moveAnt() {
    // Implementation to move the ant based on head and cell value
  }
};