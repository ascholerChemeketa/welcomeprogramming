vector<int> counts(26, 0);
string lower = s;
transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
