#include <iostream>
#include <cmath>
using namespace std;

// Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


/**
 * @brief Calculates the area of a triangle using Heron's formula.
 * @param a Length of the first side of the triangle.
 * @param b Length of the second side of the triangle.
 * @param c Length of the third side of the triangle.
 * @return The area of the triangle.
 */
double heronsFormula(double a, double b, double c) {