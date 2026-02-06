#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "client/structs.h"

void clientRegistration() {

    system("clear");

    char strcatAux[100] = "";

    Client newClient;

    printf("===============================\n");
    printf("      Client Registration     \n");
    printf("===============================\n");
    printf("Username (MAX 50 characters): ");
    fgets(newClient.username, sizeof(newClient.username), stdin);
    removeNewLine(newClient.username);

    printf("Password (MAX 50 characters): ");
    fgets(newClient.password, sizeof(newClient.password), stdin);
    removeNewLine(newClient.password);

    printf("Full Name (MAX 100 characters): ");
    fgets(newClient.fullName, sizeof(newClient.fullName), stdin);
    removeNewLine(newClient.fullName);

    printf("Email (MAX 100 characters): ");
    fgets(newClient.email, sizeof(newClient.email), stdin);
    removeNewLine(newClient.email);

    printf("Phone Number (MAX 15 characters): ");
    fgets(newClient.phoneNumber, sizeof(newClient.phoneNumber), stdin);
    removeNewLine(newClient.phoneNumber);

    if (dataClientValidation(newClient.username, newClient.password, newClient.fullName, newClient.email, newClient.phoneNumber) == 1) {

        FILE *file;
        file = fopen("data/Data Clients/clients.dat", "a");

        if (file == NULL) {
            printf("Error opening file for writing.\n");
            system("pause");
            return;
        }

        fprintf(file, "%s;%s;%s;%s;%s\n", newClient.username, newClient.password, newClient.fullName, newClient.email, newClient.phoneNumber);
        fclose(file);

        printf("Client registered successfully!\n");
        printf("Press ENTER to continue...");
        getchar();
    } else {
        printf("Client registration failed due to invalid data.\n");
        printf("Press ENTER to continue...");
        getchar();
    }
}

void clientLogin() {

    system("clear");

    char username[50];
    char password[50];
    int loginSuccess = 0;

    printf("===============================\n");
    printf("         Client Login         \n");
    printf("===============================\n");
    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    removeNewLine(username);
    printf("Password: ");
    fgets(password, sizeof(password), stdin);
    removeNewLine(password);

    int validationResult = loginValidation(username, password);

    if (validationResult == 1) {
        printf("Login successful!\n");
        printf("Press ENTER to continue...");
        getchar();
        // Proceed to client menu (not implemented here)
    } else if (validationResult == -1) {
        printf("Invalid username or password. Please try again.\n");
        printf("Press ENTER to continue...");
        getchar();
    } else {
        printf("Error during login process. Please try again later.\n");
        printf("Press ENTER to continue...");
        getchar();
    }
}