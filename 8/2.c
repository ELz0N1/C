#include <stdio.h>
#include <stdlib.h>

void nullCheck (void* ptr) {
    if (ptr == NULL) {
        printf("Out of memory!");
        exit(0);
    }
}

void scanArr(int* arr, size_t length) {
    for (int i = 0; i < length; i++) {
        scanf("%d", &(*(arr + i)));
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
    int* r = &arr[length - 1];
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
            return i;
            break;
        }
    }
    return -1;
}

void extractDigits(int* arr, size_t length, int X) {
    int tmp = X, len_X = -1;
    
    while (tmp) {
        len_X += 1;
        tmp /= 10;
    }
    
    if (len_X == -1) len_X = 0;
    
    for (int i = len_X; i>= 0; i--) {
        arr[i] = X % 10;
        X /= 10;
    }
}

int compareArrays(int* arr1, int* arr2, size_t len_arr1, size_t len_arr2) {
    size_t min_len = (len_arr1 < len_arr2) ? len_arr1 : len_arr1;
    for (int i = 0; i < min_len; i++) {
        if (*(arr1 + i) > *(arr2 + i)) {
            return -1;
        } else if (*(arr1 + i) < *(arr2 + i)) {
            return 1;
        } else {
            continue;
        }
    }
    return 0;
}

int main() {
    printf("Enter your array: ");
    size_t N = 2;
    int* arr = (int*) malloc(N * sizeof(int));
    nullCheck(arr);
    for(size_t i = 0;; i++) {
        int input;
        scanf("%d", &input);
        if (input == 0) {
            N = i;
            break;
        }
        if (i + 1 < N) {
            arr[i] = input;
            continue;
        }
        arr[i] = input;
        int* new_arr = (int*) malloc(2 * N * sizeof(int));
        nullCheck(new_arr);
        for (int j=0; j < N; j++) {
            new_arr[j] = arr[j];
        }
        N *= 2;
        free(arr);
        arr = new_arr;
    }

    printf("Entered array: ");
    printArr(arr, N);

    revertArr(arr, N);
    printf("Reversed array: ");
    printArr(arr, N);
    revertArr(arr, N); //возвращение к исходному

    int result;
    result = maxInArr(arr, N);
    printf("Max: %d\n", result);

    int target;
    printf("Enter element to find: ");
    scanf("%d", &target);
    result = findInArr(arr, N, target);
    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element %d index is %d\n", target, result);
    }

    if (N < 0)
        printf("Not able to perform extractDigits function for this array\n");
    else {
        int X;
        int arr_copy[N];
        for (size_t i = 0; i < N; i++) arr_copy[i] = arr[i];
        printf("Enter your digits: ");
        scanf("%d", &X);
        extractDigits(arr_copy, N, X);
        printf("Array with %d extracted:", X);
        printArr(arr_copy, N);
    }

    printf("Enter length of array to compare: ");
    int len_Array2;
    scanf("%d", &len_Array2);
    printf("Enter elements of array to compare: ");
    int Array2[len_Array2];
    scanArr(Array2, len_Array2);

    result = compareArrays(arr, Array2, N, len_Array2);
    if (result == -1) {
        printf("First array is greater");
    } else if (result == 1) {
        printf("Second array is greater");
    } else {
        printf("Arrays are equal");
    }
        
    free(arr);
    return 0;
}