#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    list<string> jobs;

    // Add jobs at the back (FIFO input)
    jobs.push_back("jobA");
    jobs.push_back("jobB");
    jobs.push_back("jobC");

    // Add an urgent job at the front
    jobs.push_front("urgent");

    cout << "Front: " << jobs.front() << "\n";
    cout << "Back: " << jobs.back() << "\n";

    // Process jobs FIFO: pop from the front
    while (!jobs.empty()) {
        cout << "Processing: " << jobs.front() << "\n";
        jobs.pop_front();
    }

    // Demonstrate back operations
    jobs.push_back("cleanup1");
    jobs.push_back("cleanup2");
    cout << "Removing from back: " << jobs.back() << "\n";
    jobs.pop_back();
    cout << "Remaining size: " << jobs.size() << "\n";
}
