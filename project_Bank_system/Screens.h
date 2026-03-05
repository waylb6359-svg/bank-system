#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "Admin.h"
#include "Client.h"
#include "Employee.h"
#include "Person.h"
#include "Validation.h"
#include "Parser.h"
#include "FileManager.h"
#include "DataSourceInterface.h"
#include "FilesHelper.h"
#include "EmployeeOperations.h"
#include "ClientManager.h"
#include "EmployeeManager.h"
#include "AdminManager.h"
using namespace std;
class Screens {
private:
    static void displayexit() {
        system("cls");
        cout << "\nThank you for using ROUTE EGYPTIAN BANK SYSTEM!";
        for (int i = 0; i <= 6; i++) {
            cout << "\n\t\t";
            for (int j = 0; j <= 6; j++) {
                if (
                    (i == 0 && (j == 1 || j == 2 || j == 4 || j == 5)) ||
                    (i == 1 && (j == 0 || j == 3 || j == 6)) ||
                    (i == 2 && (j == 0 || j == 6)) ||
                    (i == 3 && (j == 1 || j == 5)) ||
                    (i == 4 && (j == 2 || j == 4)) ||
                    (i == 5 && j == 3)
                    ) 
                {
                    system("color 0C");
                    cout << "o";
                }
                else {
                    cout << "  ";
                }
            }
            cout << endl;
        }
        cout << "\nGoodbye!" << endl;
        system("pause");
    }

    static void welcomeAnimation(string msg) {
        cout << "\n\n\t\t";
        for (int i = 0; i < msg.length(); i++) {
            cout << msg[i];
            for (long long j = 0; j < 90000000; j++); 
        }
        cout << "\n\n\t\t";
        string line = "**************************************";
        for (int i = 0; i < line.length(); i++) {
            cout << line[i];
            for (long long j = 0; j < 80000000; j++);
        }
        cout << endl << endl << endl;
    }

    static void clearScreen(string color = "0B") {
        if (color == "0B") system("color 0B");
        else if (color == "0A") system("color 0A");
        else if (color == "0D") system("color 0D");
        else if (color == "04") system("color 04");
        else system("color 07");
        
        system("cls");
    }

    static void clearInput() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    static void firstTimeSetup() {
        clearScreen();
        cout << "\n=== FIRST TIME SETUP ===\n";
        cout << "Welcome! This seems to be your first time running the program.\n";
        cout << "Let's create the first Admin account.\n\n";
        
        int id;
        string name, password;
        double salary;
        
        id = 1;
        
        cout << "Your Admin ID will be: " << id << "\n\n";
        
        do {
            cout << "Enter Admin Name (3-20 alphabetic chars): ";
            cin >> name;
        } while (!Validation::isValidName(name));
        
        do {
            cout << "Enter Admin Password (8-20 chars, no spaces): ";
            cin >> password;
        } while (!Validation::isValidPassword(password));
        
        do {
            cout << "Enter Admin Salary (Min 5000): ";
            cin >> salary;
            
            if (cin.fail()) {
                clearInput();
                salary = 0;
                cout << "Salary must be a number!\n";
            }
        } while (!Validation::isValidSalary(salary));
        
        Admin a(id, name, password, salary);
        FilesHelper::saveEmployee("Admin.txt", "AdminLastId.txt", a);
        
        cout << "\nAdmin account created successfully!\n";
        cout << "Your Admin ID is: " << id << "\n";
        cout << "Please remember your ID and password.\n";
        system("pause");
    }

    static void createClientAccount() {
        clearScreen();
        cout << "\n=== CREATE NEW CLIENT ACCOUNT ===\n";
        
        int id;
        string name, password;
        double balance;
        
        id = FilesHelper::getLast("ClientLastId.txt") + 1;
        
        cout << "Your ID will be: " << id << "\n\n";
        
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
                clearInput();
                balance = 0;
                cout << "Balance must be a number!\n";
            }
        } while (!Validation::isValidBalance(balance));
        
        Client c(id, name, password, balance);
        FilesHelper::saveClient(c);
        
        cout << "\nClient account created successfully!\n";
        cout << "Your ID is: " << id << "\n";
        cout << "Please remember your ID and password.\n";
        system("pause");
    }

    static void createEmployeeAccount() {
        clearScreen();
        cout << "\n=== CREATE NEW EMPLOYEE ACCOUNT ===\n";
        
        int id;
        string name, password;
        double salary;
        
        id = FilesHelper::getLast("EmployeeLastId.txt") + 1;
        
        cout << "Your ID will be: " << id << "\n\n";
        
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
                clearInput();
                salary = 0;
                cout << "Salary must be a number!\n";
            }
        } while (!Validation::isValidSalary(salary));
        
        Employee e(id, name, password, salary);
        FilesHelper::saveEmployee("Employee.txt", "EmployeeLastId.txt", e);
        
        cout << "\nEmployee account created successfully!\n";
        cout << "Your ID is: " << id << "\n";
        cout << "Please remember your ID and password.\n";
        system("pause");
    }

public:
    static void bankName() {
        cout << "================================\n";
        cout << "   ROUTE EGYPTIAN BANK SYSTEM   \n";
        cout << "================================\n";
    }
    
    static void welcome() {
        clearScreen();
        welcomeAnimation("WELCOME TO ROUTE EGYPTIAN BANK SYSTEM");
    }
    
    static void loginOptions() {
        cout << "\n1. Login as Client\n";
        cout << "2. Login as Employee\n";
        cout << "3. Login as Admin\n";
        cout << "4. Create New Client Account\n";
        cout << "5. Create New Employee Account\n";
        cout << "6. Exit\n\n";
    }
    
    static int loginAs() {
        int choice;
        cout << "Choose option: ";
        cin >> choice;
        
        if (cin.fail()) {
            clearInput();
            return -1;
        }
        return choice;
    }
    
    static void invalid(int c) {
        cout << "Invalid choice: " << c << "! Please try again.\n";
        system("pause");
    }
    
    static void logout() {
        cout << "Logging out...\n";
    }
    
    static void loginScreen(int c) {
        int id;
        string password;
        
        cout << "\n=== LOGIN ===\n";
        cout << "Enter ID: ";
        cin >> id;
        
        if (cin.fail()) {
            clearInput();
            cout << "\nError: ID must be a number!\n";
            system("pause");
            return;
        }
        
        cout << "Enter Password: ";
        cin >> password;
        
        if (c == 1) {
            Client* client = ClientManager::login(id, password);
            if (client) {
                cout << "\nLogin successful! Welcome " << client->getName() << "\n";
                system("pause");
                ClientManager::clientOptions(client);
                delete client;
            } else {
                cout << "\nInvalid ID or Password! Please try again.\n";
                system("pause");
            }
        }
        else if (c == 2) {
            Employee* employee = EmployeeManager::login(id, password);
            if (employee) {
                cout << "\nLogin successful! Welcome " << employee->getName() << "\n";
                system("pause");
                EmployeeManager::employeeOptions(employee);
                delete employee;
            } else {
                cout << "\nInvalid ID or Password! Please try again.\n";
                system("pause");
            }
        }
        else if (c == 3) {
            Admin* admin = AdminManager::login(id, password);
            if (admin) {
                cout << "\nLogin successful! Welcome " << admin->getName() << "\n";
                system("pause");
                AdminManager::adminOptions(admin);
                delete admin;
            } else {
                cout << "\nInvalid ID or Password! Please try again.\n";
                system("pause");
            }
        }
    }
    
    static void runApp() {
        vector<Admin> admins = FilesHelper::getAdmins();
        if (admins.empty()) {
            firstTimeSetup();
        }
        
        while (true) {
            welcome();
            loginOptions();
            int choice = loginAs();
            
            if (choice == -1) {
                cout << "\nPlease enter a valid number!\n";
                system("pause");
                continue;
            }
            
            if (choice == 6) {
                displayexit();
                break;
            }
            
            if (choice == 4) {
                createClientAccount();
                continue;
            }
            
            if (choice == 5) {
                createEmployeeAccount();
                continue;
            }
            
            if (choice < 1 || choice > 6) {
                invalid(choice);
                continue;
            }
            
            loginScreen(choice);
        }
    }
};