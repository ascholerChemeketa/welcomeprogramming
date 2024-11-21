public RegularPolygon(int nsides, int radius, Color color) {

    // validate the arguments
    if (nsides &lt; 3) {
        throw new IllegalArgumentException("invalid nsides");
    }
    if (radius &lt;= 0) {
        throw new IllegalArgumentException("invalid radius");
    }
    if (color == null) {
        throw new NullPointerException("invalid color");
    }

    // the rest of the method is omitted