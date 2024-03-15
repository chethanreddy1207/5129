#include <stdio.h>
#include <string.h>

void vernam_decrypt(const char *ciphertext, const char *key, char *plaintext) {
    int cipher_len = strlen(ciphertext);
    int key_len = strlen(key);

    // Repeat the key if it's shorter than the ciphertext
    for (int i = 0; i < cipher_len; ++i) {
        plaintext[i] = ciphertext[i] ^ key[i % key_len]; // XOR operation between ciphertext and key
    }
    plaintext[cipher_len] = '\0';
}

int main() {
    char ciphertext[] = {0x0C, 0x1C, 0x0B, 0x18, 0x11, 0x05, 0x14, 0x11, 0x16, 0x15, 0x11, 0x0B, 0x15, 0x19, 0x09, 0x0C, 0x05, 0x1B, 0x0D, 0x11, 0x17, 0x0C};
    char key[] = "RANDOMKEY";
    char plaintext[100];

    vernam_decrypt(ciphertext, key, plaintext);
    printf("Ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++){
        printf("%02X ", (unsigned char)ciphertext[i]); // Print ciphertext as hexadecimal
    }
    printf("\n");
    printf("Key: %s\n", key);
    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}

