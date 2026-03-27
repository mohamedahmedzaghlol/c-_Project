#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Person.h"

using namespace std;

class Student : public Person {
private:
    int id;
    double gpa;
    vector<string> courses;

public:
    Student() : Person(), id(0), gpa(0.0) {}
    Student(int studentId, string studentName, double studentGpa)
        : Person(studentName) {
        id = studentId;
        gpa = studentGpa;
    }

    int getId() const { return id; }
    double getGpa() const { return gpa; }

    bool enrollInCourse(string courseName) {
        for (string c : courses) {
            if (c == courseName) return false;
        }
        courses.push_back(courseName);
        return true;
    }

    vector<string> getCourses() const { return courses; }

    void printInfo() const {
        cout << "id: " << id
            << " | name: " << name
            << " | gpa: " << fixed << setprecision(2) << gpa << endl;
    }
};