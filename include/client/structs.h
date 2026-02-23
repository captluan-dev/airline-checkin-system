struct Client {
    char username[50];
    char password[50];
    char fullName[100];
    char email[100];
    char phoneNumber[15];
};

typedef struct Client Client;

struct Flight {
    int flightID;
    char flightNumber[6];
    char origin[50];
    char destination[50];
    char departureDate[12];
    char departureTime[7];
    char arrivalDate[12];
    char arrivalTime[7];
    int totalSeats;
    int occupiedSeats;
};

typedef struct Flight Flight;

struct Booking {
    int bookingID;
    char flightNumber[6];
    char passengerName[51];
    char cpf[15];
    int seatsBooked;
    char bookingDate[12];
    int checkedIn;
};

typedef struct Booking Booking;