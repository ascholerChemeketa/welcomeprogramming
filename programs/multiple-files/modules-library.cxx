// Start global module fragment
module;

// All includes go here
#include <cmath>

// Start module, declare its name and make available outside this module
export module library;

// Using namespace is safer in a module as it will be scoped to this module only
// The place to do so is after the module declaration
using namespace std;

// Declare the functions in the module. Only the functions marked with `export`
// will be available outside this module.

/**
 * @brief Gets the number 2. A silly function that demonstrates a function
 * that is NOT exported
 * 
 * @return 2
 */
int getMultiplier() {
    return 2;
}

/**
 * @brief Doubles the value of the input number
 * This function is exported for use outside this module.
 * 
 * @param num an integer value
 * @return int 2x the input number
 */
export int doubleValue(int num) {
    int result = getMultiplier() * num;
    return result;
}