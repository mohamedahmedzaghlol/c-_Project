#pragma once
#include <string>

using namespace std;

class Person {
protected:
    string name;

public:
    Person() { name = ""; }
    Person(string personName) { name = personName; }

    string getName() const { return name; }
    void setName(string personName) { name = personName; }
};