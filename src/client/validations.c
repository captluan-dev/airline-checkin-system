#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dataClientValidation(char username[], char password[], char fullName[], char email[], char phoneNumber[]) {

    int validation = -1;

    if (strlen(username) > 50) {
        printf("Username exceeds maximum length of 50 characters.\n");
        return validation;
    }

    if (strlen(password) > 50) {
        printf("Password exceeds maximum length of 50 characters.\n");
        return validation;
    }

    if (strlen(fullName) > 100) {
        printf("Full Name exceeds maximum length of 100 characters.\n");
        return validation;
    }

    if (strlen(email) > 100) {
        printf("Email exceeds maximum length of 100 characters.\n");
        return validation;
    }

    if (strlen(phoneNumber) > 15) {
        printf("Phone Number exceeds maximum length of 15 characters.\n");
        return validation;
    }

    validation = 1;
    return validation;
}

int loginValidation(char username[], char password[]) {

    char line[128];
    char fileUsername[50];
    char filePassword[50];

    FILE *file;
    file = fopen("data/Data Clients/clients.dat", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        system("pause");
        return -1;
    }

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%49[^;];%49[^;];%*s;%*s;%*s", fileUsername, filePassword) == 2) {

            if (strcmp(username, fileUsername) == 0 &&
                strcmp(password, filePassword) == 0) {

                fclose(file);
                return 1;
            }
        }
    }
    fclose(file);
    return -1;
}