#include <stdio.h>
#include <string.h>
#include <time.h>

char* sfgets(char* str, int size) {
    fgets(str, size, stdin);
    fflush(stdin);
    str[strlen(str) - 1] = '\0';
    return str;
}

int wait(unsigned int secs) {
    int count = time(0) + secs;
    while (time(0) < count);
    return 1;
}
