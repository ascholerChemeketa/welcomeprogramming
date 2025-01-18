public void mickey(Graphics g, Rectangle bb) {
    boxOval(g, bb);

    int hx = bb.width / 2;
    int hy = bb.height / 2;
    Rectangle half = new Rectangle(bb.x, bb.y, hx, hy);

    half.translate(-hx / 2, -hy / 2);
    boxOval(g, half);

    half.translate(hx * 2, 0);
    boxOval(g, half);
}