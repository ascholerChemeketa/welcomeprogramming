class Cell {
private:
  const int x;
  const int y;
  const int size;
  int state;

public:
  Cell(int x, int y, int size, int state):
      x(x), y(y), size(size), state(state) {
  }
};