#include <stdio.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

void row_column_encrypt(const char *plaintext, const char *key, char *ciphertext) {
    int key_len = strlen(key);
    int plain_len = strlen(plaintext);

    // Calculate the number of rows required
    int rows = (plain_len + key_len - 1) / key_len;

    // Create a 2D matrix to hold the plaintext characters
    char matrix[MAX_ROWS][MAX_COLS];

    // Fill the matrix with the plaintext characters
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key_len; j++) {
            if (index < plain_len) {
                matrix[i][j] = plaintext[index++];
            } else {
                matrix[i][j] = ' '; // Padding with spaces if necessary
            }
        }
    }

    // Rearrange the characters according to the key
    for (int i = 0; i < key_len; i++) {
        int col = key[i] - '1';
        for (int j = 0; j < rows; j++) {
            ciphertext[i * rows + j] = matrix[j][col];
        }
    }
    ciphertext[plain_len] = '\0';
}

int main() {
    char plaintext[] = "HELLO WORLD";
    char key[] = "2314";
    char ciphertext[MAX_ROWS * MAX_COLS];

    row_column_encrypt(plaintext, key, ciphertext);
    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

