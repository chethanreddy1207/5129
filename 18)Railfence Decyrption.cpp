#include <stdio.h>
#include <string.h>
void railFenceDecrypt(char *encryptedText, int rails, char *decryptedText) {
    int length = strlen(encryptedText);
    int railLength = rails * 2 - 2;
    int index = 0;
    int railCounts[rails];
    for (int i = 0; i < rails; i++) {
        railCounts[i] = 0;
    }
    for (int i = 0; i < length; i++) {
        int rail = i % railLength;
        if (rail < rails)
            railCounts[rail]++;
        else
            railCounts[railLength - rail]++;
    }
    for (int i = 0; i < rails; i++) {
        int step = railLength - 2 * i;
        int count = railCounts[i];
        for (int j = i; j < length; j += railLength) {
            decryptedText[j] = encryptedText[index++];
            if (step && i != rails - 1 && j + step < length)
                decryptedText[j + step] = encryptedText[index++];
        }
        decryptedText += count;
    }
    decryptedText[length] = '\0'; 
}

int main() {
    char encryptedText[100], decryptedText[100];
    int rails;
    printf("Enter the encrypted text: ");
    fgets(encryptedText, sizeof(encryptedText), stdin);
    printf("Enter the number of rails: ");
    scanf("%d", &rails);
    railFenceDecrypt(encryptedText, rails, decryptedText);
    printf("Decrypted text: %s\n", decryptedText);
    return 0;
}

