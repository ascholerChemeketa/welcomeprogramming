double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dsquared = dx * dx + dy * dy;
    cout << "dsquared is " << dsquared << endl;
    return sqrt(dsquared);
}