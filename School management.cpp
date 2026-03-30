#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    string grade;

    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Grade: ";
        cin >> grade;
    }

    void display() {
        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nGrade: " << grade << endl;
    }
};

class School {
private:
    vector<Student> students;

public:
    void addStudent() {
        Student s;
        s.input();
        students.push_back(s);
        cout << "Student added successfully!\n";
    }

    void displayAll() {
        if (students.empty()) {
            cout << "No students found.\n";
            return;
        }

        for (auto &s : students) {
            s.display();
            cout << "-------------------\n";
        }
    }

    void searchStudent() {
        int id;
        cout << "Enter ID to search: ";
        cin >> id;

        for (auto &s : students) {
            if (s.id == id) {
                cout << "Student found:\n";
                s.display();
                return;
            }
        }

        cout << "Student not found.\n";
    }

    void deleteStudent() {
        int id;
        cout << "Enter ID to delete: ";
        cin >> id;

        for (auto it = students.begin(); it != students.end(); it++) {
            if (it->id == id) {
                students.erase(it);
                cout << "Student deleted successfully.\n";
                return;
            }
        }

        cout << "Student not found.\n";
    }
};

int main() {
    School school;
    int choice;

    do {
        cout << "\n===== School Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                school.addStudent();
                break;
            case 2:
                school.displayAll();
                break;
            case 3:
                school.searchStudent();
                break;
            case 4:
                school.deleteStudent();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}