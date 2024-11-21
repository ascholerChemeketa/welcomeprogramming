public class Drawing extends Canvas {
    private ArrayListLESSDrawablePolygonMORE list;

    public Drawing(int width, int height) {
        setSize(width, height);
        setBackground(Color.WHITE);
        list = new ArrayListLESSDrawablePolygonMORE();
    }