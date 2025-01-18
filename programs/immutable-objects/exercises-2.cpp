string s = "((3 + 7) * 2)";
int count = 0;
for (char c : s) {
    if (c == '(') {
        count++;
    } else if (c == ')') {
        count--;
    }
}
cout << count << endl;