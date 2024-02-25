#include <stdio.h>

int x, y;

int main() {
    scanf("%d%d", &x, &y);

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

    return 0;
}