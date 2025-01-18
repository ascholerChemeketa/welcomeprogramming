Rectangle intersection(const Rectangle& a, const Rectangle& b) {
    return Rectangle(min(a.x, b.x), min(a.y, b.y),
                     max(a.x + a.width, b.x + b.width) - min(a.x, b.x),
                     max(a.y + a.height, b.y + b.height) - min(a.y, b.y));
}