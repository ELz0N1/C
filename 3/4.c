#include <stdio.h>

int main() {
    unsigned long long N;
    scanf("%d", &N);

    if (N < 2) {
        printf("Error");
    } else {
        int count = 0;
        int i = 1;
        while (i <= N) {
            if (N % i == 0) count++;
            i++;
        }
        if (count == 2) {
            printf("Простое");
        } else {
            printf("Сложное");
        }
    }
    return 0;
}