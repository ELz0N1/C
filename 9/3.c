#include <stdio.h>
#include <stdlib.h>

void nullCheck (void* ptr) {
    if (ptr == NULL) {
        printf("Out of memory!");
        exit(0);
    }
}

int* findSubArr(int* arr1, int* arr2, size_t* size1, size_t* size2) {
    int k;
	for (size_t i = 0; i < *size1 - 1; i++) {
        k = i;
		for (size_t j = 0; j < *size2 - 1 ; j++) {
            if ((arr1[k] == arr2[j]) && (arr1[k + 1] == arr2[j + 1])) {
                return &arr1[k];
            }
            k++;
        }
	}
    return NULL;
}

int removeSubArr(int* arr1, int* arr2, size_t size1, size_t size2) {
    int* subarr;
    while ((subarr = findSubArr(arr1, arr2, &size1, &size2))) {
        size1-=size2;
        for (size_t i =0; i < size1; i++) {
            subarr[i] = subarr[i + size2];
        }
    }
    arr1 = (int*)realloc(arr1, size1*sizeof(int));
    nullCheck(arr1);
    return size1;
}

void printArr(int* arr, size_t length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", *(arr + i));    
    }
    printf("\n");
}

int main() {
    size_t len_Array1, len_Array2;

    scanf("%zu", &len_Array1);
    int *Array1 = (int*)malloc(len_Array1 * sizeof(int));
    nullCheck(Array1);
    for (size_t i = 0; i < len_Array1; i++) {
        scanf("%d", &Array1[i]);
    }

    scanf("%zu", &len_Array2);
    int *Array2 = (int*)malloc(len_Array2 * sizeof(int));
    nullCheck(Array2);
    for (size_t i = 0; i < len_Array2; i++) {
        scanf("%d", &Array2[i]);
    }

    len_Array1 = removeSubArr(Array1, Array2, len_Array1, len_Array2);
    printArr(Array1, len_Array1);

    free(Array1);
    free(Array2);

    return 0;
}