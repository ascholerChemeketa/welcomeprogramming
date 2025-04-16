bool stringToBool(const string& s, bool& error) {
    if (s == "true") {
        return true;
    } else if (s == "false") {
        return false;
    }
    error = true; // Set error to true if the string is not "true" or "false"
    return false; // What do we do??????
}