Airline Check-in System (C)

An academic project written in "C" that simulates an "airline check-in system".
The goal is to practice software design, file handling, modular programming,
and system organization using the C language.

This project is being developed entirely in English as a way to improve
technical English skills. A Portuguese version may be added in the future.

==================================================================================

Project Status

In development

At the moment, the project focuses on the company (admin) side of the system.
Passenger features will be implemented in future versions.

==================================================================================

Current Features (Company Side)

Initial interface with menu options:
	- Login
	- Register new airline company
	- Exit
Company login system using file-based authentication ('.txt')
Company registration with persistent data storage
Admin menu structure after successful login
Modular code organization using '.c' and '.h' files

> Note: Some menu options are currently interface-only and will be fully
implemented in upcoming updates.

==================================================================================

Planned Features

Company (Admin)
- Manage flights (create, edit, remove)
- View company data
- Improved menu navigation and screen handling

Passenger (Client)
- Passenger login and registration
- Flight search
- Check-in simulation
- Access to flight and company information

==================================================================================

Executables (Planned)

In future versions, the project will be split into two separate executables:
- 'company' → Airline/company management system
- 'client' → Passenger access and check-in system

==================================================================================

Technologies & Concepts

- Language: C
- File handling ('FILE*', read/write)
- Structs and modular design
- Header files and separation of concerns
- Console-based user interface
- Git & GitHub for version control

==================================================================================

Compilation

Example compilation using "gcc" in vscode:

"bash"
gcc -Iinclude src/*.c src/*.c src/*.c -o bin/admin
