#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vigenere_decrypt(const char *ciphertext, const char *key, char *plaintext) {
    int cipher_len = strlen(ciphertext);
    int key_len = strlen(key);
    
    for (int i = 0, j = 0; i < cipher_len; ++i) {
        if (isalpha(ciphertext[i])) {
            char shift = isupper(ciphertext[i]) ? 'A' : 'a';
            char key_char = toupper(key[j % key_len]);
            char cipher_char = toupper(ciphertext[i]);
            plaintext[i] = (((cipher_char - 'A') - (key_char - 'A') + 26) % 26) + shift;
            ++j;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[cipher_len] = '\0';
}

int main() {
    char ciphertext[] = "Jevpq, Wyvnd!";
    char key[] = "KEY";
    char plaintext[100];

    vigenere_decrypt(ciphertext, key, plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Key: %s\n", key);
    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}

