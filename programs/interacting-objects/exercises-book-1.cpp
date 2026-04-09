#include <iostream>
using namespace std;

class Book {
public:
    Book(string title, int pages) {
        m_title = title;
        m_pages = pages;
    }

    bool isLonger(const Book& other) const;

private:
    string m_title;
    int m_pages;
};