// outer loop: for each lowercase letter
for (char c = 'a'; c <= 'z'; c++) {
    // inner loop: count how many times the letter appears
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == c) {
            count++;
        }
    }
    // if the count is not 0 or 2, return false
    if (count != 0 && count != 2) {
        return false;
    }
}
return true;