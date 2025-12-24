#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "company/authentication.h"
#include "company/structs.h"

void companyLogin() {

    system("clear");

    char companyCode[10];
    char userLogin[16];
    char password[16];

    printf("===============================\n");
    printf("        Company Login         \n");
    printf("===============================\n");
    printf("Company CODE: ");
    fgets(companyCode, sizeof(companyCode), stdin);
    removeNewLine(companyCode);
    printf("User Login: ");
    fgets(userLogin, sizeof(userLogin), stdin);
    removeNewLine(userLogin);
    printf("Password: ");
    fgets(password, sizeof(password), stdin);
    removeNewLine(password);

    int result;

    result = userValidation(companyCode, userLogin, password);

    if (result == 1) {
        printf("Admin access granted.\n");
        system("pause");
        menuAdmin(companyCode);
    }
    else if (result == 0) {
        printf("User access granted.\n");
        system("pause");
        menuUser(companyCode);
    }
    else {
        printf("Invalid credentials. Please try again.\n");
        system("pause");
    }
}

void companyRegistration() {

    system("clear");

    char strcatAux[100] = "";

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
        newCompany.userQuantity = 1;
    } else {
        printf("Registration failed. Please check the data and try again.\n");
        return;
    }

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

    fprintf(file, "%d %s\n", newCompany.userQuantity, strcatAux);

    fclose(file);
}