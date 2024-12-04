#include <iostream>

void zippo(const string& quince, int flag) {
    if (flag < 0) {
        cout << quince << " zoop\n";
    } else {
        cout << "ik\n";
        baffle(quince);
        cout << "boo-wa-ha-ha\n";
    }
}

void baffle(const string& blimp) {
    cout << blimp << endl;
    zippo("ping", -5);
}

void ping(const string& strangStrung) {
    cout << "any " << strangStrung << "more \n";
}

void clink(int fork) {
    cout << "It's ";
    for (int i = 0; i < fork; ++i) {
        cout << "breakfast ";
    }
}

int main() {
    // Example to call zippo
    zippo("test", 5);
    return 0;
}
