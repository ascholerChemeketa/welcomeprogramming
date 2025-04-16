// Start global module fragment
module;

// All includes go here
#include <cmath>

// Start module, declare its name and make available outside this module
export module library;

// Declare the functions in the module

/**
 * @brief Doubles the value of the input number
 * 
 * @param num an integer value
 * @return int 2x the input number
 */
export int doubleValue(int num) {
    int result = 2 * num;
    return result;
}