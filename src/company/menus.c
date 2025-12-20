#include <stdio.h>
#include <stdlib.h>

#include "company/menus.h"

void menuAdmin() {

    int option;

    do {

        printf("===============================\n");
        printf("        Admin Menu            \n");
        printf("===============================\n");
        printf("1 - Create Flight\n");
        printf("2 - Modify Flight\n");
        printf("3 - Delete Flight\n");
        printf("4 - Manage Users\n");
        printf("5 - Register Passenger\n");
        printf("6 - Generate Reservation Code\n");
        printf("0 - Logout\n\n");
        printf("Select an option: ");
        scanf("%d", &option);

            switch (option) {

                case 1:
                    // Create Flight functionality
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

                case 5:
                    // Register Passenger functionality
                    break;

                case 6:
                    // Generate Reservation Code functionality
                    break;

                case 0:
                    printf("Logging out...\n");
                    system("pause");
                    break;

                default:
                    printf("Invalid option. Please try again.\n");
                    break;
            }
    } while (option != 0);
}