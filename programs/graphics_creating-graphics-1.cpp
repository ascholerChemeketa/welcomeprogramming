#include <iostream>
#include <vector>

// Assuming the existence of a graphics library
// This is a simplified example, and you will need to use your graphics
// library's functions
namespace Graphics {
void drawLine(int x1, int y1, int x2, int y2) {
  // Implementation of drawLine using your graphics library
  cout << "Drawing line from (" << x1 << ", " << y1 << ") to (" << x2 << ", "
       << y2 << ")\n";
}

void drawRect(int x, int y, int width, int height) {
  // Implementation of drawRect using your graphics library
  cout << "Drawing rectangle at (" << x << ", " << y << ") with width " << width
       << " and height " << height << "\n";
}

void drawOval(int x, int y, int width, int height) {
  // Implementation of drawOval using your graphics library
  cout << "Drawing oval at (" << x << ", " << y << ") with width " << width
       << " and height " << height << "\n";
}
} // namespace Graphics

class Drawing {
public:
  void paint(int width, int height) {
    Graphics::drawLine(10, 10, 50, 50);
    Graphics::drawRect(100, 100, 20, 30);
    Graphics::drawOval(200, 200, 40, 60);
    // Implementation of further drawing operations
  }
};

int main() {
  Drawing drawing;
  drawing.paint(300, 400); // Example values
  return 0;
}