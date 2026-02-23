#ifndef AUTHENTICATIONCLIENT_H
#define AUTHENTICATIONCLIENT_H

void clientRegistration();
void clientLogin();

void removeNewLine(char *str);
int dataClientValidation(char username[], char password[], char fullName[], char email[], char phoneNumber[]);
int loginValidation(char username[], char password[]);

#endif