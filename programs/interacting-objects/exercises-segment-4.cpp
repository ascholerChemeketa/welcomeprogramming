#include <iostream>
#include <cmath>

import Point;

using namespace std;

class Segment {
public:
    Segment(const Point& start, const Point& end) {
        m_start = start;
        m_end = end;
    }
