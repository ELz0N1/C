#include <stdio.h>
#include <stdlib.h>

void nullCheck (void* ptr) {
    if (ptr == NULL) {
        printf("Out of memory!");
        exit(0);
    }
}

void printArr(int* arr, size_t length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", *(arr + i));    
    }
    printf("\n");
}

int* concat(int* array1, int* array2, size_t* size1, size_t* size2, size_t* new_len) {
    *new_len = (*size1) + (*size2);
	int *result_arr = (int*)malloc(*new_len * sizeof(int));
	nullCheck(result_arr);
    
	for (size_t i = 0; i < *size1; i++) {
		result_arr[i] = array1[i];
	}
  
	for (size_t i = *size1; i < *new_len; i++) {
		result_arr[i] = array2[i - (*size1)];
	}
  
    return result_arr;
}

int main() {
    size_t len_Array1, len_Array2;
    
    scanf("%zu", &len_Array1);
    int *Array1 = (int*)malloc(len_Array1 * sizeof(int));
    nullCheck(Array1);
    for (size_t i = 0; i < len_Array1; i++) scanf("%d", &Array1[i]);

    scanf("%zu", &len_Array2);
    int *Array2 = (int*)malloc(len_Array2 * sizeof(int));
    nullCheck(Array2);
    for (size_t i = 0; i < len_Array2; i++) scanf("%d", &Array2[i]);
    
    
    size_t result_len;
    int *result_Array = concat(Array1, Array2, &len_Array1, &len_Array2, &result_len);
    printArr(result_Array, result_len);

    free(Array1);
    free(Array2);
    free(result_Array);

    return 0;
}
