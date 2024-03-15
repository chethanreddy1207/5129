#include <stdio.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

void row_column_decrypt(const char *ciphertext, const char *key, char *plaintext) {
    int key_len = strlen(key);
    int cipher_len = strlen(ciphertext);

    // Calculate the number of rows required
    int rows = (cipher_len + key_len - 1) / key_len;

    // Create a 2D matrix to hold the ciphertext characters
    char matrix[MAX_ROWS][MAX_COLS];

    // Rearrange the characters according to the key
    for (int i = 0; i < key_len; i++) {
        int col = key[i] - '1';
        for (int j = 0; j < rows; j++) {
            matrix[j][col] = ciphertext[i * rows + j];
        }
    }

    // Reconstruct the plaintext from the matrix
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key_len; j++) {
            plaintext[index++] = matrix[i][j];
        }
    }
    plaintext[cipher_len] = '\0';
}

int main() {
    char ciphertext[] = "LHLO ELWOLRD";
    char key[] = "2314";
    char plaintext[MAX_ROWS * MAX_COLS];

    row_column_decrypt(ciphertext, key, plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Key: %s\n", key);
    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}

