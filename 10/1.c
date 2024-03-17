#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int palindrome(const char* str) {
    size_t j = strlen(str);

    for (size_t i = 0; i <= (j / 2); i++) {
        j--;
        if (str[i] == str[j]) {
            continue;
        } else if (str[i] == ' ') {
            i++;
        } else if (str[j] == ' ') {
            j--;
        } else {
            return -1;
        }
    }
    return 0;
}

int main() {
    const char *string = "ababababa";

    int result = palindrome(string);
    if (result == 0) {
        printf("palindrome");
    } else {
        printf("not palindrome");
    }

    return 0;
}
