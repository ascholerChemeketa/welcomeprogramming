
double minValue(const vector<double>& values) {
    // assume the first element is the minimum
    int minimum = values.at(0);
    // loop through the rest of the vector to see if any elements are smaller
    for (size_t i = 1; i < values.size(); ++i) {
        int value = values.at(i);
        if (value < minimum) {
            minimum = value; // found a new minimum
        }
    }
    return minimum;
}