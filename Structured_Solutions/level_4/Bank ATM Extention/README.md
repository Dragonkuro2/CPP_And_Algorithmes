# ATM Application

## 📌 Project Description

The **ATM Application** is an extension of the Bank Management System, providing a console-based interface for clients to perform banking transactions such as withdrawals, deposits, and balance inquiries. The application reads client data from a file and ensures secure authentication before granting access to banking operations.

## 🎯 Features ✨

- **Authentication**: Clients log in using their account number and PIN.
- **Quick Withdraw**: Predefined withdrawal amounts for faster transactions.
- **Normal Withdraw**: Allows users to specify a custom withdrawal amount (must be a multiple of 5).
- **Deposit Funds**: Clients can add money to their account.
- **Check Balance**: Displays the current account balance.
- **Data Persistence**: All transactions update `ClientData.txt` in real time.
- **Input Validation**: Ensures only valid inputs are accepted.

## 🛠️ Technologies Used

- **C++** (Standard Library)
- **File Handling** (fstream for reading/writing data)
- **Structs & Enums** (for managing client data and menu options)

## 📂 Project Structure 📌

```
ATM.cpp              # ATM application source code
ClientData.txt       # Stores client account records
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
g++ -o ATM ATM.cpp
./ATM
```

#### Using MSVC (Windows):

```sh
cl ATM.cpp
ATM.exe
```

## 🔑 User Authentication

- Clients must enter their **account number** and **PIN code** to access their account.
- Credentials are verified against `ClientData.txt`.
- If authentication fails, the user is prompted to try again.

## 📌 Menu Navigation

### ATM Main Menu:

```
===================================================
        ATM Main Menu Screen:
===================================================
[1] Quick Withdraw
[2] Normal Withdraw
[3] Deposit
[4] Check Balance
[5] Logout
===================================================
```

### Quick Withdraw Options:

```
===================================================
        Quick Withdraw Screen:
===================================================
[1] 20      [2] 50
[3] 100     [4] 200
[5] 400     [6] 600
[7] 800     [8] 1000
[9] Exit
===================================================
```

## 🏦 How Transactions Work

- **Withdrawals**: Users can withdraw funds if they have sufficient balance.
- **Deposits**: Users can deposit any positive amount.
- **Balance Inquiry**: Displays the current account balance.
- **Logout**: Returns to the login screen.

## ⚠️ Known Issues & Limitations

- PIN codes and account numbers are stored in plain text.
- The program uses `system("cls")`, which may not work on all operating systems.
- Transactions update the file but do not use database transactions (could lead to corruption in case of an error).

## 💡 Future Improvements 🛠️

- Implement **encryption** for stored PIN codes.
- Replace text file storage with a **database** for better reliability.
- Enhance the UI with **a graphical interface**.
- Add a **receipt printing option** for transactions.

## 👨‍💻 Author

**[Hicham Bourezi]**\
If you have any suggestions or issues, feel free to reach out!

## 📜 License

This project is open-source. You can modify and distribute it freely.


