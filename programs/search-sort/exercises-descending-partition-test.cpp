


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("descendingPartition") {
    {
      vector<int> test1 = {4, 7, 3, 9, 1, 6, 2, 8, 5};
      int pivotLoc = descendingPartition(test1, 0, 8);
      CHECK(pivotLoc == 5);
      for(int i = 0; i < pivotLoc; ++i) {
          CHECK(test1.at(i) >= test1.at(pivotLoc));
      }
      for(int i = pivotLoc + 1; i <= 8; ++i) {
          CHECK(test1.at(i) <= test1.at(pivotLoc));
      }
    }
    {
      vector<int> test2 = {8, 6, 7, 5, 3, 9, 2, 1, 4};
      int pivotLoc = descendingPartition(test2, 0, 8);
      CHECK(pivotLoc == 1);
      for(int i = 0; i < pivotLoc; ++i) {
          CHECK(test2.at(i) >= test2.at(pivotLoc));
      }
      for(int i = pivotLoc + 1; i <= 8; ++i) {
          CHECK(test2.at(i) <= test2.at(pivotLoc));
      }
    }
}

TEST_CASE("descendingPartitionPartial") {
    vector<int> test = {0, 0, 4, 7, 3, 9, 1, 6, 2, 8, 5, 0, 0};
    int pivotLoc = descendingPartition(test, 2, 10);
    CHECK(pivotLoc == 7);
    for(int i = 2; i < pivotLoc; ++i) {
        CHECK(test.at(i) >= test.at(pivotLoc));
    }
    for(int i = pivotLoc + 1; i <= 10; ++i) {
        CHECK(test.at(i) <= test.at(pivotLoc));
    }
}