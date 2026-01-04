template<typename T>
int linearSearchRecursive(const vector<T>& vec, T key, int currentIndex = 0) {
    if (currentIndex >= vec.size()) {
        // Reached the end without finding the key
        return -1; 
    } else if (vec.at(currentIndex) == key) {
        // Found the key at the current index
        return currentIndex;
    } else {
        // Not found yet, check the next index, return the result
        return linearSearchRecursive(vec, key, currentIndex + 1);
    }
}