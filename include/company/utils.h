#ifndef UTILS_H
#define UTILS_H

void removeNewLine(char *str);
int userValidation(char companyCode[], char userLogin[], char password[]);
int registrationDataValidation(char companyCode[], char companyName[], char userAdmin[], char passwordAdmin[]);

#endif