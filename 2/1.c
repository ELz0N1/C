#include <stdio.h>

int x, y;

int main() {
    scanf("%d%d", &x, &y);
    
    printf("%d + %d = %d\n", x, y, x + y);
    printf("%d - %d = %d\n", x, y, x - y);
    printf("%d * %d = %d\n", x, y, x * y);
    printf("%d == %d = %d\n", x, y, x == y);
    printf("%d != %d = %d\n", x, y, x != y);
    printf("%d < %d = %d\n", x, y, x < y);
    printf("%d > %d = %d\n", x, y, x > y);
    printf("%d <= %d = %d\n", x, y, x <= y);
    printf("%d >= %d = %d\n", x, y, x >= y);
    printf("%d && %d = %d\n", x, y, x && y);
    printf("%d || %d = %d\n", x, y, x || y);
    printf("%d & %d = %d\n", x, y, x & y);
    printf("%d | %d = %d\n", x, y, x | y);
    printf("%d ^ %d = %d\n", x, y, x ^ y);
    printf("%d << %d = %d\n", x, y, x << y);
    printf("%d >> %d = %d\n", x, y, x >> y);
    printf("!%d = %d\n", x, !x);
    printf("~%d = %d\n", x, ~x);
    printf("-%d = %d\n", x, -x);
    
    if (y == 0) {
        printf("Division by zero is undefined\n");
    } else {
        printf("%d / %d = %d\n", x, y, x / y);
        printf("%d %% %d = %d\n", x, y, x % y);
    }
    
    
    return 0;
}
