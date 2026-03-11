#pragma once
#include "Admin.h"
#include "EmployeeOperations.h"
#include "EmployeeManager.h"
#include "FilesHelper.h"
#include <iostream>
#include <vector>
using namespace std;

class AdminManager {
public:
    static void printAdminMenu() {
        cout << "\n=== Admin Menu ===\n";
        cout << "1. Add New Client\n";
        cout << "2. List All Clients\n";
        cout << "3. Search for Client\n";
        cout << "4. Edit Client Info\n";
        cout << "5. Add New Employee\n";
        cout << "6. List All Employees\n";
        cout << "7. Search for Employee\n";
        cout << "8. Edit Employee Info\n";
        cout << "9. Add New Admin\n";
        cout << "10. Clear All Data\n";
        cout << "11. Change Password\n";
        cout << "12. Logout\n";
    }

    static void clearAllData() {
        system("cls");
        cout << "\n=== CLEAR ALL DATA ===\n";
        cout << "Are you sure you want to delete ALL data?\n";
        cout << "This will remove all Clients, Employees, and Admins!\n";
        cout << "Type 'YES' to confirm: ";

        string confirm;
        cin >> confirm;

        if (confirm == "YES" || confirm == "yes") {
            FilesHelper::clearFile("Clients.txt", "ClientLastId.txt");
            FilesHelper::clearFile("Employee.txt", "EmployeeLastId.txt");
            FilesHelper::clearFile("Admin.txt", "AdminLastId.txt");

            cout << "\nAll data has been cleared successfully!\n";
            cout << "The system will now restart for first time setup.\n";
            system("pause");

            exit(0);
        }
        else {
            cout << "\nOperation cancelled.\n";
            system("pause");
        }
    }

    static void addEmployee(Admin* admin) {
        system("cls");
        string name, password;
        double salary;
        int id;

        id = FilesHelper::getLast("EmployeeLastId.txt") + 1;

        cout << "New Employee ID will be: " << id << "\n\n";

        do {
            cout << "Enter Name (3-20 alphabetic chars): ";
            cin >> name;
        } while (!Validation::isValidName(name));

        do {
            cout << "Enter Password (8-20 chars, no spaces): ";
            cin >> password;
        } while (!Validation::isValidPassword(password));

        do {
            cout << "Enter Salary (Min 5000): ";
            cin >> salary;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                salary = 0;
                cout << "Salary must be a number!\n";
            }
        } while (!Validation::isValidSalary(salary));

        Employee e(id, name, password, salary);
        FilesHelper::saveEmployee("Employee.txt", "EmployeeLastId.txt", e);

        cout << "\nEmployee added successfully with ID: " << id << "\n";
        system("pause");
    }

    static void addAdmin(Admin* admin) {
        system("cls");
        string name, password;
        double salary;
        int id;

        id = FilesHelper::getLast("AdminLastId.txt") + 1;

        cout << "New Admin ID will be: " << id << "\n\n";

        do {
            cout << "Enter Name (3-20 alphabetic chars): ";
            cin >> name;
        } while (!Validation::isValidName(name));

        do {
            cout << "Enter Password (8-20 chars, no spaces): ";
            cin >> password;
        } while (!Validation::isValidPassword(password));

        do {
            cout << "Enter Salary (Min 5000): ";
            cin >> salary;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                salary = 0;
                cout << "Salary must be a number!\n";
            }
        } while (!Validation::isValidSalary(salary));

        Admin a(id, name, password, salary);
        FilesHelper::saveEmployee("Admin.txt", "AdminLastId.txt", a);

        cout << "\nNew Admin added successfully with ID: " << id << "\n";
        system("pause");
    }

    static void listAllEmployees(Admin* admin) {
        system("cls");
        vector<Employee> employees = FilesHelper::getEmployees();
        if (employees.empty()) {
            cout << "\nNo employees found.\n";
        }
        else {
            cout << "\n--- All Employees ---\n";
            for (Employee& e : employees) {
                e.display();
            }
        }
        system("pause");
    }

    static void searchForEmployee(Admin* admin) {
        system("cls");
        int id;
        cout << "Enter Employee ID to search: ";
        cin >> id;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid ID!\n";
            system("pause");
            return;
        }

        vector<Employee> employees = FilesHelper::getEmployees();
        for (Employee& e : employees) {
            if (e.getId() == id) {
                e.display();
                system("pause");
                return;
            }
        }
        cout << "\nEmployee not found!\n";
        system("pause");
    }

    static void editEmployeeInfo(Admin* admin) {
        system("cls");
        int id;
        string name, password;
        double salary;

        cout << "Enter Employee ID to edit: ";
        cin >> id;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid ID!\n";
            system("pause");
            return;
        }

        vector<Employee> employees = FilesHelper::getEmployees();
        bool found = false;

        for (size_t i = 0; i < employees.size(); i++) {
            if (employees[i].getId() == id) {
                do {
                    cout << "Enter New Name (3-20 alphabetic chars): ";
                    cin >> name;
                } while (!Validation::isValidName(name));

                do {
                    cout << "Enter New Password (8-20 chars, no spaces): ";
                    cin >> password;
                } while (!Validation::isValidPassword(password));

                do {
                    cout << "Enter New Salary (Min 5000): ";
                    cin >> salary;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        salary = 0;
                        cout << "Salary must be a number!\n";
                    }
                } while (!Validation::isValidSalary(salary));

                employees[i].setName(name);
                employees[i].setPassword(password);
                employees[i].setSalary(salary);
                found = true;
                break;
            }
        }

        if (found) {
            FilesHelper::clearFile("Employee.txt", "EmployeeLastId.txt");
            for (Employee& e : employees) {
                FilesHelper::saveEmployee("Employee.txt", "EmployeeLastId.txt", e);
            }
            cout << "\nEmployee updated successfully!\n";
        }
        else {
            cout << "\nEmployee not found!\n";
        }
        system("pause");
    }

    static void updatePassword(Admin* admin) {
        system("cls");
        string newPass;
        do {
            cout << "Enter new password (8-20 chars, no spaces): ";
            cin >> newPass;
        } while (!Validation::isValidPassword(newPass));

        admin->setPassword(newPass);

        vector<Admin> admins = FilesHelper::getAdmins();
        for (Admin& a : admins) {
            if (a.getId() == admin->getId()) {
                a.setPassword(newPass);
                break;
            }
        }

        FilesHelper::clearFile("Admin.txt", "AdminLastId.txt");
        for (Admin& a : admins) {
            FilesHelper::saveEmployee("Admin.txt", "AdminLastId.txt", a);
        }

        cout << "\nPassword updated successfully!\n";
        system("pause");
    }

    static Admin* login(int id, string password) {
        vector<Admin> admins = FilesHelper::getAdmins();
        for (Admin& a : admins) {
            if (a.getId() == id && a.getPassword() == password) {
                return new Admin(a);
            }
        }
        return nullptr;
    }

    static bool adminOptions(Admin* admin) {
        int choice;
        do {
            system("cls");
            printAdminMenu();
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
                EmployeeManager::newClient(nullptr);
                break;
            case 2:
                EmployeeManager::listAllClients(nullptr);
                break;
            case 3:
                EmployeeManager::searchForClient(nullptr);
                break;
            case 4:
                EmployeeManager::editClientInfo(nullptr);
                break;
            case 5:
                addEmployee(admin);
                break;
            case 6:
                listAllEmployees(admin);
                break;
            case 7:
                searchForEmployee(admin);
                break;
            case 8:
                editEmployeeInfo(admin);

                break;
            case 9:
                addAdmin(admin);

                break;
            case 10:
                clearAllData();
                break;
            case 11:
                updatePassword(admin);

                break;
            case 12:
                cout << "\nLogging out...\n";
                system("pause");
                return false;
            default:
                cout << "\nInvalid choice! Please try again.\n";
                system("pause");
            }
        } while (choice != 12);

        return true;
    }
};
