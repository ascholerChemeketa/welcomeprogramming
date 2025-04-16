vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8};
// remove all the elements from index 0 up to (but not including) index 3
values.erase(values.begin(), values.begin() + 3);
// now values is {4, 5, 6, 7, 8}
// remove all the elements from index 2 to the end
values.erase(values.begin() + 2, values.end());
// now values is {4, 5}