#include <stdio.h>

int main() {
    unsigned long long N;
    scanf("%d", &N);

    if (N < 2) {
        printf("Error");
    } else {
        for (int i = 2; i <= N; i++) {
            int count = 0;
            int j = 1;
            while (j <= i) {
                if (i % j == 0) count++;
                j++;
            }
            if (count == 2) printf("%d ", i);
        }
    }
    return 0;
}