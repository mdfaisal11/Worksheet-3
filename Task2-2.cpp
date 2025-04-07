#include <iostream>
#include <fstream>
#include<vector>
using namespace std;

class StudentsRecords
{
private:
    string roll, name;
    int marks;

public:
    void readStudents()
    {
        ifstream file("students.txt");
        if (!file) {
            cout << "Error opening file" << endl;
            return;
        }
        while (file >> roll >> name >> marks) {
            if (marks < 0 || marks > 100) {
                cout << "Invalid number Enter a number between 0 to 100." << endl;
            } else {
                cout << "Roll: " << roll << ", Name: " << name << ", Marks: " << marks << endl;
            }
        }
        file.close();
    }

    void addStudent()
    {
        ofstream file("students.txt", ios::app);
        if (!file) {
            cout << "Error opening file" << endl;
            return;
        }
        string roll, name;
        int marks;
        cout << "Enter Roll No, Name, and Marks: ";
        cin >> roll >> name >> marks;
        if (marks < 0 || marks > 100) {
            cout << "Invalid marks! Must be between 0 and 100." << endl;
            return;
        }
        file << roll << " " << name << " " << marks << endl;
        file.close();
        cout << "Student record added successfully!" << endl;
    }
    void modifyStudent()
    {
        ifstream file("students.txt");
        if (!file) {
            cout << "Error opening file" << endl;
            return;
        }
        vector<pair<string, pair<string, int>>> students;
        string r, n;
        int m;
        while (file >> r >> n >> m) {
            students.push_back({r, {n, m}});
        }
        file.close();

        string rollNo;
        cout << "Enter Roll No of the student to modify: ";
        cin >> rollNo;

        bool found = false;
        for (auto &student : students) {
            if (student.first == rollNo) {
                cout << "Enter new Name and Marks: ";
                cin >> student.second.first >> student.second.second;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Student not found!" << endl;
            return;
        }

        ofstream outFile("students.txt");
        for (const auto &student : students) {
            outFile << student.first << " " << student.second.first << " " << student.second.second << endl;
        }
        outFile.close();
        cout << "Student record updated successfully!" << endl;
    }
};

int main()
{
    StudentsRecords sr;
    int choice;
    cout << "\nEnter your choice:" << endl;
    cout << "1. Read Students" << endl;
    cout << "2. Add Student" << endl;
    cout<<  "3. Modify"<<endl;
    cout << "3. Exit" << endl;
    cout << "Choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            sr.readStudents();
            break;
        case 2:
            sr.addStudent();
            break;
        case 3:
            sr.modifyStudent();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice Please enter 1, 2, or 4." << endl;
    }

    return 0;
}
