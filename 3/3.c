#include <stdio.h>

int main() {
    unsigned long N;
    scanf("%lu", &N);

    for (int i = 0; i < ((N*(N+1))/2)-1; i++) {
        if (i % N == 0) printf("\n");
        printf("%d ", i);
    }

    return 0;
}
