#include <stdio.h>

void evil_scanf(int* P0, int* P1, int* P2) {
    int N0, N1, N2;
    scanf("%d%d%d", &N0, &N1, &N2);
    *P0 = N0;
    if (N0 > 0) {
        *P1 = N1;
        *P2 = N2;
    } else {
        *P1 = *P0;
        *P2 = N0 * N1 * N2 * (*P1) * (*P2);
    }

}

int main() {
    int A = 1, B = 2, C = 3;
    evil_scanf(&A, &B, &C);
    printf("%d %d %d", A, B, C);

    return 0;
}