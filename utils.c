#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


char* sfgets(char* str, int size) {
	char *ret = fgets(str, size, stdin); /* to avoid compiler warning */

	if (ret == NULL) /* did fgets fail? */
		return ret;

    fflush(stdin);
    str[strlen(str) - 1] = '\0';
    return str;
}

void wait(unsigned int secs) {
    int count = time(0) + secs;
    while (time(0) < count);
}
