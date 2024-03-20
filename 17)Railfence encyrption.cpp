#include <stdio.h>
#include <string.h>
void railFenceEncrypt(char *plaintext, int rails, char *encryptedText) {
    int length = strlen(plaintext);
    int railLength = rails * 2 - 2;
    int index = 0;
    for (int i = 0; i < rails; i++) {
        int step = railLength - 2 * i;
        for (int j = i; j < length; j += railLength) {
            encryptedText[index++] = plaintext[j];
            if (step && i != rails - 1 && j + step < length)
                encryptedText[index++] = plaintext[j + step];
        }
    }
    encryptedText[index] = '\0';
	}
int main() {
    char plaintext[100], encryptedText[100];
    int rails;
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    printf("Enter the number of rails: ");
    scanf("%d", &rails);
    railFenceEncrypt(plaintext, rails, encryptedText);
    printf("Encrypted text: %s\n", encryptedText);
    return 0;
}

