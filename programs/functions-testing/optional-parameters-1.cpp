int toInches(int feet) {
    int totalInches = feet * 12;
    return totalInches;
}

int toInches(int yards, int feet) {
    int totalFeet = yards * 3 + feet;
    int totalInches = totalFeet * 12;
    return totalInches;
}

int toInches(int miles, int yards, int feet) {
    int totalFeet = miles * 5280 + yards * 3 + feet;
    int totalInches = totalFeet * 12;
    return totalInches;
}