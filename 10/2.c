#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nullCheck(void* ptr) {
    if (ptr == NULL) {
        printf("Out of memory!");
        exit(0);
    }
}

char* trim(const char* str) {
    size_t i = 0, j = strlen(str) - 1;

    while (i < strlen(str) && str[i] == ' ') {
        i++;
    }

    if (i == strlen(str)) {
        return NULL;
    }

    while (j >= 0 && str[j] == ' ') {
      j--;
    }

    char* trimstr = (char*)malloc(sizeof(char) * (j - i + 2));
    for (size_t k = 0; k <= j - i; k++) {
        trimstr[k] = str[k + i];
    }
    trimstr[j - i + 1] = '\0';

    return trimstr;
}

int main() {
    const char* string = "      ab a    aa      ";
    printf("%s\n", string);

    char* result = trim(string);
    printf("%s\n", result);

    free(result);
    return 0;
}