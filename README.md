
# 🔐 Secure Authentication System in C++

A secure and extensible authentication system built in C++ using Object-Oriented Programming principles. It implements password hashing with unique salt per user using SHA-256 and ensures persistent user data storage via CSV files.

---

## ✨ Features

- ✅ Secure password hashing (SHA-256) with unique salt  
- ✅ User registration with validation rules  
- ✅ User login and password verification  
- ✅ Persistent CSV-based data storage  
- ✅ Clean OOP structure with interfaces and implementations

---

## 🧩 Class Structure

- **IHasher** – Interface for hashing and salt generation  
  - `SHA256Hasher` – SHA-256 implementation with OpenSSL or similar

- **IValidator** – Interface for input validation  
  - `UserValidator` – Validates username and password formats

- **User** – Data class representing a user (username, hashed password, salt)

- **IUserRepository** – Interface for data storage  
  - `FileUserRepository` – CSV file implementation

- **AuthService** – Core logic for registration and authentication

---

## ✅ Validation Rules

- **Username**:
  - Minimum 3 characters  
  - Alphanumeric only  

- **Password**:
  - Minimum 8 characters  
  - At least one uppercase letter  
  - At least one lowercase letter  
  - At least one digit  

---

## 🔧 Building and Running

### 🔹 Using g++ (MinGW or Linux)

```bash
g++ -std=c++17 main.cpp SHA256Hasher.cpp UserValidator.cpp User.cpp FileUserRepository.cpp AuthService.cpp -o auth_system.exe
./auth_system.exe
```

### 🔹 Using Visual Studio

1. Create a C++ Console Application project  
2. Add all `.h` and `.cpp` files  
3. Build and run (F5)

---

## 💻 Usage

The app provides a simple CLI interface:

```
1. Register
2. Login
3. Exit
```

---

## 🔐 Security Features

- **Password Hashing**: Uses SHA-256 with salt  
- **Salt Generation**: Unique salt per user to prevent rainbow table attacks  
- **Strict Validation**: Enforces strong credentials  
- **No Plaintext Storage**: Only hashed values stored  

---

## 🗂️ File Format

User data is stored in `users.csv` in the format:

```
username,hashedPassword,salt
```

---

## 🧠 OOP Concepts

- **Abstraction** – Defined behavior using interfaces  
- **Encapsulation** – Secure and isolated data  
- **Inheritance** – Concrete classes from abstract interfaces  
- **Polymorphism** – Interchangeable components  
- **Dependency Injection** – Services injected via constructors  

---

## 🧱 SOLID Principles

- **S** – Single Responsibility (each class = one task)  
- **O** – Open/Closed (extendible without modifying base code)  
- **L** – Liskov Substitution (implementations can replace interfaces)  
- **I** – Interface Segregation (small, focused interfaces)  
- **D** – Dependency Inversion (high-level modules don’t depend on low-level ones)

---

## 📁 Project Structure

```
OOP_project/
├── IHasher.h
├── SHA256Hasher.h / .cpp
├── IValidator.h
├── UserValidator.h / .cpp
├── User.h / .cpp
├── IUserRepository.h
├── FileUserRepository.h / .cpp
├── AuthService.h / .cpp
├── main.cpp
└── README.md
```

---

## 🔄 Authentication Flow

### 📝 Registration
1. Validate input  
2. Check if username already exists  
3. Generate salt and hash password  
4. Store in CSV

### 🔐 Login
1. Find user by username  
2. Hash entered password with stored salt  
3. Compare with stored hash  
4. Authenticate if match

---

## 🙌 Acknowledgments

This project was developed as part of an Object-Oriented Programming course to practice security and design patterns in C++.
