int toInches(int feet, int yards = 0, int miles = 0) {
    int totalFeet = miles * 5280 + yards * 3 + feet;
    int totalInches = totalFeet * 12;
    return totalInches;
}