#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Item {
    string name;
    double price;
};

void sortItems(vector<Item>& items) {