double distance(double x1, double y1, double x2, double y2) {
    cout << "distance(" << x1 << ", " << y1 << ", " << x2 << ", " << y2 << ")" << endl;
    double dx = x2 - x1;
    double dy = y2 - y1;
    cout << "dx is " << dx << endl;
    cout << "dy is " << dy << endl;
    double dsquared = dx * dx + dy * dy;
    cout << "dsquared is " << dsquared << endl;
    return 0;  // Fixme!!!
}