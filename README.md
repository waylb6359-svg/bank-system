🏦 ROUTE Egyptian Bank System
Overview
A comprehensive banking system simulation built in C++ that manages clients, employees, and administrators with different access levels.
The system uses text files for persistent data storage and provides a user-friendly console interface.

✨ Features
🔐 Multi-Level Login System
Client: Personal account management
Employee: Client management capabilities
Admin: Full system management (clients, employees, other admins)
💼 Account Management
Automatic ID generation (no manual ID entry)
Self-registration for Clients and Employees
Admin-only Admin account creation
First-time setup wizard for creating the first Admin
💰 Banking Operations
Deposit funds
Withdraw funds
Transfer money between clients
Check account balance
Change password
👥 User Management
Employee can
Add new clients
View all clients
Search for clients
Edit client information
Admin can
All Employee permissions
Add new employees
View all employees
Search for employees
Edit employee information
Add new admins
Clear all system data
🧱 System Structure
📁 Core Classes
Class	Description
Validation	Data validation (name, password, balance, salary)
Person	Base class (id, name, password)
Client	Client with balance and banking operations
Employee	Employee with salary and client management
Admin	Admin with full system management
📁 File Management Classes
Class	Description
FilesHelper	File read/write operations
Parser	Text to object conversion
DataSourceInterface	Abstract class for data source
FileManager	Implementation of DataSourceInterface
📁 User Management Classes
Class	Description
ClientManager	Client operations (deposit, withdraw, transfer)
EmployeeManager	Employee operations (client management)
AdminManager	Admin operations (employee/admin management)
EmployeeOperations	Helper functions for client operations
Screens	UI screens and menus management
📂 Data Files
File	Content
Clients.txt	Client data (ID, name, password, balance)
Employee.txt	Employee data (ID, name, password, salary)
Admin.txt	Admin data (ID, name, password, salary)
ClientLastId.txt	Last used Client ID
EmployeeLastId.txt	Last used Employee ID
AdminLastId.txt	Last used Admin ID
📋 Menus & Permissions
Main Menu
Login as Client

Login as Employee

Login as Admin

Create New Client Account

Create New Employee Account

Exit

Client Menu
Deposit

Withdraw

Transfer

Check Balance

Change Password

Logout

Employee Menu
Add New Client

List All Clients

Search for Client

Edit Client Info

Change Password

Logout

Admin Menu
Add New Client

List All Clients

Search for Client

Edit Client Info

Add New Employee

List All Employees

Search for Employee

Edit Employee Info

Add New Admin

Clear All Data

Change Password

Logout

🔑 Permissions Matrix
Operation	Client	Employee	Admin
Deposit / Withdraw / Transfer	✅	❌	❌
Check Balance	✅	❌	❌
Change Password	✅	✅	✅
Add New Client	❌	✅	✅
List All Clients	❌	✅	✅
Search Client	❌	✅	✅
Edit Client	❌	✅	✅
Add New Employee	❌	❌	✅
List All Employees	❌	❌	✅
Search Employee	❌	❌	✅
Edit Employee	❌	❌	✅
Add New Admin	❌	❌	✅
Clear All Data	❌	❌	✅
✔ Validation Rules
Field	Rule
Name	3-20 characters, alphabetic only
Password	8-20 characters, no spaces
Balance	Minimum 1500
Salary	Minimum 5000
🆔 ID System
First Admin: ID = 1 (First Time Setup)
First Client: ID = 1
First Employee: ID = 1
Next IDs: Last ID + 1
⚠️ Each user type has its own ID counter stored in separate files.

⚙ First Time Setup
When running the program for the first time:

First Time Setup screen appears automatically
Create the first Admin account (Name, Password, Salary)
System assigns ID = 1
Login with the new Admin credentials
Start adding Employees and Clients
💾 Data Storage Format
Each line in the text files contains comma-separated values.

Clients.txt
1,Ahmed,12345678,5000 2,Mohamed,12345678,3000

Employee.txt
1,Sara,12345678,7000 2,Khaled,12345678,8000

Admin.txt
1,Admin,12345678,10000

⚙ Technical Features
✅ Error Handling to prevent crashes
✅ Screen Clearing for clean interface
✅ Confirmation prompts before critical operations
✅ Code reuse using inheritance and polymorphism
✅ Separation of concerns (each class has one responsibility)
✅ Interface implementation using DataSourceInterface
✅ Persistent storage using text files
🖥 Requirements
C++ Compiler (C++11 or later)
Windows OS (for system("cls") and system("color"))
Visual Studio (recommended) or any C++ IDE
▶ How to Run
Clone the repository
Open the project in Visual Studio
Build the solution
Ctrl + Shift + B

Run the program
F5

Complete the First Time Setup
Start using the banking system
📁 File Structure
BankSystem │ ├── Validation.h ├── Person.h ├── Client.h ├── Employee.h ├── Admin.h ├── DataSourceInterface.h ├── FilesHelper.h ├── Parser.h ├── FileManager.h ├── EmployeeOperations.h ├── ClientManager.h ├── EmployeeManager.h ├── AdminManager.h ├── Screens.h └── main.cpp

👨‍💻 Author
Developed as a C++ final project for learning:

Object-Oriented Programming (OOP)
File Handling
Data Structures
📜 License
This project is open-source and available for educational purposes.
