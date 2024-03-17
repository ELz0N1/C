#include <stdio.h>
#include <stdlib.h>

void nullCheck (void* ptr) {
    if (ptr == NULL) {
        printf("Out of memory!");
        exit(0);
    }
}

int* scanArr(size_t* length, size_t* capacity) {
    int* arr = (int*)malloc((*capacity) * sizeof(int));
    nullCheck(arr);
    
    do {
        scanf("%d", &arr[*length]);
        (*length)++;
        if (*length == *capacity){
            *capacity *= 2;
            arr = (int*)realloc(arr, (*capacity) * sizeof(int));
            nullCheck(arr);
        }
    } while (*(arr + *length - 1) != 0);
    return arr;
}

void printArr(int *arr, size_t len) {
	for (size_t i = 0; i < len; i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");
}

int main () {
    size_t length = 0, capacity = 1;
    
    int* array = scanArr(&length, &capacity);
    printArr(array, length);

    free(array);
    return 0;
}