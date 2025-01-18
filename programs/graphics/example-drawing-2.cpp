void mickey(Graphics* g, const Rectangle& bb) {
    g->fillOval(bb.x, bb.y, bb.width, bb.height);

    int hx = bb.width / 2;
    int hy = bb.height / 2;
    Rectangle half = {bb.x, bb.y, hx, hy};

    half.x -= hx / 2;
    half.y -= hy / 2;
    g->fillOval(half.x, half.y, half.width, half.height);

    half.x += hx * 2;
    g->fillOval(half.x, half.y, half.width, half.height);
}