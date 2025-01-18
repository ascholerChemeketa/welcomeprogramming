double halfWidth = 0.5 * rect.getWidth();
double halfHeight = 0.5 * rect.getHeight();
int dx = static_cast<int>(round(halfWidth));
int dy = static_cast<int>(round(halfHeight));
rect.translate(dx, dy);