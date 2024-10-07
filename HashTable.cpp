
#include "HashTable.h"
#include <iostream>

int HashTable::hashFunction(int id) const {
    return id % table_size;
}

void HashTable::insertStudent(int id, const string &name, float gpa) {
    int index = hashFunction(id);
    table[index].push_back(new Student(id, name, gpa));
    cout << "Student added successfully." << endl;
}

void HashTable::searchStudent(int id) const {
    int index = hashFunction(id);
    for (const auto &student : table[index]) {
        if (student->getId() == id) {
            student->displayStudentInfo();
            return;
        }
    }
    cout << "Student not found." << endl;
}

void HashTable::deleteStudent(int id) {
    int index = hashFunction(id);
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            table[index].erase(it);
            cout << "Student deleted successfully." << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

void HashTable::displayAllStudents() const {
    for (int i = 0; i < table_size; ++i) {
        if (!table[i].empty()) {
            for (const auto &student : table[i]) {
                student->displayStudentInfo();
            }
        }
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < table_size; ++i) {
        for (auto student : table[i]) {
            delete student;
        }
    }
}
