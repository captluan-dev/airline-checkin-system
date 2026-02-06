#ifndef FLIGHTS_H
#define FLIGHTS_H

void createFlight(const char *codeCompany);
void modifyFlight(const char *codeCompany);
void deleteFlight(const char *codeCompany);
void manageFlights(const char *code);
int newFlightValidation(char flightNumber[], char origin[], char destination[], char departureDate[], char departureTime[], char arrivalDate[], char arrivalTime[], int totalSeats);
int flightQuantity();
void clearInputBuffer();
void showDetailsFlightByCode(int flightCode);
void showDetailsFlightByFlightCode(const char *flightCode);

#endif