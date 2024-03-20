#include <stdio.h>
#define N 3 
int determinant(int key[N][N], int n) 
{
    return key[0][0] * (key[1][1] * key[2][2] - key[2][1] * key[1][2]) -
           key[0][1] * (key[1][0] * key[2][2] - key[1][2] * key[2][0]) +
           key[0][2] * (key[1][0] * key[2][1] - key[1][1] * key[2][0]);
}
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}
void adjoint(int key[N][N], int adj[N][N]) {
    adj[0][0] = key[1][1] * key[2][2] - key[1][2] * key[2][1];
    adj[0][1] = key[0][2] * key[2][1] - key[0][1] * key[2][2];
    adj[0][2] = key[0][1] * key[1][2] - key[0][2] * key[1][1];
    adj[1][0] = key[1][2] * key[2][0] - key[1][0] * key[2][2];
    adj[1][1] = key[0][0] * key[2][2] - key[0][2] * key[2][0];
    adj[1][2] = key[0][2] * key[1][0] - key[0][0] * key[1][2];
    adj[2][0] = key[1][0] * key[2][1] - key[1][1] * key[2][0];
    adj[2][1] = key[0][1] * key[2][0] - key[0][0] * key[2][1];
    adj[2][2] = key[0][0] * key[1][1] - key[0][1] * key[1][0];
}
void inverse(int key[N][N], int inv[N][N]) {
    int det = determinant(key, N);
    int invDet = modInverse(det, 26);
    if (invDet == -1) {
        printf("Matrix is not invertible\n");
        return;
    }

    int adj[N][N];
    adjoint(key, adj);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            inv[i][j] = (adj[i][j] * invDet) % 26;

    if (invDet < 0)
        invDet += 26;
}
void decrypt(int cipher[], int key[N][N], int inv[N][N], int len) {
    int plain[len];

    for (int i = 0; i < len; i += N) {
        for (int j = 0; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += (inv[j][k] * cipher[i + k]) % 26;
            }
            plain[i + j] = sum % 26;
        }
    }

    printf("Decrypted Message: ");
    for (int i = 0; i < len; i++) {
        printf("%c", plain[i] + 'A');
    }
    printf("\n");
}

int main() {
    int key[N][N] = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}}; // Example key matrix
    int inv[N][N];
    inverse(key, inv);
    int len;
    printf("Enter the length of the message: ");
    scanf("%d", &len);
    int cipher[len];
    printf("Enter the encrypted message (numbers 0-25): ");
    for (int i = 0; i < len; i++) 
	{
        scanf("%d", &cipher[i]);
    }
    decrypt(cipher, key, inv, len);
    return 0;
}

