    );  // end of count_if
    return count;
} // end of getNonEmptyCount

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test getNonEmptyCount function") {
    vector<string> words = {
        "Apple",
        "Banana",
        "",
        "Grapes"
    };

    int count = getNonEmptyCount(words);
    REQUIRE(count == 3);

    words.push_back("Orange");
    count = getNonEmptyCount(words);
    REQUIRE(count == 4);
    
    words.push_back("");
    count = getNonEmptyCount(words);
    REQUIRE(count == 4);
}
