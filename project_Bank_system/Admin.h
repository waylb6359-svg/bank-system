#pragma once
#include "Employee.h"
#include <iostream>
using namespace std;

class Admin : public Employee {
public:
    Admin() {}
    Admin(int id, string& name, string& password, double salary)
        : Employee(id, name, password, salary) {
    }
    void display() override {
        cout << "--- Admin Info ---\n";
        Employee::display();
    }
};