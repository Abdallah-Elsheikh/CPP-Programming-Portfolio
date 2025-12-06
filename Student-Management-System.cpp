#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

// Case Study: Student Registration System
// Attributes: ID, First Name, Last Name, Age, Department

struct Student {
    int id;
    string fname, lname, dept;
    int age;
};

vector<Student> students;

// Function to load data from file
void loadData() {
    ifstream file("students.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Student s;
        string temp;
        getline(ss, temp, ','); s.id = stoi(temp);
        getline(ss, s.fname, ',');
        getline(ss, s.lname, ',');
        getline(ss, temp, ','); s.age = stoi(temp);
        getline(ss, s.dept, ',');
        students.push_back(s);
    }
    file.close();
}

// Function to save data to file
void saveData() {
    ofstream file("students.txt");
    for (auto &s : students) {
        file << s.id << "," << s.fname << "," << s.lname << ","
             << s.age << "," << s.dept << endl;
    }
    file.close();
}

// Insert new record
void insertRecord() {
    Student s;
    cout << "Enter ID: "; cin >> s.id;
    cout << "Enter First Name: "; cin >> s.fname;
    cout << "Enter Last Name: "; cin >> s.lname;
    cout << "Enter Age: "; cin >> s.age;
    cout << "Enter Department: "; cin >> s.dept;
    students.push_back(s);
    saveData();
}

// Delete record
void deleteRecord() {
    int id;
    cout << "Enter ID to delete: "; cin >> id;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            saveData();
            cout << "Record deleted.\n";
            return;
        }
    }
    cout << "Record not found.\n";
}

// Update record
void updateRecord() {
    int id;
    cout << "Enter ID to update: "; cin >> id;
    for (auto &s : students) {
        if (s.id == id) {
            cout << "Enter new first name: "; cin >> s.fname;
            cout << "Enter new last name: "; cin >> s.lname;
            cout << "Enter new age: "; cin >> s.age;
            cout << "Enter new department: "; cin >> s.dept;
            saveData();
            cout << "Record updated.\n";
            return;
        }
    }
    cout << "Record not found.\n";
}

// Search record
void searchRecord() {
    int id;
    cout << "Enter ID to search: "; cin >> id;
    for (auto &s : students) {
        if (s.id == id) {
            cout << "Found: " << s.fname << " " << s.lname << ", "
                 << s.age << " years, Dept: " << s.dept << endl;
            return;
        }
    }
    cout << "Record not found.\n";
}

int main() {
    loadData();
    int choice;
    do {
        cout << "\n1.Insert\n2.Delete\n3.Update\n4.Search\n5.Exit\n";
        cout << "Enter choice: "; cin >> choice;
        switch (choice) {
            case 1: insertRecord(); break;
            case 2: deleteRecord(); break;
            case 3: updateRecord(); break;
            case 4: searchRecord(); break;
        }
    } while (choice != 5);
    return 0;
}
