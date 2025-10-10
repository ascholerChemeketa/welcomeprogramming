    // Calculate the semi-perimeter s
    double s = (a + b + c) / 2.0;
    // Calculate the area using Heron's formula
    double area = sqrt((s - a) * (s - b) * (s - c));
    return area;
}