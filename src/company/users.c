#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "company/utils.h"

void listUsers(int user) {

    system("clear");

    FILE *file = fopen("data/Company Users/CompanyUsers.dat", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        getchar();
        return;
    }

    char companyCode[50], username[50], password[50];
    int codeUser;

    while (fscanf(file, "%d %s %s %s", &codeUser, companyCode, username, password) == 4) {

        if (user == 1 && codeUser == 1) {


            printf("===============================\n");
            printf("        Company Admins        \n");
            printf("===============================\n");
            printf("-------------------------------\n");
            printf("[User Code]: %d\n", codeUser);
            printf("[Username]: %s\n", username);
            printf("------------------------------\n");
        } else if (user == 2 && codeUser == 0) {


            printf("===============================\n");
            printf("         Company Users        \n");
            printf("===============================\n");
            printf("-------------------------------\n");
            printf("[User Code]: %d\n", codeUser);
            printf("[Username]: %s\n", username);
            printf("------------------------------\n");
        } 
    }

    fclose(file);
    printf("===============================\n");
    printf("Press Enter to continue...");
    getchar();
}

void AddUser(const char *codeCompany) {
    
    system("clear");

    FILE *file = fopen("data/Company Users/CompanyUsers.dat", "a");

    if (file == NULL) {
        printf("Error opening file.\n");
        getchar();
        return;
    }

    int codeUser;
    char username[50], password[50];

    printf("===============================\n");
    printf("          Add User            \n");
    printf("===============================\n");
    printf("Enter User Code (1 for Admin, 0 for User): ");
    scanf("%d", &codeUser);
    clearInputBuffer();

    printf("Enter Username: ");
    fgets(username, sizeof(username), stdin);
    removeNewLine(username);

    printf("Enter Password: ");
    fgets(password, sizeof(password), stdin);
    removeNewLine(password);

    fprintf(file, "%d;%s;%s;%s\n", codeUser, codeCompany, username, password);

    fclose(file);

    printf("User added successfully!\n");
    printf("Press Enter to continue...");
    getchar();
}

void modifyUser(const char *codeCompany) {
    
    system("clear");

    char usernameModify[50] = "";


    printf("===============================\n");
    printf("         Modify User          \n");
    printf("===============================\n");
    printf("Enter the username of the user to modify: ");
    fgets(usernameModify, sizeof(usernameModify), stdin);
    removeNewLine(usernameModify);

    FILE *file = fopen("data/Company Users/CompanyUsers.dat", "r");
    FILE *tempFile = fopen("data/Company Users/TempUsers.dat", "w");

    if (file == NULL || tempFile == NULL) {
        printf("Error opening files.\n");
        if(file) fclose(file);
        return;
    }

    char companyCode[50], username[50], password[50];
    int codeUser;
    int found = 0;

    while (fscanf(file, "%d %s %s %s", &codeUser, companyCode, username, password) == 4) {
        
        if (strcmp(usernameModify, username) == 0) {
            found = 1;

            system("clear");
            
            printf("What do you want to modify?\n");
            printf("1 - Username\n");
            printf("2 - Password\n");
            printf("0 - Cancel\n");
            
            int op = readInt("Option: ");

            switch (op) {
                case 1:
                    printf("New Username: ");
                    fgets(username, sizeof(username), stdin);
                    removeNewLine(username);
                    printf("Username modified successfully.\n");
                    printf("Press Enter to continue...");
                    getchar();
                    break;
                case 2:
                    printf("New Password: ");
                    fgets(password, sizeof(password), stdin);
                    removeNewLine(password);
                    printf("Password modified successfully.\n");
                    printf("Press Enter to continue...");
                    getchar();
                    break;
                case 0:
                    printf("Modification cancelled.\n");
                    printf("Press Enter to continue...");
                    getchar();
                    break;
                default:
                    printf("Invalid option.\n");
                    printf("Press Enter to continue...");
                    getchar();
                    break;
            }
        }
        fprintf(tempFile, "%d %s %s %s\n", codeUser, companyCode, username, password);
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove("data/Company Users/CompanyUsers.dat");
        rename("data/Company Users/TempUsers.dat", "data/Company Users/CompanyUsers.dat");
        printf("User updated successfully!\n");
    } else {
        remove("data/Company Users/TempUsers.dat");
        printf("User not found.\n");
    }
    printf("Press Enter to continue...");
    getchar();
}

void deleteUser(const char *codeCompany) {
    
    system("clear");

    char usernameDelete[50] = "";

    printf("===============================\n");
    printf("         Delete User          \n");
    printf("===============================\n");
    printf("Enter the username of the user to delete: ");
    fgets(usernameDelete, sizeof(usernameDelete), stdin);
    removeNewLine(usernameDelete);

    FILE *file = fopen("data/Company Users/CompanyUsers.dat", "r");
    FILE *tempFile = fopen("data/Company Users/TempUsers.dat", "w");

    if (file == NULL || tempFile == NULL) {
        printf("Error opening files.\n");
        if(file) fclose(file);
        return;
    }

    char companyCode[50], username[50], password[50];
    int codeUser;
    int found = 0;

    while (fscanf(file, "%d %s %s %s", &codeUser, companyCode, username, password) == 4) {
        
        if (strcmp(usernameDelete, username) == 0) {
            found = 1;
            continue;
        } else {
            fprintf(tempFile, "%d %s %s %s\n", codeUser, companyCode, username, password);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove("data/Company Users/CompanyUsers.dat");
        rename("data/Company Users/TempUsers.dat", "data/Company Users/CompanyUsers.dat");
        printf("User deleted successfully!\n");
    } else {
        remove("data/Company Users/TempUsers.dat");
        printf("User not found.\n");
    }
    printf("Press Enter to continue...");
    getchar();
}

void listAllUsers() {
    
    system("clear");

    printf("===============================\n");
    printf("           All Users     \n");
    printf("===============================\n");

    FILE *file = fopen("data/Company Users/CompanyUsers.dat", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        getchar();
        return;
    }

    char companyCode[50], username[50], password[50];
    int codeUser;

    while (fscanf(file, "%d %s %s %s", &codeUser, companyCode, username, password) == 4) {

        printf("-------------------------------\n");
        printf("[User Code]: %d\n", codeUser);
        printf("[Username]: %s\n", username);
        printf("------------------------------\n");
    }

    fclose(file);
    printf("===============================\n");
    printf("Press Enter to continue...");
    getchar();
}