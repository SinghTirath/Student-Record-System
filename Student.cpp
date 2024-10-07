
#include "Student.h"
#include <iostream>

Student::Student(int id, const string &name, float gpa) : id(id), name(name), gpa(gpa) {}

int Student::getId() const { return id; }
string Student::getName() const { return name; }
float Student::getGPA() const { return gpa; }

void Student::displayStudentInfo() const {
    cout << "ID: " << id << ", Name: " << name << ", GPA: " << gpa << endl;
}
