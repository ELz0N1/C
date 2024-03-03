#include <stdio.h>

int main() {
    unsigned long L, R;
    scanf("%lu%lu", &L, &R);
    if (L > R) {
        printf("Error");
    } else { 
        for (int i = L; i < R; i++) {
            if ((L>=100000 && R<=999999) && (i % 1000) == (i / 1000)) {
                printf("%d ", i);
            }
        }
    }
    return 0;
}
