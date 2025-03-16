/**
 * @file SimpleRandom.h
 * 
 * A very simple header-only file to provide easy random number generation.
 * Placing definitions in a header file is not good practice, but this file
 * is intended to be a simple workaround for adding random number generation
 * to programs run by the server in this book.
 * 
 */

#ifndef SIMPLERANDOM_H
#define SIMPLERANDOM_H

#include <random>

std::mt19937 generator{std::random_device{}()};

/**
 * @brief Seeds the random number generator. Calling this function with an integer
 *        will seed the generator with that value.
 * 
 * @param x Seed value to use.
 * 
 * @note If you don't call this function, the generator will
 *       be seeded with a random value.
 */
void seedRNG(unsigned int x) {
  generator.seed(x);
}

/**
 * @brief Generates a random integer in the range [min, max].
 * 
 * @param min The minimum value of the range.
 * @param max The maximum value of the range.
 * @return A random integer in the range [min, max].
 */
int randRange(int min, int max) {
  std::uniform_int_distribution<int> distribution(min, max);
  return distribution(generator);
}

/**
 * @brief Generates a random double in the range [0.0, 1.0).
 * 
 * @return A random double in the range [0.0, 1.0). i.e. 0-0.9999...
 */
double randDouble() {
  std::uniform_real_distribution<double> distribution(0.0, 1.0);
  return distribution(generator);
}

#endif // SIMPLERANDOM_H