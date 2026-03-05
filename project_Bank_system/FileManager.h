#pragma once
#include "Employee.h" 
#include "Admin.h"    
#include "Client.h"   
#include "DataSourceInterface.h"
#include "FilesHelper.h"
#include <vector>

class FileManager : public DataSourceInterface {
public:
    void addClient(Client obj) override {
        FilesHelper::saveClient(obj);
    }

    vector<Client> getAllClients() override {
        return FilesHelper::getClients();
    }

    void removeAllClients() override {
        FilesHelper::clearFile("Clients.txt", "ClientLastId.txt");
    }

    void addEmployee(Employee obj) override {
        FilesHelper::saveEmployee("Employee.txt", "EmployeeLastId.txt", obj);
    }

    vector<Employee> getAllEmployees() override {
        return FilesHelper::getEmployees();
    }

    void removeAllEmployees() override {
        FilesHelper::clearFile("Employee.txt", "EmployeeLastId.txt");
    }

    void addAdmin(Admin obj) override {
        FilesHelper::saveEmployee("Admin.txt", "AdminLastId.txt", obj);
    }

    vector<Admin> getAllAdmins() override {
        return FilesHelper::getAdmins();
    }

    void removeAllAdmins() override {
        FilesHelper::clearFile("Admin.txt", "AdminLastId.txt");
    }
};