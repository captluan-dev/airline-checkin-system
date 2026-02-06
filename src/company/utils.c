#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "company/utils.h"

void removeNewLine(char *str) { //str = data
    
    str[strcspn(str, "\n")] = '\0';
}

int flightQuantity() {

    int id;
    int biggestID = 0;
    char line[200];

    FILE *file;
    file = fopen("data/Company Users/DataFlights.txt", "r");

    if (file == NULL) {
        return 0;
    }

    while(fgets(line, 200, file)) {

        if (sscanf(line, "%d", &id) == 1) {

        if (id > biggestID)
            biggestID = id;
        }
    }

    fclose(file);
    return biggestID;
}

int readInt(const char *msg) {
    
    char buffer[32];
    int value;

    while (1) {
        printf("%s", msg);

        if (!fgets(buffer, sizeof(buffer), stdin))
            return -1;

        if (buffer[0] == '\n')
            continue;

        if (sscanf(buffer, "%d", &value) == 1)
            return value;

        printf("Invalid number. Try again.\n");
    }
}


void clearInputBuffer() {

    int c;

    while ((c = getchar()) != '\n' && c != EOF);
}

void readString(const char *msg, char *dest, int size) {
    printf("%s", msg);

    if (fgets(dest, size, stdin)) {
        dest[strcspn(dest, "\n")] = '\0';
    }
}

void showDetailsFlightByCode(int flightCode) {

    FILE *file = fopen("data/Company Users/DataFlights.txt", "r");
    
    if (file == NULL) {
        printf("Error opening file.\n");
        system("pause");
        return;
    }

    char fCode[20], origin[50], dest[50], depDate[12], depTime[7], arrDate[12], arrTime[7];
    int code, seats, occupiedSeats;
    int found = 0;

    while (fscanf(file, "%d %s %s %s %s %s %s %s %d %d", &code, fCode, origin, depDate, depTime, dest, arrDate, arrTime, &seats, &occupiedSeats) == 10) {

        if (code == flightCode) {

            found = 1;

            printf("===============================\n");
            printf("        Flight %s Details\n", fCode);
            printf("===============================\n");
            printf("Flight code: %d\n", code);
            printf("Origin: %s\n", origin);
            printf("Departure Date: %s\n", depDate);
            printf("Departure Time: %s\n", depTime);
            printf("Destination: %s\n", dest);
            printf("Arrival Date: %s\n", arrDate);
            printf("Arrival Time: %s\n", arrTime);
            printf("Total Seats: %d\n", seats);
            printf("Occupied Seats: %d\n", occupiedSeats);
            printf("===============================\n\n");
            
            printf("Press Enter to continue...");
            getchar();
            break;
        }
    }

    if (!found) {
        printf("Flight with code %d not found.\n", flightCode);
    }

    fclose(file);
    system("pause");
}

void showDetailsFlightByFlightCode(const char *flightCode) {

    FILE *file = fopen("data/Company Users/DataFlights.txt", "r");
    
    if (file == NULL) {
        printf("Error opening file.\n");
        system("pause");
        return;
    }

    char fCode[20], origin[50], dest[50], depDate[12], depTime[7], arrDate[12], arrTime[7];
    int code, seats, occupiedSeats;
    int found = 0;

    while (fscanf(file, "%d %s %s %s %s %s %s %s %d %d", &code, fCode, origin, depDate, depTime, dest, arrDate, arrTime, &seats, &occupiedSeats) == 10) {

        if (strcmp(fCode, flightCode) == 0) {

            found = 1;

            printf("===============================\n");
            printf("  Flight %s Details\n", fCode);
            printf("===============================\n");
            printf("[Flight Code]: %d\n", code);
            printf("[Origin]: %s\n", origin);
            printf("[Departure Date]: %s\n", depDate);
            printf("[Departure Time]: %s\n", depTime);
            printf("[Destination]: %s\n", dest);
            printf("[Arrival Date]: %s\n", arrDate);
            printf("[Arrival Time]: %s\n", arrTime);
            printf("[Total Seats]: %d\n", seats);
            printf("[Occupied Seats]: %d\n", occupiedSeats);
            printf("===============================\n\n");
            
            printf("Press Enter to continue...");
            getchar();
            break;
        }
    }

    if (!found) {
        printf("Flight with code %s not found.\n", flightCode);
    }

    fclose(file);
    system("pause");
}

void listFlights(const char *codeCompany) {

    system("clear");

    FILE *file = fopen("data/Company Users/DataFlights.txt", "r");
    
    if (file == NULL) {
        printf("Error opening file.\n");
        system("pause");
        return;
    }

    char fCode[20], origin[50], dest[50], depDate[12], depTime[7], arrDate[12], arrTime[7];
    int code, seats, occupiedSeats;
    int found = 0;

    printf("===============================\n");
    printf("        All Flights           \n");
    printf("===============================\n");

    while (fscanf(file, "%d %s %s %s %s %s %s %s %d %d", &code, fCode, origin, depDate, depTime, dest, arrDate, arrTime, &seats, &occupiedSeats) == 10) {

        if (strncmp(fCode, codeCompany, strlen(codeCompany)) == 0) {
            found = 1;

            printf("-------------------------------\n");
            printf("        Flight %s\n", fCode);
            printf("-------------------------------\n");
            printf("[Flight Code]: %d\n", code);
            printf("[Origin]: %s\n", origin);
            printf("[Departure Date]: %s\n", depDate);
            printf("[Departure Time]: %s\n", depTime);
            printf("[Destination]: %s\n", dest);
            printf("[Arrival Date]: %s\n", arrDate);
            printf("[Arrival Time]: %s\n", arrTime);
            printf("[Total Seats]: %d\n", seats);
            printf("[Occupied Seats]: %d\n", occupiedSeats);
            printf("-------------------------------\n\n");
        }
    }

    if (!found) {
        printf("No flights founded.\n");
    }

    fclose(file);
    printf("===============================\n");
    printf("Press Enter to continue...");
    getchar();
}

void manageUsers(const char *codeCompany) {

    system("clear");

    printf("===============================\n");
    printf("       Manage Users          \n");
    printf("===============================\n");
    printf("1 - List Users\n");
    printf("2 - Add User\n");
    printf("3 - Modify User\n");
    printf("4 - Delete User\n");
    printf("0 - Back to Admin Menu\n\n");

    int option = readInt("Select an option: ");

    switch(option) {

        case 1:
            system("clear");

            printf("===============================\n");
            printf("           List Users          \n");
            printf("===============================\n");
            printf("1 - List Admins\n");
            printf("2 - List Users\n");
            printf("3 - List All\n");
            printf("0 - Back to Manage Users Menu\n\n");

            int listOption = readInt("Select an option: ");

            switch(listOption) {
                case 1:
                    listUsers(listOption);
                    break;
                case 2:
                    listUsers(listOption);
                    break;
                case 3:
                    listAllUsers();
                    break;
                case 0:
                    printf("Returning to Manage Users Menu...\n");
                    printf("Press Enter to continue...");
                    getchar();
                    break;
                default:
                    printf("Invalid option. Please try again.\n");
                    printf("Press Enter to continue...");
                    getchar();
                    break;
            }
            break;
        case 2:
            AddUser(codeCompany);
            break;
        case 3:
            modifyUser(codeCompany);
            break;
        case 4:
            deleteUser(codeCompany);
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