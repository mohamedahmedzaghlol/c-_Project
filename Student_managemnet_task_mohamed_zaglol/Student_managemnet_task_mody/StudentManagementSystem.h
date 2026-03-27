#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "Student.h"

using namespace std;

class StudentManagementSystem {
private:
    map<int, Student> students;

public:
    void addStudent() {
        int id;
        string name;
        double gpa;
        cout << "enter id: ";
        cin >> id;
        if (students.find(id) != students.end()) {
            cout << "id already exists\n";
            return;
        }
        cout << "enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "enter gpa: ";
        cin >> gpa;
        students.emplace(id, Student(id, name, gpa));
        cout << "added.\n";
    }

    void removeStudent() {
        int id;
        cout << "enter id to remove: ";
        cin >> id;
        if (students.erase(id))
        {
            cout << "remove\n";
        }
        else 
            cout << "not found\n";
    }

    void searchStudent() {
        int id;
        cout << "enter id: ";
        cin >> id;
        if (students.count(id))
        { 
            students[id].printInfo();
        }
        else
            cout << "not found\n";
    }

    void displayAllStudents() {
        if (students.empty())
        {
            cout << "empty list.\n"; return;
        }
        for (auto p : students) {
            p.second.printInfo(); 
        }
    }

    void enrollStudentInCourse() {
        int id;
        cout << "enter student id: ";
        cin >> id;
        if (students.count(id)) {
            string course; cout << "course name: "; 
            cin.ignore(); getline(cin, course);
            if (students[id].enrollInCourse(course)) 
                cout << "enrolled\n";
            else cout << "already \n";
        }
        else cout << "not found\n";
    }

    void showStudentCourses() {
        int id;
        cout << "enter id: "; 
        cin >> id;
        if (students.count(id)) {
            for (string c : students[id].getCourses()) 
                cout << c << "\n";
        }
        else cout << "not found\n";
    }
    bool compareGPA(Student a, Student b) {
        return a.getGpa() > b.getGpa(); 
    }
    //void sortStudentsByGpa() {
    //    vector<Student> v;

    //    for (auto p : students) {
    //        v.push_back(p.second);
    //    }
    //    sort(v.begin(), v.end(), compareGPA);
    //    for (Student s : v) {
    //        s.printInfo();
    //    }
    //}

    void searchByName() {
        string target;
        cout << "enter name: ";
        cin.ignore();
        getline(cin, target);

        bool found = false;
        for (auto p : students) {
            if (p.second.getName() == target) {
                p.second.printInfo();
                found = true;
            }
        }

        if (!found) cout << "not found\n";
    }

    void saveToFile() {
        ofstream out("data.txt");
        for (auto const& [id, s] : students) {
            out << s.getId() << "|" << s.getName() << "|" << s.getGpa() << "|";
            for (string c : s.getCourses()) out << c << ",";
            out << "\n";
        }
        cout << "saved to data.txt\n";
    }

    void loadFromFile() {
        ifstream in("data.txt");
        if (!in) return;
        students.clear(); string line;
        while (getline(in, line)) {
            stringstream ss(line); string sid, sname, sgpa, scourses;
            getline(ss, sid, '|'); getline(ss, sname, '|'); getline(ss, sgpa, '|'); getline(ss, scourses, '|');
            if (!sid.empty()) {
                Student temp(stoi(sid), sname, stod(sgpa));
                stringstream ss2(scourses); string c;
                while (getline(ss2, c, ',')) { if (!c.empty()) temp.enrollInCourse(c); }
                students[stoi(sid)] = temp;
            }
        }
        cout << "loaded.\n";
    }
};