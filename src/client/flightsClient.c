#include <stdio.h>
#include <stdlib.h>

void viewFlights() {

    system("clear");

    printf("===============================\n");
    printf("       Available Flights       \n");
    printf("===============================\n");

    FILE *file = fopen("flights.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open flights.txt\n");
        getchar();
        return;
    }

    char fCode[20], origin[50], dest[50], depDate[12], depTime[7], arrDate[12], arrTime[7];
    int code, seats, occupiedSeats;
    int found = 0;

    while (fscanf(file, "%d %s %s %s %s %s %s %s %d %d", &code, fCode, origin, depDate, depTime, dest, arrDate, arrTime, &seats, &occupiedSeats) == 10) {
        
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

    char flightNumber[20], passengerName[51], passengerID[15];
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

    printf("Passenger ID: ");
    fgets(passengerID, sizeof(passengerID), stdin);
    removeNewLine(passengerID);

    seatsToBook = readInt("Number of Seats to Book: ");

    FILE *file = fopen("data/Company Users/DataFlights.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open flights.txt\n");
        getchar();
        return;
    }

    char fCode[20], origin[50], dest[50], depDate[12], depTime[7], arrDate[12], arrTime[7];
    int code, seats, occupiedSeats;
    int found = 0;

    while (fscanf(file, "%d %s %s %s %s %s %s %s %d %d", &code, fCode, origin, depDate, depTime, dest, arrDate, arrTime, &seats, &occupiedSeats) == 10) {

        if (strcmp(fCode, flightNumber) == 0) {

            found = 1;

        } else {

            printf("Flight with number %s not found.\n", flightNumber);

            fclose(file);
            getchar();
            return;
        }

        if (found) {

            if (occupiedSeats + seatsToBook <= seats) {

                occupiedSeats += seatsToBook;

                printf("Successfully booked %d seats on flight %s for %s (ID: %s).\n", seatsToBook, flightNumber, passengerName, passengerID);
                getchar();

            } else {
                
                printf("Error: Not enough available seats on flight %s.\n", flightNumber);
                getchar();

            }
            break;
        }
    }
    fclose(file);
}