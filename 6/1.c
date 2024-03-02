#include <stdio.h>

void scanArr(int* arr, size_t length) {
    int numbers;
    for (int i = 0; i < length; i++) {
        *(arr + i)= scanf("%d", &numbers);
    }
}

void printArr(int* arr, size_t length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", *(arr+i));    
    }
    printf("\n");
}

void revertArr(int* arr, size_t length) {
    int* l = &arr[0];
    int* r = &arr[length];
    while (l != r) {
        int tmp = *l;
        *l = *r;
        *r = tmp;
        l++;
        r--;
    }
}

int maxInArr(int* arr, size_t length) {
    int max_elem = 0;
    for (int i = 0; i < length; i++) {
        if (*(arr+i) > max_elem) {
            max_elem = *(arr+i);
        }
    }
    return max_elem;
}

int findInArr(int* arr, size_t length, int target) {
    for (int i = 0; i < length; i++) {
        if (*(arr + i) == target) {
            return *(arr+i);
            break;
        }
    }
    return NULL;
}

//not finished...
void extractDigits(int* arr, size_t length, int X) {
    int tmp = X, len_X = -1;
    
    while (tmp > 0) {
        len_X += 1;
        tmp /= 10;
    }

    for (int i = len_X; i>= 0; i--) {

    }

}

int compareArrays(int* arr1, int* arr2, size_t len_arr1, size_t len_arr2) {
    for (int i = 0; i < len_arr1; i++) {
        for (int j = 0; j < len_arr2; j++) {
            if (*(arr1 + i) == *(arr2 + j)) {
                continue;
            } else if (*(arr1 + i) > *(arr2 + j)) {
                return -1;
            } else {
                return 1;
            }

        }
    }
    return 0;
}

int main(){
    int Array1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len_Array1 = 10;
    int Array2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len_Array2 = 10;
    int target = 5, X = 12345;

    scanArr(Array1, len_Array1);
    printArr(Array1, len_Array1);
    revertArr(Array1, len_Array1);
    maxInArr(Array1, len_Array1);
    findInArr(Array1, len_Array1, target);
    extractDigits(Array1, len_Array1, X);
    compareArrays(Array1, Array2, len_Array1, len_Array2);
    return 0;
}
