#include <stdio.h>

#define N 3 
void encrypt(int message[], int key[N][N], int len) {
    int cipher[len];

    for (int i = 0; i < len; i += N) {
        for (int j = 0; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += key[j][k] * message[i + k];
            }
            cipher[i + j] = sum % 26;
        }
    }

    printf("Encrypted Message: ");
    for (int i = 0; i < len; i++) {
        printf("%c", cipher[i] + 'A');
    }
    printf("\n");
}

int main() {
    int key[N][N] = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}}; // Example key matrix
    int len;
    printf("Enter the length of the message: ");
    scanf("%d", &len);

    int message[len];
    printf("Enter the message (letters A-Z): ");
    for (int i = 0; i < len; i++) {
        char c;
        scanf(" %c", &c);
        message[i] = c - 'A';
    }

    encrypt(message, key, len);

    return 0;
}

