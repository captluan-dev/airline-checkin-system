#include <stdio.h>
#include <stdlib.h>

#include "client/main.h"
#include "client/authenticationClient.h"

int main() {

    int option;

    do {

    system("clear");

    printf("===============================\n");
    printf("          Client System        \n");
    printf("===============================\n");
    printf("1 - Client Login\n");
    printf("2 - Register Client\n");
    printf("0 - Exit\n\n");
    printf("Select an option: ");
    scanf("%d", &option);

    clearInputBuffer();

        switch (option) {

            case 1:
                clientLogin();
                break;

            case 2:
                clientRegistration();
                break;

            case 0:
                printf("Exiting the system. Goodbye!\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }

    } while (option != 0);
}