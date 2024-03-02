#include <stdio.h>

int main() {
    unsigned int N, input, ypos = 0, xpos = 0;
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
                if (i == ypos && j == xpos) {
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

        if (ypos == N - 1 && xpos == N - 1) {
            break;
        }
        
        printf("Score: %ld; Enter next step: ", score);
        scanf("%d", &input);
        if (input == 8 && ypos != 0) {
            ypos--;
        } else if (input == 4 && xpos != 0) {
            xpos--;
        } else if (input == 5 && ypos != N - 1) {
            ypos++;
        } else if (input == 6 && xpos != N - 1) {
            xpos++;
        } else {
            printf("Invalid value!\n");
            continue;
        }
        score++;
    }
    printf("Victory! Number of score: %ld!", score);
    return 0;
}