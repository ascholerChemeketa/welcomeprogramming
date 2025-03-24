#include <iostream>
#include <string>
using namespace std;

int main() {
    string myString = "She sells sea shells";
    cout << myString.find('e') << endl;
    cout << myString.find("ell") << endl;
    size_t seIndex = myString.find("se");
    cout << seIndex << endl;
    size_t seIndex2 = myString.find("se", seIndex + 1);
    cout << seIndex2 << endl;
}