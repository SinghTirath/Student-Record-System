
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student {
private:
    int id;
    string name;
    float gpa;

public:
    // Constructor
    Student(int id, const string &name, float gpa);

    // Accessor methods
    int getId() const;
    string getName() const;
    float getGPA() const;

    // Method to display student details
    void displayStudentInfo() const;
};

#endif
