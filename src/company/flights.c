#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "company/structs.h"
#include "company/validations.h"
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

        int occupiedSeats = 0;
        newFlight.flightID = flightQuantity() + 1;

        FILE *file;
        file = fopen("data/Company Users/DataFlights.txt", "a");

        if (file == NULL) {
            printf("Error opening file.\n");
            system("pause");
            return;
        }

        sprintf(strcatAux, "%s%s %s %s %s %s %s %s", codeCompany, newFlight.flightNumber, newFlight.origin, newFlight.departureDate, newFlight.departureTime, newFlight.destination, newFlight.arrivalDate, newFlight.arrivalTime);

        fprintf(file, "%d %s %d %d\n", newFlight.flightID, strcatAux, newFlight.totalSeats, occupiedSeats);

        fclose(file);

    } else {
        printf("Flight creation failed due to validation errors.\n");
    }

    system("pause");
}

void modifyFlight(const char *codeCompany) {

    system("clear");

    char flightModifyCode[15] = "";
    char flightModifyAux[10];
    char dateFlight[12], timeFlight[7];

    printf("Insert the number of the flight: ");
    fgets(flightModifyAux, sizeof(flightModifyAux), stdin);
    removeNewLine(flightModifyAux);

    sprintf(flightModifyCode, "%s%s", codeCompany, flightModifyAux);

    printf("Insert departure date (DD/MM/YYYY): ");
    fgets(dateFlight, sizeof(dateFlight), stdin);
    removeNewLine(dateFlight);

    printf("Insert departure hour (HH:MM): ");
    fgets(timeFlight, sizeof(timeFlight), stdin);
    removeNewLine(timeFlight);

    FILE *file = fopen("data/Company Users/DataFlights.txt", "r");
    FILE *tempFile = fopen("data/Company Users/TempFlights.txt", "w");

    if (file == NULL || tempFile == NULL) {
        printf("Error opening files.\n");
        if(file) fclose(file);
        return;
    }

    char fCode[20], origin[50], dest[50], depDate[12], depTime[7], arrDate[12], arrTime[7];
    int code, seats, occupiedSeats;
    int found = 0;

    while (fscanf(file, "%d %s %s %s %s %s %s %s %d %d", &code, fCode, origin, depDate, depTime, dest, arrDate, arrTime, &seats, &occupiedSeats) == 10) {
        
        if (strcmp(flightModifyCode, fCode) == 0 && strcmp(dateFlight, depDate) == 0 && strcmp(timeFlight, depTime) == 0) {
            found = 1;

            system("clear");
            
            printf("What do you want to modify?\n");
            printf("1 - Flight Number\n");
            printf("2 - Origin\n");
            printf("3 - Destination\n");
            printf("4 - Departure Date\n");
            printf("5 - Departure Time\n");
            printf("6 - Arrival Date\n");
            printf("7 - Arrival Time\n");
            printf("8 - Total Seats\n");
            printf("0 - Cancel\n");
            
            int op = readInt("Option: ");

            switch (op) {
                case 1:
                    printf("New Flight Number: ");
                    fgets(fCode + strlen(codeCompany), sizeof(fCode) - strlen(codeCompany), stdin);
                    removeNewLine(fCode + strlen(codeCompany));
                    printf("Flight Number modified successfully.\n");
                    printf("Press Enter to continue...");
                    getchar();
                    break;
                case 2:
                    printf("New Origin: ");
                    fgets(origin, sizeof(origin), stdin);
                    removeNewLine(origin);
                    printf("Origin modified successfully.\n");
                    printf("Press Enter to continue...");
                    getchar();
                    break;
                case 3:
                    printf("New Destination: ");
                    fgets(dest, sizeof(dest), stdin);
                    removeNewLine(dest);
                    printf("Destination modified successfully.\n");
                    printf("Press Enter to continue...");
                    getchar();
                    break;
                case 4:
                    printf("New Departure Date (DD/MM/YYYY): ");
                    fgets(depDate, sizeof(depDate), stdin);
                    removeNewLine(depDate);
                    dateValidation(depDate);
                    printf("Departure Date modified successfully.\n");
                    printf("Press Enter to continue...");
                    getchar();
                    break;
                case 5:
                    printf("New Departure Time (HH:MM): ");
                    fgets(depTime, sizeof(depTime), stdin);
                    removeNewLine(depTime);
                    timeValidation(depTime);
                    printf("Departure Time modified successfully.\n");
                    printf("Press Enter to continue...");
                    getchar();
                    break;
                case 6:
                    printf("New Arrival Date (DD/MM/YYYY): ");
                    fgets(arrDate, sizeof(arrDate), stdin);
                    removeNewLine(arrDate);
                    dateValidation(arrDate);
                    printf("Arrival Date modified successfully.\n");
                    printf("Press Enter to continue...");
                    getchar();
                    break;
                case 7:
                    printf("New Arrival Time (HH:MM): ");
                    fgets(arrTime, sizeof(arrTime), stdin);
                    removeNewLine(arrTime);
                    timeValidation(arrTime);
                    printf("Arrival Time modified successfully.\n");
                    printf("Press Enter to continue...");
                    getchar();
                    break;
                case 8:
                    seats = readInt("New Total Seats: ");
                    printf("Total Seats modified successfully.\n");
                    printf("Press Enter to continue...");
                    getchar();
                    break;
                case 0:
                    printf("Modification cancelled.\n");
                    printf("Press Enter to continue...");
                    getchar();
                default:
                    printf("Invalid option.\n");
                    fclose(file);
                    return;
            }

            if(op == 0) {
                 fprintf(tempFile, "%d %s %s %s %s %s %s %s %d %d\n", code, fCode, origin, depDate, depTime, dest, arrDate, arrTime, seats, occupiedSeats);
                 continue;
            }
        }
        fprintf(tempFile, "%d %s %s %s %s %s %s %s %d %d\n", code, fCode, origin, depDate, depTime, dest, arrDate, arrTime, seats, occupiedSeats);
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove("data/Company Users/DataFlights.txt");
        rename("data/Company Users/TempFlights.txt", "data/Company Users/DataFlights.txt");
        printf("Flight updated successfully!\n");
    } else {
        remove("data/Company Users/TempFlights.txt");
        printf("Flight not found.\n");
    }
    system("pause");
}

void deleteFlight(const char *codeCompany) {
    
    system("clear");

    int code;

    printf("===============================\n");
    printf("        Delete Flight         \n");
    printf("===============================\n");
    printf("Insert the code of the flight to delete: ");

    scanf("%d", &code);
    clearInputBuffer();

    FILE *file = fopen("data/Company Users/DataFlights.txt", "r");
    FILE *tempFile = fopen("data/Company Users/TempFlights.txt", "w");

    if (file == NULL || tempFile == NULL) {
        printf("Error opening files.\n");
        if(file) fclose(file);
        return;
    }

    char fCode[20], origin[50], dest[50], depDate[12], depTime[7], arrDate[12], arrTime[7];
    int flightID, seats, occupiedSeats;
    int found = 0;
    char confirm;

    while (fscanf(file, "%d %s %s %s %s %s %s %s %d %d", &flightID, fCode, origin, depDate, depTime, dest, arrDate, arrTime, &seats, &occupiedSeats) == 10) {

        if (flightID == code) {
            found = 1;

            showDetailsFlightByCode(flightID);
            printf("Confirm deletion? (y/n): ");
            scanf(" %c", &confirm);
            clearInputBuffer();

            if (confirm == 'y' || confirm == 'Y') {
                continue;
            } else if (confirm == 'n' || confirm == 'N') {
                printf("Deletion cancelled.\n");
                printf("Press Enter to continue...");
                getchar();

                fprintf(tempFile, "%d %s %s %s %s %s %s %s %d %d\n", flightID, fCode, origin, depDate, depTime, dest, arrDate, arrTime, seats, occupiedSeats);

                fclose(file);
                fclose(tempFile);
                remove("data/Company Users/TempFlights.txt");
                return;
            }

            continue;
        }
        fprintf(tempFile, "%d %s %s %s %s %s %s %s %d %d\n", flightID, fCode, origin, depDate, depTime, dest, arrDate, arrTime, seats, occupiedSeats);
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove("data/Company Users/DataFlights.txt");
        rename("data/Company Users/TempFlights.txt", "data/Company Users/DataFlights.txt");
        printf("Flight deleted successfully!\n");
    } else {
        remove("data/Company Users/TempFlights.txt");
        printf("Flight not found.\n");
    }
    system("pause");
}

void manageFlights(const char *code) {

    system("clear");

    int option;

    printf("===============================\n");
    printf("       Manage Flights         \n");
    printf("===============================\n");
    printf("1 - Check flight details\n");
    printf("2 - List all flights\n");
    printf("0 - Back to Admin Menu\n\n");
    printf("Select an option: ");
    scanf("%d", &option);

    clearInputBuffer();

    switch(option) {

        case 1:
            system("clear");

            printf("Check via flight code or number?\n");
            printf("1 - Flight Code\n");
            printf("2 - Flight Number\n");

            int subOption = readInt("Option: ");

            if(subOption == 1) {

                int flightCode = readInt("Insert flight code: ");

                showDetailsFlightByCode(flightCode);
            } else if(subOption == 2) {

                char flightNumber[20];

                readString("Insert flight number: ", flightNumber, sizeof(flightNumber));

                char fullFlightCode[25];
                sprintf(fullFlightCode, "%s%s", code, flightNumber);

                showDetailsFlightByFlightCode(fullFlightCode);
            } else {
                printf("Invalid option.\n");
                getchar();
            }

            break;
        case 2:
            listFlights(code);
            break;
        case 0:
            printf("Returning to Admin Menu...\n");
            printf("Press Enter to continue...");
            getchar();
            break;
        default:
            printf("Invalid option. Please try again.\n");
            printf("Press Enter to continue...");
            getchar();
            break;
        }
}