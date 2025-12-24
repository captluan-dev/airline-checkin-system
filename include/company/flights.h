#ifndef FLIGHTS_H
#define FLIGHTS_H

void createFlight(const char *codeCompany);
int newFlightValidation(char flightNumber[], char origin[], char destination[], char departureDate[], char departureTime[], char arrivalDate[], char arrivalTime[], int totalSeats);
int flightQuantity();
void clearInputBuffer();

#endif