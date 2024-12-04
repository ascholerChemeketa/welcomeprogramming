void ping() {
    cout << ".\n";
}

void baffle() {
    cout << "wug";
    ping();
}

void zippo(const string& quince, int flag) {
    if (flag < 0) {
        cout << quince << " zoop\n";
    } else {
        cout << "ik\n";
        baffle();
        cout << "boo-wa-ha-ha\n";
    }
}

void zoop() {
    baffle();
    cout << "You wugga ";
    baffle();
}

int main() {
    cout << "No, I ";
    zoop();
    cout << "I ";
    baffle();
    return 0;
}
