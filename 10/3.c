#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nullCheck(void* ptr) {
    if (ptr == NULL) {
        printf("Out of memory!");
        exit(0);
    }
}

char** split(const char *str, size_t *size, size_t *capacity) {
    char **splitted = malloc(sizeof(const char*));
    nullCheck(splitted);

    *size = 0;
    *capacity = 1;

    for (const char *i = str; *i != 0; i++) {
        if (*i == ' ') continue;
        
        const char *j = i;
        while (*j != ' ' && *j != 0)
            j++;

        char *substr = malloc((j - i + 1) * sizeof(char));
        nullCheck(substr);

        char *k = substr;
        for (; i < j; i++) {
            *k = *i;
            k++;
        }
        *k = 0;

        if (*size == *capacity) {
            splitted = realloc(splitted, (*capacity *= 2) * sizeof(const char*));
            nullCheck(splitted);
        }
        splitted[*size] = substr;
        (*size)++;
    }

    return splitted;
}

int main() {
    const char *string = " to be  splitted  ";
    size_t size, capacity;
    char **splitted = split(string, &size, &capacity);

    for (size_t i = 0; i < size; i++)
        if (i == size - 1) {
            printf("%s.", splitted[i]);
        } else{
            printf("%s, ", splitted[i]);
        }

    for (size_t i = 0; i < size; i++)
        free(splitted[i]);
    
    free(splitted);
    return 0;
}