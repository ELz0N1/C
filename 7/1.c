#include <stdio.h>

int main() {
    int array[4][4];
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    for (size_t i = 0; i < 4; i++) {
        for (size_t j = i; j < 4; j++) {
            int tmp = array[i][j];
            array[i][j] = array[j][i];
            array[j][i] = tmp;
        }
    }

    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
