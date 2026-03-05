#pragma once
#include "Person.h"
#include "Validation.h"
#include <iostream>
#include <vector> 
#include <string>
using namespace std;

class Employee : public Person {
protected:
    double salary = 0;

public:
    Employee() {}

    Employee(int id, string& name, string& password, double salary)
        : Person(id, name, password) {
        setSalary(salary);
    }

    bool setSalary(double salary) {
        if (!Validation::isValidSalary(salary)) {
            cout << "\nError: Minimum salary is 5000!\n";
            return false;
        }
        this->salary = salary;
        return true;
    }

    double getSalary() {
        return salary;
    }

    void display() override {
        Person::display();
        cout << "Salary: " << salary << "\n------------------------\n";
    }
};