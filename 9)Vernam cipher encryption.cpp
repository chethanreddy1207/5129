#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vernam_encrypt(const char *plaintext, const char *key, char *ciphertext) {
    int plain_len = strlen(plaintext);
    int key_len = strlen(key);
    
    // Repeat the key if it's shorter than the plaintext
    for (int i = 0; i < plain_len; ++i) {
        ciphertext[i] = plaintext[i] ^ key[i % key_len]; // XOR operation between plaintext and key
    }
    ciphertext[plain_len] = '\0';
}

int main() {
    char plaintext[] = "Hello, World!";
    char key[] = "RANDOMKEY";
    char ciphertext[100];

    vernam_encrypt(plaintext, key, ciphertext);
    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);
    printf("Ciphertext: ");
    for(int i = 0; i < strlen(plaintext); i++){
        printf("%02X ", (unsigned char)ciphertext[i]); // Print ciphertext as hexadecimal
    }
    printf("\n");

    return 0;
}

