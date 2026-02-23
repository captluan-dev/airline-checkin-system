#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "client/flightsClient.h"
#include "client/structs.h"

char* generateCheckInCode() {
    static char code[7];
    char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    srand(time(NULL) + rand());
    
    for (int i = 0; i < 6; i++) {
        code[i] = chars[rand() % 36];
    }
    code[6] = '\0';
    return code;
}

void viewFlights() {

    system("clear");

    printf("===============================\n");
    printf("       Available Flights       \n");
    printf("===============================\n");

    FILE *file = fopen("data/Company Users/DataFlights.dat", "r");

    if (file == NULL) {
        printf("Error: Could not open flight data\n");
        getchar();
        return;
    }

    char fCode[20], origin[50], dest[50], depDate[12], depTime[7], arrDate[12], arrTime[7];
    int code, seats, occupiedSeats;
    int found = 0;

    while (fscanf(file, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%d;%d", &code, fCode, origin, depDate, depTime, dest, arrDate, arrTime, &seats, &occupiedSeats) == 10) {
        
        found = 1;

        printf("-------------------------------\n");
        printf("        Flight %s\n", fCode);
        printf("-------------------------------\n");
        printf("[Origin]: %s\n", origin);
        printf("[Destination]: %s\n", dest);
        printf("[Departure Date]: %s\n", depDate);
        printf("[Departure Time]: %s\n", depTime);
        printf("[Arrival Date]: %s\n", arrDate);
        printf("[Arrival Time]: %s\n", arrTime);
        printf("[Occupied Seats]: %d\n", occupiedSeats);
        printf("-------------------------------\n\n");
    }

    if (!found) {
        printf("No flights available.\n");
        getchar();
    }

    fclose(file);
    printf("===============================\n");
    printf("Press Enter to continue...");
    getchar();
}

void bookFlight() {

    system("clear");

    char flightNumber[20], passengerName[51], cpf[15];
    int seatsToBook;

    printf("===============================\n");
    printf("         Book a Flight        \n");
    printf("===============================\n");

    printf("Flight Number: ");
    fgets(flightNumber, sizeof(flightNumber), stdin);
    removeNewLine(flightNumber);

    printf("Passenger Name: ");
    fgets(passengerName, sizeof(passengerName), stdin);
    removeNewLine(passengerName);

    printf("CPF/Document ID: ");
    fgets(cpf, sizeof(cpf), stdin);
    removeNewLine(cpf);

    seatsToBook = readInt("Number of Seats to Book: ");

    FILE *file = fopen("data/Company Users/DataFlights.dat", "r");

    if (file == NULL) {
        printf("Error: Could not open flights data.\n");
        getchar();
        return;
    }

    char fCode[20], origin[50], dest[50], depDate[12], depTime[7], arrDate[12], arrTime[7];
    int code, seats, occupiedSeats;
    int found = 0;

    while (fscanf(file, "%d %s %s %s %s %s %s %s %d %d", &code, fCode, origin, depDate, depTime, dest, arrDate, arrTime, &seats, &occupiedSeats) == 10) {

        if (strcmp(fCode, flightNumber) == 0) {
            found = 1;

            if (occupiedSeats + seatsToBook <= seats) {

                // Save booking to file
                FILE *bookingFile = fopen("data/Company Users/Bookings.dat", "a");
                if (bookingFile == NULL) {
                    printf("Error: Could not save booking.\n");
                    fclose(file);
                    getchar();
                    return;
                }

                fprintf(bookingFile, "%s;%s;%s;%d;0\n", flightNumber, passengerName, cpf, seatsToBook);
                fclose(bookingFile);

                printf("\n===============================\n");
                printf("       Booking Confirmed!       \n");
                printf("===============================\n");
                printf("Flight: %s\n", flightNumber);
                printf("Passenger: %s\n", passengerName);
                printf("CPF: %s\n", cpf);
                printf("Seats: %d\n", seatsToBook);
                printf("===============================\n");
                printf("Total available seats remaining: %d\n", seats - occupiedSeats - seatsToBook);
                printf("Press Enter to continue...");
                getchar();

            } else {
                int availableSeats = seats - occupiedSeats;
                printf("\n===============================\n");
                printf("       Booking Failed!          \n");
                printf("===============================\n");
                printf("Not enough available seats on flight %s.\n", flightNumber);
                printf("Available seats: %d\n", availableSeats);
                printf("Requested seats: %d\n", seatsToBook);
                printf("===============================\n");
                printf("Press Enter to continue...");
                getchar();
            }
            fclose(file);
            return;
        }
    }

    fclose(file);

    if (!found) {
        printf("\n===============================\n");
        printf("       Flight Not Found!        \n");
        printf("===============================\n");
        printf("Flight number '%s' not found in the system.\n", flightNumber);
        printf("Please check the flight number and try again.\n");
        printf("===============================\n");
        printf("Press Enter to continue...");
        getchar();
    }
}

void viewBookings() {

    system("clear");

    char cpf[15];

    printf("===============================\n");
    printf("        Your Bookings           \n");
    printf("===============================\n");

    printf("Enter your CPF/Document ID to view bookings: ");
    fgets(cpf, sizeof(cpf), stdin);
    removeNewLine(cpf);

    FILE *file = fopen("data/Company Users/Bookings.dat", "r");

    if (file == NULL) {
        printf("No bookings found.\n");
        printf("Press Enter to continue...");
        getchar();
        return;
    }

    char flightNumber[20], passengerName[51], fileCPF[15];
    int seatsBooked, checkedIn;
    int found = 0;

    while (fscanf(file, "%[^;];%[^;];%[^;];%d;%d", flightNumber, passengerName, fileCPF, &seatsBooked, &checkedIn) == 5) {
        
        if (strcmp(cpf, fileCPF) == 0) {
            found = 1;

            printf("-------------------------------\n");
            printf("Flight Number: %s\n", flightNumber);
            printf("Passenger Name: %s\n", passengerName);
            printf("Seats Booked: %d\n", seatsBooked);
            printf("Check-in Status: %s\n", checkedIn == 0 ? "Pending" : "Completed");
            printf("-------------------------------\n");
        }
    }

    if (!found) {
        printf("No bookings found for CPF: %s\n", cpf);
    }

    fclose(file);
    printf("===============================\n");
    printf("Press Enter to continue...");
    getchar();
}

void checkIn() {

    system("clear");

    char cpf[15], flightNumber[20];

    printf("===============================\n");
    printf("          Check-in             \n");
    printf("===============================\n");

    printf("Enter your CPF/Document ID: ");
    fgets(cpf, sizeof(cpf), stdin);
    removeNewLine(cpf);

    printf("Enter flight number: ");
    fgets(flightNumber, sizeof(flightNumber), stdin);
    removeNewLine(flightNumber);

    FILE *file = fopen("data/Company Users/Bookings.dat", "r");

    if (file == NULL) {
        printf("Error: Could not find bookings.\n");
        printf("Press Enter to continue...");
        getchar();
        return;
    }

    char fNumber[20], passengerName[51], fileCPF[15];
    int seatsBooked, checkedIn;
    int found = 0;

    while (fscanf(file, "%[^;];%[^;];%[^;];%d;%d", fNumber, passengerName, fileCPF, &seatsBooked, &checkedIn) == 5) {
        
        if (strcmp(cpf, fileCPF) == 0 && strcmp(flightNumber, fNumber) == 0) {
            found = 1;
            break;
        }
    }

    fclose(file);

    if (found) {
        if (checkedIn == 1) {
            printf("\n===============================");
            printf("\n   Check-in Already Done!      \n");
            printf("===============================");
            printf("\nFlight: %s\n", fNumber);
            printf("Passenger: %s\n", passengerName);
            printf("Your check-in was already completed.\n");
            printf("===============================");
        } else {
            char *checkInCode = generateCheckInCode();
            FILE *tempFile = fopen("data/Company Users/Bookings.tmp", "w");
            FILE *originalFile = fopen("data/Company Users/Bookings.dat", "r");
            
            char tmpFNumber[20], tmpName[51], tmpCPF[15];
            int tmpSeats, tmpCheckin;
            
            while (fscanf(originalFile, "%[^;];%[^;];%[^;];%d;%d", tmpFNumber, tmpName, tmpCPF, &tmpSeats, &tmpCheckin) == 5) {
                if (strcmp(tmpCPF, cpf) == 0 && strcmp(tmpFNumber, flightNumber) == 0) {
                    fprintf(tempFile, "%s;%s;%s;%d;1\n", tmpFNumber, tmpName, tmpCPF, tmpSeats);
                } else {
                    fprintf(tempFile, "%s;%s;%s;%d;%d\n", tmpFNumber, tmpName, tmpCPF, tmpSeats, tmpCheckin);
                }
            }
            
            fclose(originalFile);
            fclose(tempFile);
            remove("data/Company Users/Bookings.dat");
            rename("data/Company Users/Bookings.tmp", "data/Company Users/Bookings.dat");
            
            printf("\n===============================");
            printf("\n    Check-in Successful!       \n");
            printf("===============================");
            printf("\nFlight: %s\n", fNumber);
            printf("Passenger: %s\n", passengerName);
            printf("Seats: %d\n", seatsBooked);
            printf("Check-in Code: %s\n", checkInCode);
            printf("===============================");
            printf("\nYour check-in is confirmed. Have a good flight!\n");
        }
    } else {
        printf("\nNo booking found for this CPF and flight number.\n");
    }

    printf("Press Enter to continue...");
    getchar();
}