#include <stdio.h>
#include <stdlib.h>

#include "company/menus.h"
#include "company/utils.h"
#include "company/flights.h"

 void menuAdmin(const char *code) {

    int option;

    do {

        system("clear");

        printf("===============================\n");
        printf("        Admin Menu            \n");
        printf("===============================\n");
        printf("1 - Create Flight\n");
        printf("2 - Modify Flight\n");
        printf("3 - Delete Flight\n");
        printf("4 - Manage Flights\n");
        printf("5 - Manage User\n");
        printf("0 - Logout\n\n");
        printf("Select an option: ");
        scanf("%d", &option);

        clearInputBuffer();

            switch (option) {

                case 1:
                    createFlight(code);
                    break;

                case 2:
                    // Modify Flight functionality
                    break;

                case 3:
                    // Delete Flight functionality
                    break;

                case 4:
                    // Manage Flights functionality
                    break;

                case 5:
                    // Manage User functionality
                    break;

                case 0:
                    printf("Logging out...\n");
                    system("pause");
                    break;

                default:
                    printf("Invalid option. Please try again.\n");
                    system("pause");
                    break;
            }

    } while (option != 0);

}

void menuUser(const char *code) {

    int option;

    do {

        system("clear");

        printf("===============================\n");
        printf("           User Menu            \n");
        printf("===============================\n");
        printf("1 - Create Flight\n");
        printf("2 - Modify Flight\n");
        printf("3 - Delete Flight\n");
        printf("4 - Manage Flights\n");
        printf("0 - Logout\n\n");

        option = readInt("Select an option: ");

            switch (option) {

                case 1:
                    createFlight(code);
                    break;

                case 2:
                    // Modify Flight functionality
                    break;

                case 3:
                    // Delete Flight functionality
                    break;

                case 4:
                    // Manage Users functionality
                    break;

                case 0:
                    printf("Logging out...\n");
                    system("pause");
                    break;

                default:
                    printf("Invalid option. Please try again.\n");
                    system("pause");
                    break;
            }
            
    } while (option != 0);
}