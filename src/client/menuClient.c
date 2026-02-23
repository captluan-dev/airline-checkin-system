#include <stdio.h>
#include <stdlib.h>

#include "client/menuClient.h"
#include "client/flightsClient.h"
#include "client/utilsClient.h"

void menuClient() {

    int option;

    do {

        system("clear");

        printf("===============================\n");
        printf("        Client Menu           \n");
        printf("===============================\n");
        printf("1 - View Flights\n");
        printf("2 - Book Flight\n");
        printf("3 - View Bookings\n");
        printf("4 - Check-in\n");
        printf("0 - Logout\n\n");

        option = readInt("Select an option: ");

            switch (option) {

                case 1:
                    viewFlights();
                    break;

                case 2:
                    bookFlight();
                    break;

                case 3:
                    viewBookings();
                    break;

                case 4:
                    checkIn();
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
            }

    } while (option != 0);
}