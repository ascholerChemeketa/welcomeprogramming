vector<int> values = {1, 2, 3, 4, 5};
values.erase(values.begin() + 2); // remove the element at index 2
                                  // now values is {1, 2, 4, 5}
values.erase(values.begin());     // remove the element at index 0
                                  // now values is {2, 4, 5}