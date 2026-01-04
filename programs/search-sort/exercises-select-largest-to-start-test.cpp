

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("selectLargestToStart") {
    vector<int> vec = {4, 2, 7, 5, 1, 3, 6, 8};
    
    {
      selectLargestToStart(vec, 1);
      string debug1 = "After selecting 1 largest: " + vectorToString(vec);
      vector<int> expected1 = {8, 2, 7, 5, 1, 3, 6, 4};
      INFO(debug1);
      INFO("Expected: ", vectorToString(expected1));
      CHECK(vec == expected1);
    }
    {
      selectLargestToStart(vec, 3);
      string debug2 = "After selecting 3 largest: " + vectorToString(vec);
      vector<int> expected2 = {8, 7, 6, 5, 1, 3, 2, 4};
      INFO(debug2);
      INFO("Expected: ", vectorToString(expected2));
      CHECK(vec == expected2);
    }
}