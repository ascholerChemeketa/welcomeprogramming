// If we have not yet defined OTHERLIBRARY_H, keep going
// Otherwise, skip to the #endif
#ifndef OTHERLIBRARY_H
// Define OTHERLIBRARY_H so if we end up back in this file we skip over everything
#define OTHERLIBRARY_H

// Include necessary headers
#include <string>

// using namespace std;  <-- Intentionally NOT used here
// We do NOT want to use "using namespace std;" in header files
// because it can lead to name conflicts in larger projects.

// Function just for demo purposes...
// We must use std::string because we are not using "using namespace std;"
std::string firstHalf(const std::string& text);

#endif
