#include<iostream>
#include<vector>
using namespace std;

struct Student {
    int roll;
    string name;
    string course;
};

vector<Student> students;

// Function to add student
void addStudent() {
    Student s;
    cout << "Enter Roll Number: ";
    cin >> s.roll;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter Course: ";
    getline(cin, s.course);
    students.push_back(s);
    cout << "Student Added Successfully!\n";
}

// Function to display all students
void displayStudents() {
    if (students.empty()) {
        cout << "No records found.\n";
        return;
    }
    cout << "List of Students:\n";
    for (auto s : students) {
        cout << "Roll: " << s.roll << ", Name: " << s.name << ", Course: " << s.course << endl;
    }
}

// Function to search student by roll number
void searchStudent() {
    int roll;
    cout << "Enter Roll Number to search: ";
    cin >> roll;
    for (auto s : students) {
        if (s.roll == roll) {
            cout << "Student Found!\n";
            cout << "Roll: " << s.roll << ", Name: " << s.name << ", Course: " << s.course << endl;
            return;
        }
    }
    cout << "Student not found.\n";
}

// Function to delete student by roll number
void deleteStudent() {
    int roll;
    cout << "Enter Roll Number to delete: ";
    cin >> roll;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->roll == roll) {
            students.erase(it);
            cout << "Student deleted successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}