#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

void companyLogin();
int userValidation(char companyCode[], char userLogin[], char password[]);
void menuAdmin(const char *companyCode);
void menuUser(const char *companyCode);
void companyRegistration();
void removeNewLine(char *str);
int registrationDataValidation(char companyCode[], char companyName[], char userAdmin[], char passwordAdmin[]);
void readString(const char *msg, char *dest, int size);

#endif