#include <stdio.h>
#include <stdlib.h>

void nullCheck(void* ptr) {
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

    int result = findSubArr(Array1, Array2, &len_Array1, &len_Array2);
    printf("%d\n", result);

    free(Array1);
    free(Array2);

    return 0;
}