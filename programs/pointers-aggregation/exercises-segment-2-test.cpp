
    
    string toString() {
      return m_p1->toString() + " to " + m_p2->toString();
    }
};

//doctest.h already included

TEST_CASE("Test Segment Shift") {
    Point A(0, 0);
    Point B(4, 4);
    Segment s1(&A, &B);

    // shift the segment and test the new description
    s1.shift(1, 1);
    string endDesc = s1.toString();
    CHECK(endDesc == "(1, 1) to (5, 5)");

    // shift the segment and test the new description
    s1.shift(-2, 1);
    endDesc = s1.toString();
    CHECK(endDesc == "(-1, 2) to (3, 6)");
}