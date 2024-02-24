#include <stdio.h>
#include <assert.h>

int isPrime(int number) {
    assert(number >= 2);
    for (int i = 2; i <= number/2; i++) {
       if  (number % i == 0) {
        return 0;
       }
    return 1;
    }
}

int main() {
    unsigned long long N;
    scanf("%d", &N);
    
    for (int i = 2; i <= N; i++) {
        if (isPrime(i) == 1) {
            printf("%d ", i);
        }
    }
    
    return 0;
}
