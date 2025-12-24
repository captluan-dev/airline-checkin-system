#ifndef UTILS_H
#define UTILS_H

void removeNewLine(char *str);
int flightQuantity();
void clearInputBuffer(void);
int readInt(const char *msg);
void readString(const char *msg, char *dest, int size);

#endif