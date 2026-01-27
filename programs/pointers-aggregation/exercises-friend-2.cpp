#include <iostream>
#include <string>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

class Friend {
private:
    Friend* m_bestFriend;
    string m_name;

public:
    Friend(string name, Friend* bestFriend = nullptr) {
        m_name = name;
        m_bestFriend = bestFriend;
    }

    Friend* getFriend() {
        return m_bestFriend;
    }

    void setFriend(Friend* bestFriend) {
        m_bestFriend = bestFriend;
    }

    string getName() {
        return m_name;
    }
