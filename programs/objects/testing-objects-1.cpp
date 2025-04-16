TEST_CASE("Point Constructor - 2 args") {
    Point p1(3.0, 4.2);
    CHECK(p1.getX() == doctest::Approx(3.0));
    CHECK(p1.getY() == doctest::Approx(4.2));
}

TEST_CASE("Point Constructor - default") {
    Point p1;
    CHECK(p1.getX() == doctest::Approx(0.0));
    CHECK(p1.getY() == doctest::Approx(0.0)); 
}

TEST_CASE("Point shift") {
    Point p1;
    p1.shift(3.0, 4.2);
    CHECK(p1.getX() == doctest::Approx(3.0));
    CHECK(p1.getY() == doctest::Approx(4.2));
    // Test a negative shift
    p1.shift(-1.0, -2.0);
    CHECK(p1.getX() == doctest::Approx(2.0));
    CHECK(p1.getY() == doctest::Approx(2.2));
}