# Airline Check-in System (C)

A personal project written in C that simulates an airline check-in system. The goal is to practice software design, file handling, modular programming, and system organization using the C language.

**Status:** ✅ Completed

### ⚠️ Platform Note
This project was developed on **Linux**. If you're using **Windows**, please refer to the platform-specific instructions in:
- [INSTALLATION.md](docs/INSTALLATION.md) - Compilation and setup guide
- [DATA_FORMAT.md](docs/DATA_FORMAT.md) - Data files and file management

These documents contain detailed instructions for Windows users (CMD/PowerShell).

---

## 📋 Project Overview

This project implements a comprehensive airline check-in system with two main components:
- **Company (Admin)**: Airline management and flight operations
- **Client (Passenger)**: Passenger check-in and flight information

---

## 🚀 Current Features

### Company (Admin) Side
- Authentication system (login/registration) using file-based storage
- Company registration with persistent data storage
- Admin menu structure after successful login
- Flight management interface (in development)
- Modular code organization using `.c` and `.h` files

### Client (Passenger) Side
- Passenger interface structure (framework in place)
- Menu navigation system (in development)
- User authentication framework

---

## 📦 Project Structure

```
airline-checkin-system/
├── bin/                    # Compiled executables
│   ├── company            # Admin/company application
│   └── client             # Passenger application
├── src/                   # Source code
│   ├── company/           # Company-side implementation
│   └── client/            # Client-side implementation
├── include/               # Header files
│   ├── company/           # Company headers
│   └── client/            # Client headers
├── build/                 # Build artifacts (generated)
├── tests/                 # Test suite
│   ├── unit/             # Unit tests
│   ├── integration/      # Integration tests
│   └── data/             # Test data
├── docs/                 # Documentation
└── Makefile              # Build configuration
```

---

## 🔧 Compilation

### Requirements
- GCC compiler
- Make utility
- Standard C99 library

### Build Commands

```bash
# Compile both executables (company and client)
make

# Clean build artifacts
make clean

# Full rebuild (clean + compile)
make rebuild

# Run tests
make test

# Show all available commands
make help
```

### Manual Compilation (if needed)
```bash
gcc -o -Iinclude src/company/*.c -o bin/company
gcc -o -Iinclude src/client/*.c -o bin/client
```

---

## ▶️ Running the Applications

### Company (Admin)
```bash
./bin/company
```

### Client (Passenger)
```bash
./bin/client
```

---

## 📚 Documentation

Additional documentation is available in the `docs/` directory:
- **INSTALLATION.md** - Installation and setup instructions
- **DATA_FORMAT.md** - Data format specifications
- **APPLIED_STANDARDIZATION.md** - Code standardization and project organization

---

## 💻 Technologies & Concepts

- **Language:** C
- **Data Structures:** Structs for organized data management
- **Code Organization:** Modular design with header files
- **User Interface:** Console-based menu system
- **Build System:** GNU Make
- **Version Control:** Git & GitHub
- **Cross-Platform:** Uses `getchar()` for portable console pauses (not `system("pause")`)

---

## 🔄 Cross-Platform Compatibility

### User Input Handling
This project uses **`getchar()`** for console pauses instead of `system("pause")`:
- ✅ **`getchar()`**: Works on **all platforms** (Linux, macOS, Windows)
- ❌ **`system("pause")`**: Windows-only, not portable

**Why `getchar()`?**
- Multiplataforma (cross-platform)
- Standard C library function
- Better coding practice
- Works consistently across all operating systems

### Code Example
```c
// Wait for user to press Enter
printf("Press Enter to continue...\n");
getchar();
```

This approach ensures the code runs identically on Linux, macOS, and Windows without modifications.

---

## 📝 Notes

- Some menu options are currently interface-only and will be fully implemented in upcoming updates
- Data is persisted in text files within the `data/` directory
- The project follows consistent coding standards and naming conventions (see APPLIED_STANDARDIZATION.md)
