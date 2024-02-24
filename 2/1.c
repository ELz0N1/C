#include <stdio.h>

int x, y;

int main() {
    scanf("%d%d", &x, &y);
    if (y == 0) {
        printf("Second parameter can't be 0");
    } else{
        printf("%d + %d = %d\n", x, y, x + y);
        printf("%d - %d = %d\n", x, y, x - y);
        printf("%d * %d = %d\n", x, y, x * y);
        printf("%d / %d = %d\n", x, y, x / y);
        printf("%d %% %d = %d\n", x, y, x % y);
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
    }
    return 0;
}
