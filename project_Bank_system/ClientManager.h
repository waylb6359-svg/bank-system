#pragma once
#include "Client.h"
#include "FilesHelper.h"
#include <iostream>
#include <vector>
using namespace std;

class ClientManager {
public:
    static void printClientMenu() {
        cout << "\n=== Client Menu ===\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer\n";
        cout << "4. Check Balance\n";
        cout << "5. Change Password\n";
        cout << "6. Logout\n";
    }

    static void updatePassword(Person* person) {
        string newPass;
        do {
            cout << "Enter new password (8-20 chars, no spaces): ";
            cin >> newPass;
        } while (!Validation::isValidPassword(newPass));

        person->setPassword(newPass);

        vector<Client> clients = FilesHelper::getClients();
        for (Client& c : clients) {
            if (c.getId() == person->getId()) {
                c.setPassword(newPass);
                break;
            }
        }

        FilesHelper::clearFile("Clients.txt", "ClientLastId.txt");
        for (Client& c : clients) {
            FilesHelper::saveClient(c);
        }

        cout << "Password updated successfully!\n";
    }

    static Client* login(int id, string password) {
        vector<Client> clients = FilesHelper::getClients();
        for (Client& c : clients) {
            if (c.getId() == id && c.getPassword() == password) {
                return new Client(c);
            }
        }
        return nullptr;
    }

    static bool clientOptions(Client* client) {
        int choice;
        do {
            system("cls");
            printClientMenu();
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
            case 1: {
                system("cls");
                double amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\nInvalid amount!\n";
                    system("pause");
                    break;
                }

                client->deposit(amount);

                vector<Client> clients = FilesHelper::getClients();
                for (Client& c : clients) {
                    if (c.getId() == client->getId()) {
                        c.setBalance(client->getBalance());
                        break;
                    }
                }
                FilesHelper::clearFile("Clients.txt", "ClientLastId.txt");
                for (Client& c : clients) {
                    FilesHelper::saveClient(c);
                }
                system("pause");
                break;
            }
            case 2: {
                system("cls"); 
                double amount;
                cout << "Enter amount to withdraw: ";
                cin >> amount;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\nInvalid amount!\n";
                    system("pause");
                    break;
                }

                client->withdraw(amount);

                vector<Client> clients = FilesHelper::getClients();
                for (Client& c : clients) {
                    if (c.getId() == client->getId()) {
                        c.setBalance(client->getBalance());
                        break;
                    }
                }
                FilesHelper::clearFile("Clients.txt", "ClientLastId.txt");
                for (Client& c : clients) {
                    FilesHelper::saveClient(c);
                }
                system("pause");
                break;
            }
            case 3: {
                system("cls");
                int id;
                double amount;
                cout << "Enter recipient ID: ";
                cin >> id;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\nInvalid ID!\n";
                    system("pause");
                    break;
                }

                vector<Client> clients = FilesHelper::getClients();
                Client* recipient = nullptr;
                for (Client& c : clients) {
                    if (c.getId() == id) {
                        recipient = &c;
                        break;
                    }
                }

                if (recipient) {
                    cout << "Enter amount to transfer: ";
                    cin >> amount;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "\nInvalid amount!\n";
                        system("pause");
                        break;
                    }

                    client->transferTo(amount, *recipient);

                    FilesHelper::clearFile("Clients.txt", "ClientLastId.txt");
                    for (Client& c : clients) {
                        FilesHelper::saveClient(c);
                    }
                }
                else {
                    cout << "\nRecipient not found!\n";
                }
                system("pause");
                break;
            }
            case 4: {
                system("cls"); 
                client->checkBalance();
                system("pause");
                break;
            }
            case 5: {
                system("cls"); 
                updatePassword(client);
                system("pause");
                break;
            }
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
