
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Student.h"
#include <vector>

using namespace std;

class HashTable {
private:
    static const int table_size = 100;
    vector<Student*> table[table_size];

    int hashFunction(int id) const;

public:
    void insertStudent(int id, const string &name, float gpa);
    void searchStudent(int id) const;
    void deleteStudent(int id);
    void displayAllStudents() const;

    // Destructor to clean up dynamically allocated memory
    ~HashTable();
};

#endif
