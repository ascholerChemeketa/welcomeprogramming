#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int getNonEmptyCount(const vector<string>& words) {
    int count = count_if(
