#include <iostream>
import ArrayList;
using namespace std;

int main() {
    ArrayList<int> intList;
    intList.insertEnd(10);
    intList.insertEnd(20);
    intList.insertEnd(30);

    cout << "ArrayList contents: " << endl;
    for(int i = 0; i < intList.size(); ++i) {
        cout << intList.get(i) << " ";
    }
    cout << endl;
}