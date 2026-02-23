# Data Format - Airline Check-in System

All data files use the `.dat` format with **`;`** (semicolon) delimiter.

> **Why semicolon?** Allows composite city names (e.g., "São Paulo", "Rio de Janeiro")

---

## 1. DataFlights.dat

**Location:** `data/Company Users/DataFlights.dat`

**Description:** List of all available flights in the system

### Format:
```
id;companyCode;flightNumber;origin;depDate;depTime;destination;arrDate;arrTime;totalSeats;occupiedSeats
```

**⚠️ Important Note:**
- **companyCode**: Always **3 characters only** (e.g., TST for Test, AZU, TAP)
- **flightNumber**: Unique identifier for the flight, often includes company code (e.g., TST1234)

This separation allows multiple flights per company with different identifiers.

### Fields:
| Field | Type | Size | Description |
|-------|------|------|-------------|
| `id` | int | 4 bytes | Unique flight identifier |
| `companyCode` | string | 3 chars | Airline code (e.g., TST for Test) |
| `flightNumber` | string | up to 20 chars | Flight number (e.g., TST1234) |
| `origin` | string | up to 50 chars | Origin city (allows spaces) |
| `depDate` | string | 10 chars | Departure date (format: DD/MM/YYYY) |
| `depTime` | string | 5 chars | Departure time (format: HH:MM) |
| `destination` | string | up to 50 chars | Destination city (allows spaces) |
| `arrDate` | string | 10 chars | Arrival date (format: DD/MM/YYYY) |
| `arrTime` | string | 5 chars | Arrival time (format: HH:MM) |
| `totalSeats` | int | 4 bytes | Total number of seats |
| `occupiedSeats` | int | 4 bytes | Number of occupied seats |

### Examples:
```
1;TST;TST1234;Cuiaba;10/02/2026;02:00;Guarulhos;10/02/2026;05:15;136;130
2;TST;TST5001;São Paulo;22/02/2026;10:30;Rio de Janeiro;22/02/2026;12:15;180;175
3;TST;TST5002;Porto Alegre;23/02/2026;14:00;São Paulo;23/02/2026;15:45;160;145
```

---

## 2. clients.dat

**Location:** `data/Data Clients/clients.dat`

**Description:** Registry of client users registered in the system

### Format:
```
username;password;fullName;email;cpf
```

### Fields:
| Field | Type | Size | Description |
|-------|------|------|-------------|
| `username` | string | up to 30 chars | Unique username |
| `password` | string | up to 30 chars | Password (preferably hash) |
| `fullName` | string | up to 100 chars | Client's full name |
| `email` | string | up to 50 chars | Client's email |
| `cpf` | string | 11 chars | CPF without formatting |

### Example:
```
alice_smith;alice123;Alice Smith;alice.smith@example.com;12345678901
bob_jones;bob_pass;Bob Jones;bob.jones@example.com;98765432100
```

---

## 3. CompanyUsers.dat

**Location:** `data/Company Users/CompanyUsers.dat`

**Description:** Administrative users of the airline company

### Format:
```
userId;companyCode;username;password
```

**⚠️ Important Note:**
- **companyCode**: Always **3 characters only** (e.g., TST for Test)

### Fields:
| Field | Type | Size | Description |
|-------|------|------|-------------|
| `userId` | int | 4 bytes | Unique user identifier |
| `companyCode` | string | 3 chars | Company code (e.g., TST for Test) |
| `username` | string | up to 30 chars | Username |
| `password` | string | up to 30 chars | Password |

### Example:
```
1;TST;admin;admin123
2;TST;admin_secondary;admin456
```

---

## 4. Bookings.dat

**Location:** `data/Data Clients/Bookings.dat`

**Description:** Flight reservations made by clients

### Format:
```
flightNumber;clientName;cpf;seats;checkedIn
```

### Fields:
| Field | Type | Size | Description |
|-------|------|------|-------------|
| `flightNumber` | string | up to 20 chars | Flight number |
| `clientName` | string | up to 100 chars | Client's name |
| `cpf` | string | 11 chars | Client's CPF |
| `seats` | int | 4 bytes | Number of reserved seats |
| `checkedIn` | int | 1 byte | Status (0=pending, 1=completed) |

### Example:
```
TST1234;Alice Smith;12345678901;2;0
TST5001;Bob Jones;98765432100;1;1
```

---

## Format Rules

### ✅ Required:
- Delimiter: **`;`** (semicolon)
- One line per record
- Line break at end of each line (`\n`)
- Fields in correct order
- No whitespace at field boundaries

### ✅ Allowed:
- Spaces **inside** names (e.g., "São Paulo")
- Accents (ã, é, ó, etc.)
- Numbers in strings when appropriate

### ❌ Not Allowed:
- Delimiter `;` inside values
- Line breaks inside fields
- Missing fields
- Wrong field order

---

## How to Add Data Manually

### Add a new flight:

**Linux/macOS:**
```bash
# Open DataFlights.dat in an editor
nano data/Company\ Users/DataFlights.dat

# Add a line in the correct format:
# Format: id;companyCode(3 chars);flightNumber;origin;depDate;depTime;destination;arrDate;arrTime;totalSeats;occupiedSeats
4;TST;TST6789;São Paulo;01/03/2026;10:00;Brasília;01/03/2026;12:00;200;0

# Save: Ctrl+O, Enter, Ctrl+X
```

**Windows:**
```cmd
# Open DataFlights.dat in a text editor
notepad "data\Company Users\DataFlights.dat"

# Add a line in the correct format:
4;TST;TST6789;São Paulo;01/03/2026;10:00;Brasília;01/03/2026;12:00;200;0

# Save: Ctrl+S
```

### Add a new client:

**Linux/macOS:**
```bash
# Open clients.dat
nano data/Data\ Clients/clients.dat

# Add:
carol_white;carol_pass;Carol White;carol.white@example.com;55555555555
```

**Windows:**
```cmd
# Open clients.dat
notepad "data\Data Clients\clients.dat"

# Add:
carol_white;carol_pass;Carol White;carol.white@example.com;55555555555
```

---

## Data Validation

### When read, the program validates:
- ✅ Date format (DD/MM/YYYY)
- ✅ Time format (HH:MM)
- ✅ CPF (11 digits)
- ✅ Numeric values for integer fields

### Example of reading (fscanf):
```c
fscanf(file, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%d;%d",
       &id, companyCode, flightNumber, origin, depDate, depTime,
       destination, arrDate, arrTime, &totalSeats, &occupiedSeats);
```

---

## Backup and Recovery

### Create backup:

**Linux/macOS:**
```bash
cp data/Company\ Users/DataFlights.dat data/Company\ Users/DataFlights.dat.backup
cp data/Data\ Clients/clients.dat data/Data\ Clients/clients.dat.backup
```

**Windows (CMD):**
```cmd
copy "data\Company Users\DataFlights.dat" "data\Company Users\DataFlights.dat.backup"
copy "data\Data Clients\clients.dat" "data\Data Clients\clients.dat.backup"
```

### Restore backup:

**Linux/macOS:**
```bash
cp data/Company\ Users/DataFlights.dat.backup data/Company\ Users/DataFlights.dat
```

**Windows (CMD):**
```cmd
copy "data\Company Users\DataFlights.dat.backup" "data\Company Users\DataFlights.dat"
```

---

## Recommended Folder Structure

```
data/
├── Company Users/
│   ├── DataFlights.dat          # Flights
│   ├── DataFlights.dat.backup   # Backup
│   ├── CompanyUsers.dat         # Company users
│   └── README.md                # Documentation
├── Data Clients/
│   ├── clients.dat              # Clients
│   ├── Bookings.dat             # Reservations
│   ├── clients.dat.backup       # Backup
│   └── README.md                # Documentation
└── README.md                    # General documentation
```

---

## Performance Tips

- ✅ Keep files in UTF-8 encoding
- ✅ Use `;` delimiter (never use space or comma)
- ✅ Don't add blank lines
- ✅ Keep backups regularly
- ✅ Validate before using critical data
