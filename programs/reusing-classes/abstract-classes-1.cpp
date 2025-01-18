#include <iostream>

// Abstract class declaration.  You'll need to define GridCanvas separately.
class GridCanvas {};

class Automaton {
  public:
    GridCanvas* grid;
    virtual void update() = 0;

  protected:
    void mainloop(int rate) {
        // Implementation for invoking update
    }

  public:
    void run(const string& title, int rate) {
        // Implementation for invoking mainloop
    }
};