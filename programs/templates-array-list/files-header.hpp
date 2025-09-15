#ifndef MYTEMPLATEDLIBRARY_H
#define MYTEMPLATEDLIBRARY_H

// The full definition of the templated function must be in the header file
template <typename T>
T myMax(T a, T b) {
    return (a > b) ? a : b;
}

#endif