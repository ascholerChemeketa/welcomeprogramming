RegularPolygon(int nsides, int radius, string color) {
    // initialize DrawablePolygon attributes
    this->npoints = nsides;
    this->xpoints = new int[nsides];
    this->ypoints = new int[nsides];
    this->color = color;

    // the amount to rotate for each vertex (in radians)
    double theta = 2.0 * M_PI / nsides;

    // compute x and y coordinates, centered at the origin
    for (int i = 0; i < nsides; i++) {
        double x = radius * cos(i * theta);
        double y = radius * sin(i * theta);
        xpoints[i] = static_cast<int>(round(x));
        ypoints[i] = static_cast<int>(round(y));
    }
}