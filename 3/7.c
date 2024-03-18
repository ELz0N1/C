#include <stdio.h>

int main() {
    unsigned int N, input, y_pos = 0, x_pos = 0;
    unsigned long score = 0;

    printf("Enter the size of the game field: ");
    scanf("%d", &N);
    if (N < 2) {
        printf("Error: field is too small!");
        return 0;
    }

    while (1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == y_pos && j == x_pos) {
                    printf("😶 ");
                } else if (i == N - 1 && j == N - 1) {
                    printf("🍒");
                } else {
                    printf(" • ");
                }
            }
            printf("\n");
        }
        printf("\n");

        if (y_pos == N - 1 && x_pos == N - 1) {
            break;
        }
        
        printf("Score: %ld; Enter next step: ", score);
        scanf("%d", &input);
        if (input == 8 && y_pos != 0) {
            y_pos--;
        } else if (input == 4 && x_pos != 0) {
            x_pos--;
        } else if (input == 5 && y_pos != N - 1) {
            y_pos++;
        } else if (input == 6 && x_pos != N - 1) {
            x_pos++;
        } else {
            printf("Invalid value!\n");
            continue;
        }
        score++;
    }
    printf("Victory! Number of score: %ld!", score);
    return 0;
}
