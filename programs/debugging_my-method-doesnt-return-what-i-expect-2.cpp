Rectangle intersection(const Rectangle& a, const Rectangle& b) {
  int x1 = min(a.x, b.x);
  int y1 = min(a.y, b.y);
  int x2 = max(a.x + a.width, b.x + b.width);
  int y2 = max(a.y + a.height, b.y + b.height);
  return Rectangle(x1, y1, x2 - x1, y2 - y1);
}