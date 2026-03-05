#pragma once
#include <iostream>
#include <string>
using namespace std;

class Validation {
public:
    static bool isValidName(string name) {
        if (name.length() < 3 || name.length() > 20) {
            return false;
        }

        for (int i = 0; i < name.length(); i++) {
            char c = name[i];
            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
                return false;
            }
        }
        return true;
    }

    static bool isValidPassword(string password) {
        if (password.length() < 8 || password.length() > 20) {
            return false;
        }

        for (int i = 0; i < password.length(); i++) {
            char c = password[i];
            if (c == ' ' || c == '\t' || c == '\n') {
                return false;
            }
        }
        return true;
    }

    static bool isValidBalance(double balance) {
        return balance >= 1500;
    }

    static bool isValidSalary(double salary) {
        return salary >= 5000;
    }
};