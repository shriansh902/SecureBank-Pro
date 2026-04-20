SecureBank

SecureBank is a modular, file-based banking management system implemented in C. It simulates basic banking operations such as account creation, authentication, and transactions using persistent storage.

Project Overview

SecureBank is a console-based application that allows multiple users to manage their bank accounts. The system supports essential banking features like deposits, withdrawals, and money transfers while storing data securely using file handling and simple encryption techniques.

Problem Statement

To design and implement a secure and efficient console-based banking system using C programming, focusing on structured programming, file handling, and basic data security.

Key Features
Account creation with unique account number
Secure login using account number and PIN
Deposit and withdrawal with validation
Fund transfer between accounts
Balance inquiry
Update account details
Admin panel to view all accounts
Persistent data storage using files
Basic data encryption using XOR cipher
Technologies Used
C Programming Language
Structured Programming
File Handling (Text Files)
Basic Encryption (XOR Cipher)
Libraries Used
stdio.h
stdlib.h
string.h
time.h
windows.h
System Architecture

The system is divided into the following layers:

Presentation Layer (Console-based user interface)
Business Logic Layer (Core banking operations)
Data Layer (File-based storage system)
Module Division
Authentication & Security (Login, PIN validation)
Account Management (Create, update, view details)
Transaction System (Deposit, withdraw)
Fund Transfer System
File Storage & Encryption
Admin Panel
Data Storage

All account information is stored in a file (accounts.txt) and encrypted using a simple XOR-based encryption method.

Limitations
Uses basic XOR encryption (not suitable for real-world security)
No database integration
Single-user console interaction at a time
Future Improvements
Implement stronger encryption (e.g., hashing or AES)
Add account deletion feature
Introduce login attempt limits
Upgrade to GUI-based interface
Use database for better scalability
Development Plan

Week 1: Basic structure and UI
Week 2: File handling and account system
Week 3: Transaction features (deposit, withdraw, transfer)
Week 4: Admin panel and testing
Week 5: Optimization and documentation
