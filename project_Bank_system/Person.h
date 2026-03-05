#pragma once
#include <iostream>
#include <string>
#include "Validation.h"
using namespace std;

class Person {
protected:
    int id = 0;
    string name;
    string password;

public:
    Person() {}

    Person(int id, string& name, string& password)
        : id(id), name(name), password(password) {
    }

    void setId(int id) {
        this->id = id;
    }

    bool setName(string& name) {
        if (!Validation::isValidName(name)) {
            cout << "\nError: Invalid Name! (3-20 alphabetic chars)\n";
            return false;
        }
        this->name = name;
        return true;
    }

    bool setPassword(string& password) {
        if (!Validation::isValidPassword(password)) {
            cout << "\nError: Invalid Password! (8-20 chars, no spaces)\n";
            return false;
        }
        this->password = password;
        return true;
    }

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    string getPassword() {
        return password;
    }

    virtual void display() {
        cout << "ID: " << id << "\nName: " << name << endl;
    }

    virtual ~Person() {}
};