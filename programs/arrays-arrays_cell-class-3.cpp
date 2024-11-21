static const string COLORS[] = {"WHITE", "BLACK"};

void draw(Graphics& g) {
  g.setColor(COLORS[state]);
  g.fillRect(x + 1, y + 1, size - 1, size - 1);
  g.setColor("LIGHT_GRAY");
  g.drawRect(x, y, size, size);
}