#include <iostream>
#include <cmath>

#include "Point.h"

using namespace std;

class Segment {
public:
    Segment(const Point& start, const Point& end) {
        m_start = start;
        m_end = end;
    }
