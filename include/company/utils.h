#ifndef UTILS_H
#define UTILS_H

void removeNewLine(char *str);
int flightQuantity();
void clearInputBuffer(void);
int readInt(const char *msg);
void readString(const char *msg, char *dest, int size);
void showDetailsFlightByCode(int flightCode);
void showDetailsFlightByFlightCode(const char *flightCode);
void listFlights(const char *codeCompany);
void manageUsers(const char *codeCompany);
void listUsers(int user);
void listAllUsers();
void AddUser(const char *codeCompany);
void modifyUser(const char *codeCompany);
void deleteUser(const char *codeCompany);

#endif