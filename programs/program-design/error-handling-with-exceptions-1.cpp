bool stringToBool(const string& s) {
    if (s == "true") {
        return true;
    } else if (s == "false") {
        return false;
    }
    string errorMessage = "Invalid string for boolean conversion: " + s;
    throw logic_error(errorMessage);
    return false; // We will never reach this line
}