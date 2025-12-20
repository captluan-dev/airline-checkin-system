#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

void companyLogin();
int userValidation(char companyCode[], char userLogin[], char password[]);
void menuAdmin();
void companyRegistration();
void removeNewLine(char *str);
int registrationDataValidation(char companyCode[], char companyName[], char userAdmin[], char passwordAdmin[]);

#endif