#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Subject {
public:
    string name;
    double marks;

    Subject(string name, double marks) : name(name), marks(marks) {}
};

class GradeCard {
private:
    string dept;
    string name;
    int roll;
    int semester;
    vector<Subject> subjects;
    double cgpa;

    void calculateCGPA() {
        double totalMarks = 0.0;
        for (const auto& subject : subjects) {
            totalMarks += subject.marks;
        }
        cgpa = totalMarks / subjects.size();
    }

public:
    GradeCard(string dept, string student, int roll, int sem, vector<Subject> subs)
        : dept(dept), name(student), roll(roll), semester(sem), subjects(subs) {
        calculateCGPA();
    }

    double getCGPA() const {
        return cgpa;
    }

    string getname() const {
        return name;
    }

    int getroll() const {
        return roll;
    }

    void disp() const {
        cout << "dept: " << dept << endl;
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << roll << endl;
        cout << "Semester: " << semester << endl;
        cout << "Subjects and Marks:" << endl;
        for (const auto& subject : subjects) {
            cout << subject.name << ": " << subject.marks << endl;
        }
        cout << "CGPA: " << cgpa << endl;
    }
};

int main() {
    vector<GradeCard> gradeCards;

    for (int i = 1; i <= 6; ++i) {
        vector<Subject> subjects = {
            {"Math", rand() % 100},
            {"Physics", rand() % 100},
            {"Chemistry", rand() % 100},
            {"Computer Science", rand() % 100},
            {"English", rand() % 100}
        };

        gradeCards.emplace_back("Computer Science", "Student" + to_string(i), 1000 + i, 3, subjects);
    }

    auto maxCGPA = max_element(gradeCards.begin(), gradeCards.end(), [](const GradeCard& a, const GradeCard& b) {
        return a.getCGPA() < b.getCGPA();
    });

    cout << "Student with the highest CGPA:" << endl;
    cout << "Name: " << maxCGPA->getname() << endl;
    cout << "Roll Number: " << maxCGPA->getroll() << endl;
    cout << "CGPA: " << maxCGPA->getCGPA() << endl;

    return 0;
}
