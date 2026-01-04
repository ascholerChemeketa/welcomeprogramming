


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("descendingInsertionSort") {
    vector<int> vec = {2, 7, 4, 5, 1, 3, 6, 8};
    
    {
      descendingInsertionSort(vec, 2);
      string debug1 = "After sorting 2 element: " + vectorToString(vec);
      vector<int> expected1 = {7, 2, 4, 5, 1, 3, 6, 8};
      INFO(debug1);
      INFO("Expected: ", vectorToString(expected1));
      CHECK(vec == expected1);
    }
    {
      descendingInsertionSort(vec, 4);
      string debug2 = "After sorting 4 elements: " + vectorToString(vec);
      vector<int> expected2 = {7, 5, 4, 2, 1, 3, 6, 8};
      INFO(debug2);
      INFO("Expected: ", vectorToString(expected2));
      CHECK(vec == expected2);
    }
}