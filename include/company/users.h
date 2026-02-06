#ifndef USERS_H
#define USERS_H

void listUsers(int user);
void AddUser(const char *codeCompany);
void clearInputBuffer();
void removeNewLine(char *str);
void modifyUser(const char *codeCompany);
int readInt(const char *msg);
void deleteUser(const char *codeCompany);

#endif