struct Name {
    string first;
    string middle;
    string last;
};

enum class Status {
    INACTIVE,
    ACTIVE
};

struct Student {
    Name name;
    Status currentStatus;
    vector<double> scores;
};

int main() {
    // The entire roster
    vector<Student> studentList;
}