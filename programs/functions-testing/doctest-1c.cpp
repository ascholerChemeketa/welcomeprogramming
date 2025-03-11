

// The tests
TEST_CASE("heronsFormula") {
  CHECK(heronsFormula(3, 4, 5) == doctest::Approx(6));
  CHECK(heronsFormula(2.5, 4.1, 6.25) == doctest::Approx(3.20322));
  CHECK(heronsFormula(0, 3, 3) == doctest::Approx(0));
}