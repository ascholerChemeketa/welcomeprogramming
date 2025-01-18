public void step() {
    for (DrawablePolygon dp : list) {
        dp.step();
    }
    repaint();
}