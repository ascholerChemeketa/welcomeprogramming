void printArray(const vector<int>& a) {
    cout << "{";
    if (!a.empty()) {
        cout << a[0];
        for (size_t i = 1; i < a.size(); ++i) {
            cout << ", " << a[i];
        }
    }
    cout << "}" << endl;
}
