// If we have not yet defined LIBRARY_H, keep going
// Otherwise, skip to the #endif
#ifndef LIBRARY_H
// Define LIBRARY_H so if we end up back in this file we skip over everything
#define LIBRARY_H

// Declare the functions we will be using
/**
 * @brief Doubles the value of the input number
 * 
 * @param num an integer value
 * @return int 2x the input number
 */
int doubleValue(int num);

#endif
