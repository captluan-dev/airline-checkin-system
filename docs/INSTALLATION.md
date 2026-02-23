# Installation and Compilation

## Prerequisites

- GCC (C Compiler) installed
- Make (build manager)
- Git (optional, for version control)

### Linux (Ubuntu/Debian)
```bash
sudo apt-get install build-essential gcc make
```

### macOS
```bash
xcode-select --install
```

### Windows (MinGW)
Install MinGW or GCC via MSYS2 or use WSL

---

## ⚠️ Platform-Specific Notes

This project uses Unix-style paths and commands. Here are the differences:

| Item | Linux/macOS | Windows (CMD/PowerShell) |
|------|-------------|--------------------------|
| **Path separator** | `/` | `\` |
| **List files** | `ls -la data/` | `dir data` |
| **Run executables** | `./bin/company` | `bin\company.exe` or `.\bin\company.exe` |
| **Edit files** | `nano file.txt` | `notepad file.txt` or use your editor |
| **Change directory** | `cd src/client/` | `cd src\client` |
| **View file content** | `cat file.txt` | `type file.txt` |

### Key Differences:
- **WSL (Windows Subsystem for Linux)**: If using WSL, use Unix-style paths and commands (recommended)
- **CMD (Command Prompt)**: Use backslashes for paths and Windows commands
- **PowerShell**: Works with both Unix and Windows style paths, more flexible
- **MSYS2**: Provides a Unix-like environment on Windows

If using **WSL**, you can follow Linux commands directly. Otherwise, adjust paths and commands accordingly.

---

## ℹ️ Code Portability

### Cross-Platform Console Handling
This codebase uses **`getchar()`** for console input pauses, which is **portable across all platforms**:

```c
// This works on Linux, macOS, and Windows
printf("Press Enter to continue...\n");
getchar();  // ✅ Portable - Works everywhere
```

**Not used in this project:**
- ❌ `system("pause")` - Windows-only
- ❌ Platform-specific system calls

This design choice ensures the code compiles and runs identically on:
- ✅ Linux
- ✅ macOS  
- ✅ Windows (CMD, PowerShell, or WSL)

No code modifications are needed when switching between platforms!

---

## Compilation

### Option 1: Using Makefile (Recommended)

```bash
# Clone the repository
git clone https://github.com/seu-usuario/airline-checkin-system.git
cd airline-checkin-system

# Compile everything
make

# Executables will be placed in bin/
ls -la bin/
```

### Option 2: Manual Compilation

```bash
# Compile only the server
gcc -Wall -Iinclude -std=c99 src/company/*.c -o bin/company

# Compile only the client
gcc -Wall -Iinclude -std=c99 src/client/*.c -o bin/client
```

---

## Directory Structure After Compilation

```
airline-checkin-system/
├── bin/
│   ├── company        ✅ Server executable
│   └── client         ✅ Client executable
├── build/             (intermediaries - auto-generated)
│   └── obj/
├── data/              📁 Database
│   ├── Company Users/
│   │   ├── DataFlights.dat
│   │   └── CompanyUsers.dat
│   └── Data Clients/
│       ├── clients.dat
│       └── Bookings.dat
├── docs/              📖 Documentation
├── src/               📝 Source code
├── include/           🔗 Headers
├── tests/             🧪 Tests
├── Makefile
├── README.md
└── .gitignore
```

---

## Useful Commands

### Compile
```bash
make              # Compile everything
make rebuild      # Clean and recompile
```

### Cleanup
```bash
make clean        # Remove build/
```

### Tests
```bash
make test         # Run available tests
```

### Information
```bash
make help         # Show all options
make info         # Build information
```

---

## Execution

### Server (Company)

**Linux/macOS:**
```bash
./bin/company
```

**Windows (CMD):**
```cmd
bin\company.exe
```

**Windows (PowerShell):**
```powershell
.\bin\company.exe
```

**Default Credentials:**
- Username: `admin`
- Password: `admin123`
- Company Code: `TST`

### Client

**Linux/macOS:**
```bash
./bin/client
```

**Windows (CMD):**
```cmd
bin\client.exe
```

**Windows (PowerShell):**
```powershell
.\bin\client.exe
```

**Available Test Client:**
- Username: `usertest`
- Password: `test123`


---

## Data Structure

### File: `DataFlights.dat`
Contains list of available flights with `;` delimiter. Note: companyCode is 3 characters only (e.g., TST)

```
id;companyCode(3 chars);flightNumber;origin;depDate;depTime;dest;arrDate;arrTime;totalSeats;occupiedSeats
1;TST;TST1234;Cuiaba;10/02/2026;02:00;Guarulhos;10/02/2026;05:15;136;130
```

### File: `clients.dat`
Contains registered client data

```
username;password;fullName;email;cpf
usertest;test123;User Test;usertest123@gmail.com;12345678910
```

### File: `Bookings.dat`
Contains flight reservations made by clients

```
flightNumber;clientName;cpf;seats;checkedIn
TST1234;User Test;12345678910;2;0
```

---

## Troubleshooting

### Error: `gcc: command not found`
**Solution:** Install GCC following the prerequisites steps

### Error: `make: command not found`
**Solution:** Install Make
```bash
# Ubuntu/Debian
sudo apt-get install make

# macOS
brew install make

# Windows (MinGW)
mingw-get install mingw32-make
```

### Error: Data files not found
**Solution:** Make sure you are in the correct folder

**Linux/macOS:**
```bash
cd airline-checkin-system/
ls -la data/
```

**Windows (CMD):**
```cmd
cd airline-checkin-system
dir data
```

**Windows (PowerShell):**
```powershell
cd airline-checkin-system
ls -la data/
```

### Compilation with warnings
**Information:** Warnings are normal and can be ignored. The program will work correctly.

---

## Next Steps

1. Read [docs/DATA_FORMAT.md](DATA_FORMAT.md) for details on file formats
2. Run `make test` to validate the installation
3. Check [README.md](../README.md) for project overview
