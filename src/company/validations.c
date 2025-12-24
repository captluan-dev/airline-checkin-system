#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "company/validations.h"

int userValidation(char companyCode[], char userLogin[], char password[]) {

    char line[128];
    char fileCompanyCode[10];
    char fileUserLogin[16];
    char filePassword[16];
    int userID;

    FILE *file;
    file = fopen("data\\Company Users\\CompanyUsers.txt", "r");

    if (file ==NULL) {
        printf("Error opening file.\n");
        system("pause");
        return -1;
    }

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%d %9s %15s %15s", &userID, fileCompanyCode, fileUserLogin, filePassword) == 4) {

            if (strcmp(companyCode, fileCompanyCode) == 0 &&
                strcmp(userLogin, fileUserLogin) == 0 &&
                strcmp(password, filePassword) == 0) {

                fclose(file);
                return (strcmp(userLogin, "admin") == 0) ? 1 : 0;
            }
        }
    }
    
    fclose(file);
    return -1;
}

int registrationDataValidation(char companyCode[], char companyName[], char userAdmin[], char passwordAdmin[]) {

    int validation = -1;

    if (strlen(companyCode) > 5) {
        printf("Company code exceeds maximum length of 5 characters.\n");
        return validation;
    }

    if (strlen(companyName) > 50) {
        printf("Company name exceeds maximum length of 50 characters.\n");
        return validation;
    }

    if (strlen(userAdmin) > 15) {
        printf("Admin user exceeds maximum length of 15 characters.\n");
        return validation;
    }

    if (strlen(passwordAdmin) > 10) {
        printf("Admin password exceeds maximum length of 10 characters.\n");
        return validation;
    }

    validation = 1;
    return validation;
}

int newFlightValidation(char flightNumber[], char origin[], char destination[], char departureDate[], char departureTime[], char arrivalDate[], char arrivalTime[], int totalSeats) {

    int validation = -1;

    if (strlen(flightNumber) > 4) {
        printf("Flight Number exceeds maximum length of 4 characters.\n");
        return validation;
    }

    if (strlen(origin) > 30) {
        printf("Origin exceeds maximum length of 30 characters.\n");
        return validation;
    }

    if (strlen(destination) > 30) {
        printf("Destination exceeds maximum length of 30 characters.\n");
        return validation;
    }

    if (dateValidation(departureDate) == -1) {
        printf("Invalid departure date format.\n");
        return validation;
    }

    if (timeValidation(departureTime) == -1) {
        printf("Invalid departure time format.\n");
        return validation;
    }

    if (dateValidation(arrivalDate) == -1) {
        printf("Invalid arrival date format.\n");
        return validation;
    }

    if (timeValidation(arrivalTime) == -1) {
        printf("Invalid arrival time format.\n");
        return validation;
    }

    if (totalSeats < 1 || totalSeats > 500) {
        printf("Total number of seats is invalid.\n");
        return validation;
    }

    validation = 1;
    return validation;
}

int dateValidation(const char *date) {

    int i;
    int day, month, year;

    if (strlen(date) != 10)                     // Check the exact size (DD/MM/YYYY = 10 characters)
        return -1;

    if (date[2] != '/' || date[5] != '/')       // Check if the bars are in the correct positions.
        return -1;

    for (i = 0; i < 10; i++) {                  // Check if the other characters are numbers.

        if (i == 2 || i == 5)
            continue;

        if (!isdigit(date[i]))
            return -1;
    }

    day = (date[0] - '0') * 10 + (date[1] - '0');           // Converts characters to numbers.
    month = (date[3] - '0') * 10 + (date[4] - '0');
    year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');

    if (year < 2025 || month < 1 || month > 12 || day < 1)      // Basic range validation
        return -1;

    int daysMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};     // Maximum number of days per month

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))    // Adjustment for leap year
        daysMonth[1] = 29;

    if (day > daysMonth[month - 1])     // Check if the day is valid for the month.
        return -1;

    return 1;
}

int timeValidation (const char *hours) {

    int i;
    int time, minute;

    if (strlen(hours) != 5)
        return -1;

    if (hours[2] != ':')
        return -1;

    for (i = 0; i < 5; i++) {

        if (i == 2)
            continue;

        if (!isdigit(hours[i]))
            return -1;

    }

    time = (hours[0] - '0') * 10 + (hours[1] - '0');
    minute = (hours[3] - '0') * 10 + (hours[4] - '0');

    if (time < 0 || time > 23)
        return -1;

    if (minute < 0 || minute > 59)
        return -1;

    return 1;
}