double sum(const vector<double>& values) {
    double total = 0.0;
    for (size_t i = 0; i < values.size(); ++i) {
        int value = values.at(i);
        total += value;
    }
    return total;
}