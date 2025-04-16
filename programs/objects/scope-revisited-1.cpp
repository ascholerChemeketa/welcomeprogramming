void translate(int dx, int dy) {
    int oldx = this->x;
    int newx = oldx + dx;
    if (dx < 0) {
        // Handle negative dx
    } else {
        // Handle non-negative dx
    }
    int oldy = this->y;
    int newy = oldy + dy;
    if (dy < 0) {
        // Handle negative dy
    } else {
        // Handle non-negative dy
    }
    this->x = newx;
    this->y = newy;
}