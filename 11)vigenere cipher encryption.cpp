#include <stdio.h>
#include <string.h>
#include <ctype.h>
void vigenere_encrypt(const char *plaintext, const char *key, char *ciphertext) {
    int plain_len = strlen(plaintext);
    int key_len = strlen(key);
    for (int i = 0, j = 0; i < plain_len; ++i) {
        if (isalpha(plaintext[i])) {
            char shift = isupper(plaintext[i]) ? 'A' : 'a';
            char key_char = toupper(key[j % key_len]);
            char plain_char = toupper(plaintext[i]);
            ciphertext[i] = ((plain_char - 'A' + key_char - 'A') % 26) + shift;
            ++j;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[plain_len] = '\0';
}
int main() {
    char plaintext[] = "Hello, World!";
    char key[] = "KEY";
    char ciphertext[100];
    vigenere_encrypt(plaintext, key, ciphertext);
    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}

