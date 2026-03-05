#pragma once
#include "Employee.h"
#include "EmployeeOperations.h"
#include "FilesHelper.h"
#include <iostream>
#include <vector>
using namespace std;

class EmployeeManager {
public:
    static void printEmployeeMenu() {
        cout << "\n=== Employee Menu ===\n";
        cout << "1. Add New Client\n";
        cout << "2. List All Clients\n";
        cout << "3. Search for Client\n";
        cout << "4. Edit Client Info\n";
        cout << "5. Change Password\n";
        cout << "6. Logout\n";
    }

    static void newClient(Employee* employee) {
        system("cls");
        string name, password;
        double balance;
        int id;

        id = FilesHelper::getLast("ClientLastId.txt") + 1;

        cout << "New Client ID will be: " << id << "\n\n";

        do {
            cout << "Enter Name (3-20 alphabetic chars): ";
            cin >> name;
        } while (!Validation::isValidName(name));

        do {
            cout << "Enter Password (8-20 chars, no spaces): ";
            cin >> password;
        } while (!Validation::isValidPassword(password));

        do {
            cout << "Enter Initial Balance (Min 1500): ";
            cin >> balance;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                balance = 0;
                cout << "Balance must be a number!\n";
            }
        } while (!Validation::isValidBalance(balance));

        Client c(id, name, password, balance);
        EmployeeOperations::addClient(c);

        cout << "Client created with ID: " << id << "\n";
        system("pause");
    }

    static void listAllClients(Employee* employee) {
        system("cls");
        EmployeeOperations::listClient();
        system("pause");
    }

    static void searchForClient(Employee* employee) {
        system("cls");
        int id;
        cout << "Enter Client ID to search: ";
        cin >> id;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid ID!\n";
            system("pause");
            return;
        }

        Client* client = EmployeeOperations::searchClient(id);
        if (client) {
            client->display();
            delete client;
        }
        else {
            cout << "\nClient not found!\n";
        }
        system("pause");
    }

    static void editClientInfo(Employee* employee) {
        system("cls");
        int id;
        string name, password;
        double balance;

        cout << "Enter Client ID to edit: ";
        cin >> id;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid ID!\n";
            system("pause");
            return;
        }

        Client* existing = EmployeeOperations::searchClient(id);
        if (!existing) {
            cout << "\nClient not found!\n";
            system("pause");
            return;
        }
        delete existing;

        do {
            cout << "Enter New Name (3-20 alphabetic chars): ";
            cin >> name;
        } while (!Validation::isValidName(name));

        do {
            cout << "Enter New Password (8-20 chars, no spaces): ";
            cin >> password;
        } while (!Validation::isValidPassword(password));

        do {
            cout << "Enter New Balance (Min 1500): ";
            cin >> balance;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                balance = 0;
                cout << "Balance must be a number!\n";
            }
        } while (!Validation::isValidBalance(balance));

        EmployeeOperations::editClient(id, name, password, balance);
        system("pause");
    }

    static void updatePassword(Employee* employee) {
        system("cls");
        string newPass;
        do {
            cout << "Enter new password (8-20 chars, no spaces): ";
            cin >> newPass;
        } while (!Validation::isValidPassword(newPass));

        employee->setPassword(newPass);

        vector<Employee> employees = FilesHelper::getEmployees();
        for (Employee& e : employees) {
            if (e.getId() == employee->getId()) {
                e.setPassword(newPass);
                break;
            }
        }

        FilesHelper::clearFile("Employee.txt", "EmployeeLastId.txt");
        for (Employee& e : employees) {
            FilesHelper::saveEmployee("Employee.txt", "EmployeeLastId.txt", e);
        }

        cout << "\nPassword updated successfully!\n";
        system("pause");
    }

    static Employee* login(int id, string password) {
        vector<Employee> employees = FilesHelper::getEmployees();
        for (Employee& e : employees) {
            if (e.getId() == id && e.getPassword() == password) {
                return new Employee(e);
            }
        }
        return nullptr;
    }

    static bool employeeOptions(Employee* employee) {
        int choice;
        do {
            system("cls");
            printEmployeeMenu();
            cout << "Enter choice: ";
            cin >> choice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\nPlease enter a valid number!\n";
                system("pause");
                continue;
            }

            switch (choice) {
            case 1:
                newClient(employee);
                //up file
                break;
            case 2:
                listAllClients(employee);
                break;
            case 3:
                searchForClient(employee);
                break;
            case 4:
                editClientInfo(employee);
                //up file

                break;
            case 5:
                updatePassword(employee);
                //up file

                break;
            case 6:
                cout << "\nLogging out...\n";
                system("pause");
                return false;
            default:
                cout << "\nInvalid choice! Please try again.\n";
                system("pause");
            }
        } while (choice != 6);

        return true;
    }
};