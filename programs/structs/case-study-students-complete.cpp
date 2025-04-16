#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <fstream>
using namespace std;

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

Name createName(const string& line) {
    Name name;
    stringstream ss(line);
    ss >> name.first;
    ss >> name.middle;
    ss >> name.last;
    return name;
}

Status createStatus(const string& line) {
    if (line == "Active") {
        return Status::ACTIVE;
    }
    else if (line == "Inactive") {
        return Status::INACTIVE;
    }
    else {
        throw logic_error("Invalid status value");
    }
}

vector<double> createScores(string line) {
    vector<double> scores;
    size_t nextComma = line.find(',');
    while (nextComma != string::npos) {
        string scoreStr = line.substr(0, nextComma);
        double score = stod(scoreStr);
        scores.push_back(score);
        line = line.substr(nextComma + 1);
        nextComma = line.find(',');
    }
    // Handle the last score after the last comma
    double score = stod(line);
    scores.push_back(score);
    return scores;
}

Student createStudent(const string& nameLine,
                      const string& statusLine,
                      const string& scoresLine) {
    Student student;
    student.name = createName(nameLine);
    student.currentStatus = createStatus(statusLine);
    student.scores = createScores(scoresLine);
    return student;
}

double calculateAverage(const vector<double>& scores) {
    double total = 0.0;
    for (double score : scores) {
        total += score;
    }
    return total / scores.size();
}

vector<Student> getStudentData() {
    ifstream file("Students.txt");
    if (!file.is_open()) {
        throw logic_error("Could not open file");
    }

    vector<Student> students;

    while (!file.eof()) {
        string nameLine, statusLine, scoresLine;
        getline(file, nameLine);
        getline(file, statusLine);
        getline(file, scoresLine);
        if(file.fail()) {
            break; // Exit loop if reading fails
        }
        Student student = createStudent(nameLine, statusLine, scoresLine);
        students.push_back(student);
    }

    return students;
}

int main() {
    vector<Student> studentList = getStudentData();
    // print out just active students
    for (const Student& s : studentList) {
        // print out just active students
        if (s.currentStatus == Status::ACTIVE) {
            cout << "Name: " << s.name.first << " ";
            cout << calculateAverage(s.scores) << endl;
        }
    }
}