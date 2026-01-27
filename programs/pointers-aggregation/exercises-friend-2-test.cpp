

};  // end of Friend class

//doctest.h already included

TEST_CASE("bestieCheck no friend") {
    Friend f1("Bob", nullptr);
    bool isBesties = f1.bestieCheck();
    CHECK(isBesties == false);
}

TEST_CASE("bestieCheck agree") {
    Friend f1("Duncan", nullptr);
    Friend f2("Shannon", &f1);
    f1.setFriend(&f2);

    bool duncanIsBestie = f1.bestieCheck();
    CHECK(duncanIsBestie == true);

    bool shannonIsBestie = f2.bestieCheck();
    CHECK(shannonIsBestie == true);
}

TEST_CASE("bestieCheck disagree") {
    Friend f1("Duncan", nullptr);
    Friend f2("Shannon", &f1);
    Friend f3("Doug", &f2);
    f1.setFriend(&f3);

    // No, Doug is not a bestie of Duncan
    bool duncanIsBestie = f1.bestieCheck();
    CHECK(duncanIsBestie == false);

    // No, Duncan is not a bestie of Shannon
    bool shannonIsBestie = f2.bestieCheck();
    CHECK(shannonIsBestie == false);
}

TEST_CASE("bestieCheck self") {
    Friend f1("Bob", nullptr);
    f1.setFriend(&f1); // Bob is his own bestie
    bool isBesties = f1.bestieCheck();
    CHECK(isBesties == true);
}