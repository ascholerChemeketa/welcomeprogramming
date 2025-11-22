vector<int> values = {1, 2, 3, 4, 5};

values.erase(values.end() - 1);   // remove the last element
                                  // now values is {1, 2, 3, 4}

// Starting from {1, 2, 3, 4}
values.erase(values.end() - 2);   // remove the next to last element
                                  // now values is {1, 2, 4}