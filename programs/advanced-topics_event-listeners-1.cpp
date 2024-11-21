class Sprite : public Actor, public KeyListener {
private:
  int xpos;
  int ypos;
  int dx;
  int dy;
  Image image;

public:
  Sprite(const string& path, int xpos, int ypos): xpos(xpos), ypos(ypos) {
    try {
      this->image = ImageIO::read(new File(path.c_str()));
    } catch (const IOException& exc) {
      exc.printStackTrace();
    }
  }
};