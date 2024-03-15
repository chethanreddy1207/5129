#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

char matrix[SIZE][SIZE];

void generateMatrix(char key[]) {
    char alphabet[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; 
    int len = strlen(key);
    int i, j, k = 0;
    int used[26] = {0};
    for (i = 0; i < len; i++) {
        if (!used[toupper(key[i]) - 'A']) {
            matrix[k / SIZE][k % SIZE] = toupper(key[i]);
            used[toupper(key[i]) - 'A'] = 1;
            k++;
        }
    }
    for (i = 0; i < 26; i++) {
        if (!used[i]) {
            matrix[k / SIZE][k % SIZE] = alphabet[i];
            k++;
        }
    }
}
void decrypt(char text[]) {
    int i, j;
    for (i = 0; i < strlen(text); i += 2) {
        int row1, col1, row2, col2;
        char ch1 = toupper(text[i]);
        char ch2 = toupper(text[i + 1]);
        for (j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                if (matrix[j][k] == ch1) {
                    row1 = j;
                    col1 = k;
                }
                if (matrix[j][k] == ch2) {
                    row2 = j;
                    col2 = k;
                }
            }
        }
		if (row1 == row2) {
            printf("%c%c", matrix[row1][(col1 - 1 + SIZE) % SIZE], matrix[row2][(col2 - 1 + SIZE) % SIZE]);
        } else if (col1 == col2) {
            printf("%c%c", matrix[(row1 - 1 + SIZE) % SIZE][col1], matrix[(row2 - 1 + SIZE) % SIZE][col2]);
        } else {
            printf("%c%c", matrix[row1][col2], matrix[row2][col1]);
        }
    }
}
int main() {
    char key[100];
    char ciphertext[100];
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';
    printf("Enter the ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);
    ciphertext[strcspn(ciphertext, "\n")] = '\0';
    generateMatrix(key);
    decrypt(ciphertext);
    return 0;
}

