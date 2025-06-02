#include <iostream>
#include <string>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

import Point;

using namespace std;

class Friend {
private:
    Friend* m_bestFriend = nullptr;
    string m_name;

public:
    Friend(string name) {
        m_name = name;
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
};

TEST_CASE("Friend setup") {