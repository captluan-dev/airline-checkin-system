#ifndef VALIDATIONS_H
#define VALIDATIONS_H

int userValidation(char companyCode[], char userLogin[], char password[]);
int registrationDataValidation(char companyCode[], char companyName[], char userAdmin[], char passwordAdmin[]);
int newFlightValidation(char flightNumber[], char origin[], char destination[], char departureDate[], char departureTime[], char arrivalDate[], char arrivalTime[], int totalSeats);
int dateValidation(const char *date);
int timeValidation(const char *hours);

#endif