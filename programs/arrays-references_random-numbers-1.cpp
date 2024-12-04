vector<int> randomArray(int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 99);
    vector<int> a(size);
    for (int i = 0; i < size; ++i) {
        a[i] = distrib(gen);
    }
    return a;
}
