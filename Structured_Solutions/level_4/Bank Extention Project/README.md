# Bank Management System

## 📌 Project Description
The **Bank Management System** is a C++ console-based application that allows administrators to manage bank clients and users efficiently. It provides functionalities such as adding, deleting, updating, and searching for clients, as well as performing transactions like deposits and withdrawals.

## 🎯 Features ✨
- **Client Management**:
  - Add/Delete clients with unique account numbers.
  - Update client info (PIN, name, phone, balance).
  - Search clients by account number.
- **Transactions**:
  - Deposit funds with confirmation.
  - Withdraw funds (validates sufficient balance).
  - View total balances across all accounts.
- **User Management**:
  - Add, delete, and update users.
  - Assign permissions to users.
  - Manage user authentication.
- **File-based Data Storage**:
  - Clients and users are stored in `ClientData.txt` and `Userdata.txt`.
  - Data is persistent between program executions.
- **Input Validation**:
  - Handles invalid numeric inputs gracefully.

## 🛠️ Technologies Used
- **C++** (Standard Library)
- **File Handling** (fstream for reading/writing data)
- **Enums & Structs** (for managing options and user data)

## 📂 Project Structure 📌
```
BankProject.cpp      # Main project file
ClientData.txt       # Stores client records
Userdata.txt         # Stores user records
README.md           # Documentation file
```

## 🚀 Getting Started
### 1️⃣ Prerequisites
Ensure you have the following installed:
- **C++ Compiler** (GCC, MSVC, or Clang)
- **A terminal or IDE** (CodeBlocks, VS Code, Dev-C++, etc.)

### 2️⃣ How to Compile & Run
#### Using g++ (Linux/macOS/Windows with MinGW):
```sh
g++ -o BankSystem BankProject.cpp
./BankSystem
```
#### Using MSVC (Windows):
```sh
cl BankProject.cpp
BankProject.exe
```

## 🔑 User Authentication & Permissions
The initial login credentials are:
- **Username**: admin
- **Password**: password

The system includes user authentication with role-based permissions:
The system includes user authentication with role-based permissions:
- **Admin**: Full access to all features
- **Normal User**: Limited access based on assigned permissions

Permissions include:
- View client list
- Add, delete, update clients
- Perform transactions
- Manage users

## 📌 How to Use
1. **Login**: Enter a username and password.
2. **Main Menu**: Navigate through the menu using numbered options.
3. **Perform Operations**: Based on permissions, manage clients, perform transactions, or manage users.
4. **Logout**: Exit or switch users.

## 📌 Menu Navigation
### Main Menu:
```
================================================
        Main Menu Screen:
================================================
[1] Show Clients List
[2] Add New Client
[3] Delete Client
[4] Update Client Info
[5] Find Client
[6] Transactions
[7] Manage Users
[8] Logout
================================================
```

### Transactions Submenu:
```
================================================
      Transactions Menu Screen:
================================================
[1] Deposit
[2] Withdraw
[3] Total Balance
[4] Main Menu
================================================
```

## ⚠️ Known Issues & Limitations
- Passwords are stored in plain text (consider implementing encryption or hashing).
- The application uses `system("cls")`, which may not work on all operating systems.
- Searching for clients is `O(n)`; using `unordered_map` could improve performance.

## 💡 Future Improvements 🛠️
- Implement a **GUI** using Qt or a web-based frontend.
- Add **database support** (MySQL, SQLite) for better data management.
- Improve security by **hashing passwords** instead of storing them in plain text.

## 👨‍💻 Author
**Hicham Bourezi**  
- GitHub: [@Dragonkuro2](https://github.com/dragonkuro2)  
- Email: Hicham.bourezi@gmail.com  

## 📜 License
MIT License - Free for learning and modification. Commercial use permitted with attribution.
