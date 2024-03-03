#include <stdio.h>

int main() {
    unsigned long N;
    scanf("%lu", &N);

    int i = 0;
    while (i<=N) {
        if (i % 3 == 0 && i % 5 == 0) {
            printf("fizz buzz\n");
        } else if (i % 5 == 0) {
            printf("buzz\n");
        } else if (i % 3 == 0) {
            printf("fizz\n");
        } else printf("%d\n", i);
        i++;
    }

    return 0;
}
