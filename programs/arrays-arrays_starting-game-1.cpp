#include "GridCanvas.h"

class Conway {
  private:
    GridCanvas* grid;

  public:
    Conway() {
        grid = new GridCanvas(5, 10, 20);
        grid->turnOn(2, 1);
        grid->turnOn(2, 2);
        grid->turnOn(2, 3);
        grid->turnOn(1, 7);
        grid->turnOn(2, 7);
        grid->turnOn(3, 7);
    }

    ~Conway() {
        delete grid;
    }
};
