// Struct Company Registration

struct CompanyRegistration {
    char companyCode[6];
    char companyName[51];
    char userAdmin[16];
    char passwordAdmin[11];
    int levelAccess;
    int userQuantity;
};

typedef struct CompanyRegistration CompanyRegistration;

struct CreateFlight {
    int flightID;
    char flightNumber[6];
    char origin[50];
    char destination[50];
    char departureDate[12];
    char departureTime[7];
    char arrivalDate[12];
    char arrivalTime[7];
    int totalSeats;
};

typedef struct CreateFlight CreateFlight;