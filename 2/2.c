#include <stdio.h>

int main() {
    unsigned short number;
    scanf("%u", &number);

    if ((number % 4==0 && number%100!=0) || number%400==0) {
        printf("Весокосный год");
    } else {
        printf("Год не весокосный");
    }

    return 0;
}
