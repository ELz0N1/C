#include <stdio.h>

void func1() {
    int number;
    printf("%p", &number);
}

void func2() {
    func1();
}

int main() {
    func1();
    func2();    
    return 0;
}