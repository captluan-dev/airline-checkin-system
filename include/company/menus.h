#ifndef MENUS_H
#define MENUS_H

void menuAdmin(const char *code);
void createFlight(const char *code);
void modifyFlight(const char *code);
void deleteFlight(const char *code);
void manageFlights(const char *code);
void manageUsers(const char *code);
void menuUser(const char *code);
void clearInputBuffer();
int readInt(const char *msg);

#endif