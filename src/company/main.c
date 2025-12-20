#include <stdio.h>

#include "company/authentication.h"

int main() {

    int option;

    do {

    printf("===============================\n");
    printf("         Company System        \n");
    printf("===============================\n");
    printf("1 - Company Login\n");
    printf("2 - Register Company\n");
    printf("0 - Exit\n\n");
    printf("Select an option: ");
    scanf("%d", &option);
    getchar();

        switch (option) {

            case 1:
                companyLogin();
                break;

            case 2:
                companyRegistration();
                break;

            case 0:
                printf("Exiting the system. Goodbye!\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }

    } while (option != 0);

    return 0;

}