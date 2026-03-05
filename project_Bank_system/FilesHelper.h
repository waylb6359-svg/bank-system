#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"

using namespace std;

class FilesHelper {
public:
    static void saveLast(string fileName, int id) {
        ofstream file(fileName);
        if (file.is_open()) {
            file << id;
            file.close();
        }
    }

    static int getLast(string fileName) {
        ifstream file(fileName);
        int id = 0;
        if (file.is_open()) {
            file >> id;
            file.close();
        }
        return id;
    }

    static void saveClient(Client c) {
        ofstream file("Clients.txt", ios::app);
        if (file.is_open()) {
            file << c.getId() << "," << c.getName() << "," << c.getPassword() << "," << c.getBalance() << endl;
            file.close();
            saveLast("ClientLastId.txt", c.getId());
        }
    }

    static void saveEmployee(string fileName, string lastIdFile, Employee e) {
        ofstream file(fileName, ios::app);
        if (file.is_open()) {
            file << e.getId() << "," << e.getName() << "," << e.getPassword() << "," << e.getSalary() << endl;
            file.close();
            saveLast(lastIdFile, e.getId());
        }
    }

    static vector<Client> getClients() {
        vector<Client> clients;
        ifstream file("Clients.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                clients.push_back(Parser::parseToClient(line));
            }
            file.close();
        }
        return clients;
    }

    static vector<Employee> getEmployees() {
        vector<Employee> employees;
        ifstream file("Employee.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                employees.push_back(Parser::parseToEmployee(line));
            }
            file.close();
        }
        return employees;
    }

    static vector<Admin> getAdmins() {
        vector<Admin> admins;
        ifstream file("Admin.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                admins.push_back(Parser::parseToAdmin(line));
            }
            file.close();
        }
        return admins;
    }

    static void clearFile(string fileName, string lastIdFile) {
        ofstream file(fileName, ios::trunc);
        if (file.is_open()) {
            file.close();
        }
        saveLast(lastIdFile, 0);
    }
};