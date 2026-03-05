#pragma once
#include <string>
#include <vector>
#include <sstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

using namespace std;

class Parser {
public:
    static vector<string> split(const string& line, char delimiter = ',') {
        vector<string> tokens;
        string token;
        istringstream tokenStream(line);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    static Client parseToClient(const string& line) {
        vector<string> tokens = split(line);
        int id = stoi(tokens[0]);
        string name = tokens[1];
        string password = tokens[2];
        double balance = stod(tokens[3]);
        return Client(id, name, password, balance);
    }

    static Employee parseToEmployee(const string& line) {
        vector<string> tokens = split(line);
        int id = stoi(tokens[0]);
        string name = tokens[1];
        string password = tokens[2];
        double salary = stod(tokens[3]);
        return Employee(id, name, password, salary);
    }

    static Admin parseToAdmin(const string& line) {
        vector<string> tokens = split(line);
        int id = stoi(tokens[0]);
        string name = tokens[1];
        string password = tokens[2];
        double salary = stod(tokens[3]);
        return Admin(id, name, password, salary);
    }
};