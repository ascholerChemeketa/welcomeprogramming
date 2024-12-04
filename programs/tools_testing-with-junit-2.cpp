#include <cassert>
#include <iostream>

// The Series class needs to be defined elsewhere.  This is a placeholder.
class Series {
  public:
    static int fibonacci(int n) {
        // Implementation of fibonacci function
        return 0; // Placeholder return
    }
};

int main() {
    assert(Series::fibonacci(1) == 1);
    assert(Series::fibonacci(2) == 1);
    assert(Series::fibonacci(3) == 2);
    cout << "All test cases passed!\n";
    return 0;
}