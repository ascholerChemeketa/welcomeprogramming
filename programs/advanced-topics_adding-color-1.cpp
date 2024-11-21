#include <Graphics.h>

class DrawablePolygon : public Polygon {
protected:
  Color color;

public:
  DrawablePolygon(): Polygon() {
    color = Color::GRAY;
  }

  void draw(Graphics& g) {
    g.setColor(color);
    g.fillPolygon(*this);
  }
};