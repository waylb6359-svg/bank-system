#pragma once
#include "Employee.h"
#include "FilesHelper.h"
#include "Client.h"
#include <iostream>
#include <vector>
using namespace std;

class EmployeeOperations {
public:
    static void addClient(Client& client) {
        FilesHelper::saveClient(client);
        cout << "\nClient " << client.getName() << " added successfully.\n";
    }

    static Client* searchClient(int id) {
        vector<Client> allClients = FilesHelper::getClients();
        for (Client& c : allClients) {
            if (c.getId() == id) {
                return new Client(c);
            }
        }
        return nullptr;
    }

    static void listClient() {
        vector<Client> allClients = FilesHelper::getClients();
        if (allClients.empty()) {
            cout << "\nNo clients to display.\n";
            return;
        }
        cout << "\n--- All Clients ---\n";
        for (Client& c : allClients) {
            c.display();
        }
        cout << "-------------------\n";
    }

    static void editClient(int id, string name, string password, double balance) {
        vector<Client> allClients = FilesHelper::getClients();
        bool found = false;
        for (size_t i = 0; i < allClients.size(); ++i) {
            if (allClients[i].getId() == id) {
                allClients[i].setName(name);
                allClients[i].setPassword(password);
                allClients[i].setBalance(balance);
                found = true;
                break;
            }
        }
        if (found) {
            FilesHelper::clearFile("Clients.txt", "ClientLastId.txt");
            for (Client& c : allClients) {
                FilesHelper::saveClient(c);
            }
            cout << "\nClient with ID " << id << " updated successfully.\n";
        }
        else {
            cout << "\nClient with ID " << id << " not found.\n";
        }
    }
};