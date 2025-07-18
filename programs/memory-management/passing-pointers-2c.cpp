
int main() {
    // Call a function that allocates memory and returns a pointer
    int* returnedPointer = makeMemory();

    cout << "returnedMemory: " << returnedPointer << endl;
    cout << "returnedMemory points to: " << *returnedPointer << endl;

    // Pass the memory address to another function
    // and assume that function owns the memory now
    takeoverMemory(returnedPointer);
}