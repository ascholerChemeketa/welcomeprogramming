int max = numeric_limits<int>::min();
for (const string& arg : args) {
    int value = stoi(arg);
    if (value > max) {
        max = value;
    }
}
cout << "The max is " << max << endl;