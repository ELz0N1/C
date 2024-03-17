#include <stdio.h>
#include <stdlib.h>

void nullCheck (void* ptr) {
    if (ptr == NULL) {
        printf("Out of memory!");
        exit(0);
    }
}

void createPascaleTriangle(int** arr, size_t size) {
    int** result = (int**)malloc(size * sizeof(int*));
    nullCheck(result);

    for (size_t i = 0; i < size; i++) {
        *(result + i) = (int*)malloc((i + 1) * sizeof(int));
        nullCheck(result);
    }
    *arr = result;
}

void fillPascaleTriangle(int** arr, size_t size) {
    *(*(arr + 0) + 0) = 1;
    for (size_t i = 1; i < size; i++) {
        *(*(arr + i) + 0) = 1;
        *(*(arr + i) + i) = 1;
        for (size_t j = 1; j < i; j++) {
            *(*(arr + i) + j) = *(*(arr+(i - 1))+(j - 1)) + *(*(arr + (i - 1)) + j);
        }
    }
}

void printPascaleTriangle(int** arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j <= i; j++) {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");    
    }
}

int main() {
    size_t size;
    scanf("%zu", &size);

    int** arr;
    createPascaleTriangle(&arr, size);
    fillPascaleTriangle(arr, size);
    printPascaleTriangle(arr, size);

    for (size_t i = 0; i < size; i++) {
        free(*(arr + i));
    }

    free(arr);
    return 0;
}