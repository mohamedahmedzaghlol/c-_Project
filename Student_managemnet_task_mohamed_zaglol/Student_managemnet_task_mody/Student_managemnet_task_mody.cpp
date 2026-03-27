#include <iostream>
#include "StudentManagementSystem.h"

using namespace std;

int main() {
    StudentManagementSystem system;
    int choice;

    while (true) {
        cout << "\n1.Add\n 2.Remove\n 3.Search\n 4.All\n 5.Enroll\n 6.Courses\n 7.Sort\n 8.Name\n 9.Save\n 10.Load\n 11.Exit\n";
        cout << "choice: ";
        if (!(cin >> choice)) { cin.clear(); cin.ignore(1000, '\n'); continue; }

        if (choice == 1) system.addStudent();
        else if (choice == 2) system.removeStudent();
        else if (choice == 3) system.searchStudent();
        else if (choice == 4) system.displayAllStudents();
        else if (choice == 5) system.enrollStudentInCourse();
        else if (choice == 6) system.showStudentCourses();
        //else if (choice == 7) system.sortStudentsByGpa();
        else if (choice == 8) system.searchByName();
        else if (choice == 9) system.saveToFile();
        else if (choice == 10) system.loadFromFile();
        else if (choice == 11) break;
    }
    return 0;
}