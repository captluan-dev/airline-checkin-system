#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "company/structs.h"
#include "company/flights.h"
#include "company/utils.h"

void createFlight(const char *codeCompany) {

    system("clear");

    int flightQtt = flightQuantity();

    char strcatAux[500] = "";

    CreateFlight newFlight;

    printf("===============================\n");
    printf("        Create Flight         \n");
    printf("===============================\n");
    printf("\nInsert flight details below:\n");

    printf("Flight Number: ");
    fgets(newFlight.flightNumber, sizeof(newFlight.flightNumber), stdin);
    removeNewLine(newFlight.flightNumber);

    printf("Origin: ");
    fgets(newFlight.origin, sizeof(newFlight.origin), stdin);
    removeNewLine(newFlight.origin);

    printf("Destination: ");
    fgets(newFlight.destination, sizeof(newFlight.destination), stdin);
    removeNewLine(newFlight.destination);

    printf("Departure Date (DD/MM/YYYY): ");
    fgets(newFlight.departureDate, sizeof(newFlight.departureDate), stdin);
    removeNewLine(newFlight.departureDate);

    printf("Departure Time (HH:MM): ");
    fgets(newFlight.departureTime, sizeof(newFlight.departureTime), stdin);
    removeNewLine(newFlight.departureTime);

    printf("Arrival Date (DD/MM/YYYY): ");
    fgets(newFlight.arrivalDate, sizeof(newFlight.arrivalDate), stdin);
    removeNewLine(newFlight.arrivalDate);

    printf("Arrival Time (HH:MM): ");
    fgets(newFlight.arrivalTime, sizeof(newFlight.arrivalTime), stdin);
    removeNewLine(newFlight.arrivalTime);

    newFlight.totalSeats = readInt("Total seats: ");

    if (newFlightValidation(newFlight.flightNumber, newFlight.origin, newFlight.destination, newFlight.departureDate, newFlight.departureTime, newFlight.arrivalDate, newFlight.arrivalTime, newFlight.totalSeats) == 1) {
        
        printf("Flight created successfully!\n");

        newFlight.flightID = flightQuantity() + 1;

        FILE *file;
        file = fopen("data\\Company Users\\DataFlights.txt", "a");

        if (file == NULL) {
            printf("Error opening file.\n");
            system("pause");
            return;
        }

        sprintf(strcatAux, "%s%s %s %s %s %s %s", codeCompany, newFlight.flightNumber, newFlight.origin, newFlight.departureDate, newFlight.departureTime, newFlight.destination, newFlight.arrivalDate, newFlight.arrivalTime);

        fprintf(file, "%d %s %d\n", newFlight.flightID, strcatAux, newFlight.totalSeats);

        fclose(file);

    } else {
        printf("Flight creation failed due to validation errors.\n");
    }

    system("pause");
}