class Drawing : public Canvas {
private:
  vector<DrawablePolygon> list;

public:
  Drawing(int width, int height): list() {
    setSize(width, height);
    setBackground(Color::WHITE);
  }

  void add(DrawablePolygon* dp) {
    list.push_back(*dp);
  }
};