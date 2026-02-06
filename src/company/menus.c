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

        option = readInt("Select an option: ");

            switch (option) {

                case 1:
                    createFlight(code);
                    break;

                case 2:
                    modifyFlight(code);
                    break;


                case 3:
                    deleteFlight(code);
                    break;

                case 4:
                    manageFlights(code);
                    break;

                case 5:
                    manageUsers(code);
                    break;

                case 0:
                    printf("Logging out...\n");
                    printf("Press Enter to continue...\n");
                    getchar();
                    break;

                default:
                    printf("Invalid option. Please try again.\n");
                    printf("Press Enter to continue...\n");
                    getchar();
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
                    modifyFlight(code);
                    break;

                case 3:
                    deleteFlight(code);
                    break;

                case 4:
                    manageFlights(code);
                    break;

                case 0:
                    printf("Logging out...\n");
                    printf("Press Enter to continue...\n");
                    getchar();
                    break;

                default:
                    printf("Invalid option. Please try again.\n");
                    printf("Press Enter to continue...\n");
                    getchar();
                    break;
            }
            
    } while (option != 0);
}