#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "company/utils.h"

void removeNewLine(char *str) { //str = data
    
    str[strcspn(str, "\n")] = '\0';
}

int userValidation(char companyCode[], char userLogin[], char password[]) {

    int userLevel = -1;

    char fileCompanyCode[10];
    char fileUserLogin[16];
    char filePassword[16];

    FILE *file;
    file = fopen("data\\Company Users\\CompanyUsers.txt", "r");

    if (file ==NULL) {
        printf("Error opening file.\n");
        system("pause");
        return -1;
    }

    while (fscanf(file, "%3s %15s %10s", fileCompanyCode, fileUserLogin, filePassword) == 3) {
        if (strcmp(companyCode, fileCompanyCode) == 0 &&
            strcmp(userLogin, fileUserLogin) == 0 &&
            strcmp(password, filePassword) == 0) {

                if (strcmp(userLogin, "admin") == 0) {
                    userLevel = 1; // Admin user
                } else {
                    userLevel = 0; // Regular user
                }
            }
    }
    fclose(file);
    return userLevel; // Return user Level
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