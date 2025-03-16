// The tests
TEST_CASE("countPrimes") {
    CHECK(countPrimes(2) == 1);
    CHECK(countPrimes(4) == 2);
    CHECK(countPrimes(10) == 4);
    CHECK(countPrimes(11) == 4);
    CHECK(countPrimes(100) == 25);
}
