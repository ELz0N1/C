#include <stdio.h>
#include <assert.h>

int GCD(int x, int y) {
    int max_divisor = 0;
    assert(x >= 0);
    assert(y >= 0);


    for (int i = 1; i <= x; i++) {
        if (x % i == 0 && y % i == 0) {
            if (max_divisor <  i) {
                max_divisor = i;
            }
        }
    }
    return max_divisor;
}

int main() {
    int A, B;
    scanf("%d%d", &A, &B);
    
    int result = GCD(A, B);
    printf("%d", result);
    
    return 0;
}