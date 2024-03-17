#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <setjmp.h>

#define OVERFLOW_ERROR 1
#define INVALID_SYMBOL_ERROR 2


void nullCheck(void *ptr) {
    if (ptr == NULL) {
        printf("Out of memory");
        exit(0);
    }
}

void exception(int error_code, jmp_buf buf) {
    if (buf != NULL) {
        longjmp(buf, error_code);
    } else {
        exit(error_code);
    }
}

int charToDigit(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else {
        return c - 'A' + 10;
    }
}

int s2i(const char *src, unsigned int base, jmp_buf buf) {
    assert(base <= 16);

    int sign = 1;
    if (*src == '-') {
        sign = -1;
        src++;
    }

    char* valid_symbols = calloc(16, sizeof(char));
    nullCheck(valid_symbols);
    
    char i = 0;
    while ((i < base) && (i < 10)) {
        valid_symbols[i] = '0' + i;
        i++;
    }
    while (i < base) {
        valid_symbols[i] = 'A' + i - 10;
        i++;
    }

    long long result = 0;
    for(const char *i = src; *i != 0; i++) {
        char* digit = strchr(valid_symbols, *i);
        if (digit == NULL) {
            exception(INVALID_SYMBOL_ERROR, buf);
        }
        result *= base;
        result += charToDigit(*i);
        if (INT_MAX < result || result < INT_MIN) {
            exception(OVERFLOW_ERROR, buf);
        }
    }
    result *= sign;
    return result;
}

int main() {
    jmp_buf buf;
    setjmp(buf);
    printf("10101001; base = 2 is %d\n", s2i("10101001", 2, buf));
    printf("BF; base = 16 is %d\n", s2i("BF", 16, buf));
    
    int errorCode = setjmp(buf);
    if (errorCode == 0)
        s2i("996687655443", 10, buf);
    else if (errorCode == 1) {
        printf("Overflow error\n");
    }

    errorCode = setjmp(buf);
    if (errorCode == 0)
        s2i("xncvbm^#$", 10, buf);
    else if (errorCode == 2) {
        printf("Invalid symbol error\n");
    }

    return 0;
}