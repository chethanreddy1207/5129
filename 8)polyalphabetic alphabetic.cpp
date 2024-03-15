#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generate_substitution_alphabets(char *keyword, char substitution_alphabets[26][26]) {
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int keyword_length = strlen(keyword);
    int i, j, k = 0;

    // Generate multiple substitution alphabets based on the keyword
    for (i = 0; i < keyword_length; i++) {
        char current_char = toupper(keyword[i]);
        if (current_char >= 'A' && current_char <= 'Z') {
            for (j = 0; j < 26; j++) {
                substitution_alphabets[i][j] = alphabet[(j + current_char - 'A') % 26];
            }
        }
    }
}

void polyalphabetic_encrypt(char *plaintext, char *keyword, char *ciphertext) {
    char substitution_alphabets[26][26];
    generate_substitution_alphabets(keyword, substitution_alphabets);
    int keyword_length = strlen(keyword);
    int plaintext_length = strlen(plaintext);
    int i, j;

    // Encrypt each character in the plaintext using the corresponding substitution alphabet
    for (i = 0, j = 0; i < plaintext_length; i++, j = (j + 1) % keyword_length) {
        char current_char = toupper(plaintext[i]);
        if (current_char >= 'A' && current_char <= 'Z') {
            ciphertext[i] = substitution_alphabets[j][current_char - 'A'];
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';
}

void polyalphabetic_decrypt(char *ciphertext, char *keyword, char *plaintext) {
    char substitution_alphabets[26][26];
    generate_substitution_alphabets(keyword, substitution_alphabets);
    int keyword_length = strlen(keyword);
    int ciphertext_length = strlen(ciphertext);
    int i, j;

    // Decrypt each character in the ciphertext using the corresponding substitution alphabet
    for (i = 0, j = 0; i < ciphertext_length; i++, j = (j + 1) % keyword_length) {
        char current_char = toupper(ciphertext[i]);
        if (current_char >= 'A' && current_char <= 'Z') {
            int index = strchr(substitution_alphabets[j], current_char) - substitution_alphabets[j];
            plaintext[i] = 'A' + index;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[i] = '\0';
}

int main() {
    char keyword[] = "CIPHER";
    char plaintext[] = "Hello, World!";
    char ciphertext[100];
    char decrypted_text[100];

    polyalphabetic_encrypt(plaintext, keyword, ciphertext);
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    polyalphabetic_decrypt(ciphertext, keyword, decrypted_text);
    printf("Decrypted Text: %s\n", decrypted_text);

    return 0;
}

