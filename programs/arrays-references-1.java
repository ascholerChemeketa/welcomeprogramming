// outer loop: for each lowercase letter
for (char c = 'a'; c &lt;= 'z'; c++) {
    // inner loop: count how many times the letter appears
    for (int i = 0; i &lt; str.length(); i++) {
        ...
    // if the count is not 0 or 2, return false