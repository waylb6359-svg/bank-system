#pragma once
#include "Person.h"
#include "Validation.h"
#include <iostream>
using namespace std;

class Client : public Person {
    double balance = 0;

public:
    Client() {}

    Client(int id, string& name, string& password, double balance)
        : Person(id, name, password) {
        setBalance(balance);
    }

    bool setBalance(double balance) {
        if (!Validation::isValidBalance(balance)) {
            cout << "Error: Minimum balance is 1500!\n";
            return false;
        }
        this->balance = balance;
        return true;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount!\n";
            return;
        }
        balance += amount;
        cout << "Deposited: " << amount << " | Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            cout << "Invalid amount or insufficient balance!\n";
            return;
        }
        balance -= amount;
        cout << "Withdrawn: " << amount << " | Balance: " << balance << endl;
    }

    void transferTo(double amount, Client& recipient) {
        if (amount <= 0 || amount > balance) {
            cout << "Transfer failed!\n";
            return;
        }
        balance -= amount;
        recipient.balance += amount;
        cout << "Transferred " << amount << " to " << recipient.getName() << endl;
    }

    void checkBalance() {
        cout << "Client: " << name << " | Balance: " << balance << endl;
    }

    void display() override {
        Person::display();
        cout << "Balance: " << balance << "\n------------------------\n";
    }
};