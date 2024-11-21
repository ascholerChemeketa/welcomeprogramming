public void add(DrawablePolygon dp) {
        list.add(dp);
    }

    public void paint(Graphics g) {
        for (DrawablePolygon dp : list) {
            dp.draw(g);
        }
    }
}