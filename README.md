Here's the complete Markdown code for your README.md file:

```markdown
# OOP_project

A secure authentication system in C++ that hashes passwords with a salt using SHA-256. It supports user registration, login, and password verification. User data (username, hashed password, and salt) is stored in a CSV file for persistence.

## Features

- Secure password hashing with salt using SHA-256
- User registration with validation
- User authentication
- Persistent storage using CSV files
- Object-oriented design with interfaces and implementations

## Class Structure

- **IHasher**: Interface for password hashing and salt generation
  - **SHA256Hasher**: Implementation using SHA-256 algorithm

- **IValidator**: Interface for input validation
  - **UserValidator**: Implementation with username and password validation rules

- **User**: Data class for user information

- **IUserRepository**: Interface for user data storage
  - **FileUserRepository**: Implementation using CSV file storage

- **AuthService**: Main service that coordinates authentication operations

## Validation Rules

- Username: At least 3 characters, alphanumeric only
- Password: At least 8 characters, must contain uppercase, lowercase, and digits

## Building and Running

### Using g++ (MinGW)

Compile all .cpp files together:

```bash
g++ -std=c++17 main.cpp SHA256Hasher.cpp UserValidator.cpp User.cpp FileUserRepository.cpp AuthService.cpp -o auth_system.exe
```

Run the executable:

```shellscript
.\auth_system.exe
```

### Using Visual Studio

1. Create a new C++ Console Application project
2. Add all .h and .cpp files to the project
3. Build and run the project (F5)


## Usage

The application provides a simple command-line interface with the following options:

1. **Register**: Create a new user account
2. **Login**: Authenticate with existing credentials
3. **Exit**: Close the application


## Security Implementation

- **Password Hashing**: Passwords are never stored in plain text
- **Salt Generation**: Each user has a unique salt to prevent rainbow table attacks
- **Input Validation**: Strict rules for usernames and passwords


## File Format

User data is stored in a CSV file with the following format:

```plaintext
username,hashedPassword,salt
```

## OOP Concepts Demonstrated

- **Abstraction**: Interfaces define behavior without implementation details
- **Encapsulation**: Data and methods are encapsulated within classes
- **Inheritance**: Implementation classes inherit from interfaces
- **Polymorphism**: Different implementations can be used interchangeably
- **Dependency Injection**: Components receive their dependencies through constructors


## SOLID Principles Applied

1. **Single Responsibility Principle**: Each class has a single responsibility
2. **Open/Closed Principle**: Classes are open for extension but closed for modification
3. **Liskov Substitution Principle**: Implementations can be substituted for their interfaces
4. **Interface Segregation Principle**: Specific interfaces rather than general ones
5. **Dependency Inversion Principle**: Depend on abstractions, not concrete implementations


## Project Structure

```plaintext
OOP_project/
├── IHasher.h
├── SHA256Hasher.h
├── SHA256Hasher.cpp
├── IValidator.h
├── UserValidator.h
├── UserValidator.cpp
├── User.h
├── User.cpp
├── IUserRepository.h
├── FileUserRepository.h
├── FileUserRepository.cpp
├── AuthService.h
├── AuthService.cpp
├── main.cpp
└── README.md
```

## Authentication Flow

1. **User Registration**:

1. Validate input (username and password)
2. Check if username already exists
3. Generate salt and hash password
4. Save user data to CSV file



2. **User Login**:

1. Find user by username
2. Hash provided password with stored salt
3. Compare with stored hash
4. Grant access if hashes match



## Acknowledgments

- This project was created as part of an Object-Oriented Programming course
