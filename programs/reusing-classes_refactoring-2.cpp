#include <chrono>
#include <iostream>
#include <thread>

// You'll need to include appropriate headers for your GUI framework (e.g.,
// GLFW, SDL, Qt). This example uses placeholders to simulate the GUI elements
// and the delay.
class GridCanvas {
public:
  GridCanvas(int rows, int cols, int cellSize) {
  }

  void repaint() {
  }
};

class Automaton {
private:
  GridCanvas* grid;

public:
  Automaton(GridCanvas* grid): grid(grid) {
  }

  ~Automaton() {
    delete grid;
  }

  void run(const string& title, int rate) {
    // JFrame frame(title); // Placeholder for JFrame creation
    // frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Placeholder
    // frame.setResizable(false); // Placeholder
    // frame.add(this->grid); // Placeholder for adding grid to frame
    // frame.pack(); // Placeholder
    // frame.setVisible(true); // Placeholder
    mainloop(rate);
  }

protected:
  virtual void update() = 0;

  void mainloop(int rate) {
    while (true) {
      update();
      grid->repaint();
      this_thread::sleep_for(chrono::milliseconds(1000 / rate));
    }
  }
};