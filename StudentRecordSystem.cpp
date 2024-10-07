
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
    int id;
    string name;
    float gpa;

public:
    // Constructor
    Student(int id, const string &name, float gpa) : id(id), name(name), gpa(gpa) {}

    // Accessor methods
    int getId() const { return id; }
    string getName() const { return name; }
    float getGPA() const { return gpa; }

    // Method to display student details
    void displayStudentInfo() const {
        cout << "ID: " << id << ", Name: " << name << ", GPA: " << gpa << endl;
    }
};

class HashTable {
private:
    static const int table_size = 100; // Size of the hash table
    vector<Student*> table[table_size]; // Array of vectors to handle collisions via chaining

    // Private hash function
    int hashFunction(int id) const {
        return id % table_size;
    }

public:
    // Insert a student into the hash table
    void insertStudent(int id, const string &name, float gpa) {
        int index = hashFunction(id);
        table[index].push_back(new Student(id, name, gpa));
        cout << "Student added successfully." << endl;
    }

    // Search for a student by ID
    void searchStudent(int id) const {
        int index = hashFunction(id);
        for (const auto &student : table[index]) {
            if (student->getId() == id) {
                student->displayStudentInfo();
                return;
            }
        }
        cout << "Student not found." << endl;
    }

    // Delete a student by ID
    void deleteStudent(int id) {
        int index = hashFunction(id);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if ((*it)->getId() == id) {
                delete *it; // Free the memory allocated for the student
                table[index].erase(it); // Remove the student from the vector
                cout << "Student deleted successfully." << endl;
                return;
            }
        }
        cout << "Student not found." << endl;
    }

    // Display all students in the hash table
    void displayAllStudents() const {
        for (int i = 0; i < table_size; ++i) {
            if (!table[i].empty()) {
                for (const auto &student : table[i]) {
                    student->displayStudentInfo();
                }
            }
        }
    }

    // Destructor to clean up dynamically allocated memory
    ~HashTable() {
        for (int i = 0; i < table_size; ++i) {
            for (auto student : table[i]) {
                delete student;
            }
        }
    }
};

int main() {
    HashTable studentTable;

    // Adding some students
    studentTable.insertStudent(101, "Alice", 3.8);
    studentTable.insertStudent(102, "Bob", 3.6);
    studentTable.insertStudent(103, "Charlie", 3.7);

    // Searching for a student
    cout << "\nSearching for Student with ID 101:" << endl;
    studentTable.searchStudent(101);

    // Deleting a student
    cout << "\nDeleting Student with ID 102:" << endl;
    studentTable.deleteStudent(102);

    // Displaying all students
    cout << "\nDisplaying All Students:" << endl;
    studentTable.displayAllStudents();

    return 0;
}
