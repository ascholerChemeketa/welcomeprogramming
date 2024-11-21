class BlinkingPolygon : public RegularPolygon {
protected:
  bool visible;
  int count;

public:
  BlinkingPolygon(int nsides, int radius, Color c):
      RegularPolygon(nsides, radius, c) {
    visible = true;
    count = 0;
  }
  void draw(Graphics g) override {
    if (visible) {
      RegularPolygon::draw(g);
    }
  }
  void step() override {
    count++;
    if (count == 10) {
      visible = !visible;
      count = 0;
    }
  }
};