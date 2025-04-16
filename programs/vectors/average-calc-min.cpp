double minValue(const vector<double>& values) {
    if (values.size() == 0) {
        throw logic_error("No minValue in an empty vector");
    }
    // FIXME - assume the first element is the minimum
    for (double value : values) {
        // FIXME - check if the current value is smaller than the minimum
        //         if so, update the minumum
    }
    return minimum;
}