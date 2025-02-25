# Bank Management System

A console-based C++ application for managing bank clients and transactions. Supports CRUD operations, deposits, withdrawals, and balance reporting. Data is stored in a text file with delimiter-separated values.

---

## Features ✨  
- **Client Management**:  
  - Add/Delete clients with unique account numbers.  
  - Update client info (PIN, name, phone, balance).  
  - Search clients by account number.  
- **Transactions**:  
  - Deposit funds with confirmation.  
  - Withdraw funds (validates sufficient balance).  
  - View total balances across all accounts.  
- **Data Persistence**: Auto-saves to `ClientData.txt`.  
- **Input Validation**: Robust handling for numbers, strings, and negative amounts.  

---

## Author 👤  
**Hicham Bourezi**  
- GitHub: [@Dragonkuro2](https://github.com/dragonkuro2)  
- Email: Hicham.bourezi@gmail.com

---

## Prerequisites 📋  
- C++ compiler (g++, MinGW, or Visual Studio).  
- Command-line/terminal basics.  

---

## Installation & Usage 🚀  
### 1. Compile the Code  
```bash  
g++ BankApplication.cpp -o BankApp  
```  

### 2. Run the Executable  
```bash  
./BankApp    # Linux/macOS  
BankApp.exe  # Windows  
```  

---

## Menu System 📌  
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
[7] Exit  
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

---

## File Structure 📂  
- **`BankApplication.cpp`**: Main source code.  
- **`ClientData.txt`**: Auto-generated data file (format: `AccountNumber#//#PinCode#//#Name#//#Phone#//#Balance`).  

⚠️ **Do NOT edit `ClientData.txt` manually** to avoid corruption.  

---

## Example Workflows 💼  

### Add a Client:  
```  
-----------------------------------------------------------  
        Add New Client Screen:  
-----------------------------------------------------------  
Enter Account Number: AC456  
Enter Pin Code: 8899  
Enter client name: Sarah Wilson  
Enter Phone Number: 555-1234  
Enter balance: 5000.00  
```  

### Deposit Funds:  
```  
-----------------------------------------------------------  
                Deposit Screen:  
-----------------------------------------------------------  
Enter Account Number: AC456  
The following are the client details:  
-----------------------------------------------------------  
Account Number: AC456  
Pin Code      : 8899  
Client name   : Sarah Wilson  
Phone         : 555-1234  
Balance       : 5000.00  
-----------------------------------------------------------  
Enter deposit amount: 300.75  
Are you SURE you want to perform this transaction [0]:No [1]:Yes : 1  
Transaction Done.  
```  

### Withdraw Funds:  
```  
-----------------------------------------------------------  
                Withdraw Screen:  
-----------------------------------------------------------  
Enter Account Number: AC456  
The following are the client details:  
-----------------------------------------------------------  
Account Number: AC456  
Pin Code      : 8899  
Client name   : Sarah Wilson  
Phone         : 555-1234  
Balance       : 5300.75  
-----------------------------------------------------------  
Enter withdraw amount: 200.00  
Are you SURE you want to perform this transaction [0]:No [1]:Yes : 1  
Transaction Done.  
```  

---

## Key Improvements 🛠️  
- **Decimal Handling**: Balances display as `5000.00` (not scientific notation).  
- **Validation**:  
  - Rejects negative amounts.  
  - Blocks over-withdrawals.  
- **UI Polish**: Clean menus and confirmation prompts.  

---

## Notes ⚠️  
- **Platform Dependency**: Uses `system("cls")` (Windows). For Linux/macOS:  
  ```cpp  
  cout << "\033[2J\033[1;1H"; // Clear screen  
  ```  
- **Fictional Data**: All examples (Sarah Wilson, AC456) are for demonstration.  

---

## License 📄  
MIT License - Free for learning and modification. Commercial use permitted with attribution.  
