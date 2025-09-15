// Two pairs, both of type T, are equal if their first and second elements are equal
template<typename T>
bool areEqual(const Pair<T>& p1, const Pair<T>& p2) {
    return (p1.first == p2.first) && (p1.second == p2.second);
}