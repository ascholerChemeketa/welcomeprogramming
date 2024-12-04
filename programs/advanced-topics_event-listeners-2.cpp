void draw(Graphics g) {
    g.drawImage(image, xpos, ypos, nullptr);
}

void step() {
    xpos += dx;
    ypos += dy;
}