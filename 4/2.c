#include <stdio.h>
#include <assert.h>

int number_of_divisors(int number) {
    int count = 0;
    assert(number > 0);
    for (int i = 1; i <= number; i++) {
       if (number % i == 0) {
        count++;
       }
    }
    return count;
}

int main() {
    unsigned long long N;
    scanf("%llu", &N);
    
    int result = number_of_divisors(N);
    printf("%d", result);
    
    return 0;
}
