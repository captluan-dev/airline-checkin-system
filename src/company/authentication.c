#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "company/authentication.h"
#include "company/structs.h"

void companyLogin() {

    system("clear");

    char companyCode[10];
    char userLogin[16];
    char password[16    ];

    printf("===============================\n");
    printf("        Company Login         \n");
    printf("===============================\n");
    printf("Company CODE: ");
    scanf("%3s", companyCode);
    printf("User Login: ");
    scanf("%15s", userLogin);
    printf("Password: ");
    scanf("%10s", password);

    if (userValidation(companyCode, userLogin, password) == 1) {
        menuAdmin();
    } else if (userValidation(companyCode, userLogin, password) == 0) {
        printf("User access granted.\n");
    } else {
        printf("Invalid credentials. Please try again.\n");
    }
}

void companyRegistration() {

    system("clear");

    char strcatAux[100];

    CompanyRegistration newCompany;

    printf("===============================\n");
    printf("     Company Registration     \n");
    printf("===============================\n");
    printf("Company CODE (MAX 5 characters): ");
    fgets(newCompany.companyCode, 5, stdin);
    removeNewLine(newCompany.companyCode);

    printf("Company Name (MAX 50 characters): ");
    fgets(newCompany.companyName, 50, stdin);
    removeNewLine(newCompany.companyName);

    printf("Admin User (MAX 15 characters): ");
    fgets(newCompany.userAdmin, 15, stdin);
    removeNewLine(newCompany.userAdmin);

    printf("Admin Password (MAX 10 characters): ");
    fgets(newCompany.passwordAdmin, 10, stdin);
    removeNewLine(newCompany.passwordAdmin);
    
    newCompany.levelAccess = 1; // Admin level

    if (registrationDataValidation(newCompany.companyCode, newCompany.companyName, newCompany.userAdmin, newCompany.passwordAdmin) == 1) {
        printf("Company registered successfully.\n");
    } else {
        printf("Registration failed. Please check the data and try again.\n");
    } // Registrar se os dados não estão excedendo o limite

    strcat(strcatAux, newCompany.companyCode);
    strcat(strcatAux, " ");
    strcat(strcatAux, newCompany.userAdmin);
    strcat(strcatAux, " ");
    strcat(strcatAux, newCompany.passwordAdmin);

    FILE *file;
    file = fopen("data\\Company Users\\CompanyUsers.txt", "a");

    if (file == NULL) {
        printf("Error opening file.\n");
        system("pause");
        return;
    }

    fprintf(file, "%s\n", strcatAux);

    fclose(file);
}