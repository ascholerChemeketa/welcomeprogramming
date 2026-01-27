
    
    string toString() {
      return m_p1->toString() + " to " + m_p2->toString();
    }
};


//doctest.h already included

TEST_CASE("Test Segment Aggregation") {
    Point A(0, 0);
    Point B(4, 4);

    Segment s1(&A, &B);
    string startDesc = s1.toString();
    CHECK(startDesc == "(0, 0) to (4, 4)");

    // Now move point A and check the segment description again
    A.shift(1, 1);
    string endDesc = s1.toString();
    CHECK(endDesc == "(1, 1) to (4, 4)");
}