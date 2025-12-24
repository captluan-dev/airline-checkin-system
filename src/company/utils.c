#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "company/utils.h"

void removeNewLine(char *str) { //str = data
    
    str[strcspn(str, "\n")] = '\0';
}

int flightQuantity() {

    int id;
    int biggestID = 0;
    char line[200];

    FILE *file;
    file = fopen("data\\Company Users\\DataFlights.txt", "r");

    if (file == NULL) {
        return 0;
    }

    while(fgets(line, 200, file)) {

        if (sscanf(line, "%d", &id) == 1) {

        if (id > biggestID)
            biggestID = id;
        }
    }

    fclose(file);
    return biggestID;
}

int readInt(const char *msg) {
    
    char buffer[32];
    int value;

    while (1) {
        printf("%s", msg);

        if (!fgets(buffer, sizeof(buffer), stdin))
            return -1;

        if (buffer[0] == '\n')
            continue;

        if (sscanf(buffer, "%d", &value) == 1)
            return value;

        printf("Invalid number. Try again.\n");
    }
}


void clearInputBuffer() {

    int c;

    while ((c = getchar()) != '\n' && c != EOF);
}

void readString(const char *msg, char *dest, int size) {
    printf("%s", msg);

    if (fgets(dest, size, stdin)) {
        dest[strcspn(dest, "\n")] = '\0';
    }
}