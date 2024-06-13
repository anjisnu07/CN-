#include <stdio.h>

// Function to calculate the number of parity bits required
int calculateParityBits(int m) {
    int r = 1;
    while ((1 << r) < (m + r + 1)) {
        r++;
    }
    return r;
}

// Function to calculate the Hamming code
void calculateHammingCode(int *data, int m, int *hammingCode) {
    int r = calculateParityBits(m);
    int n = m + r;
    int i, j, k;

    // Initialize Hamming code with data bits
    for (i = 0, j = 0, k = 0; i < n; i++) {
        if ((i + 1) == (1 << j)) {
            hammingCode[i] = 0; // Parity bit
            j++;
        } else {
            hammingCode[i] = data[k++]; // Data bit
        }
    }

    // Calculate parity bits
    for (i = 0; i < r; i++) {
        int parityIndex = (1 << i) - 1;
        int parity = 0;
        for (j = parityIndex; j < n; j += (1 << (i + 1))) {
            for (k = 0; k < (1 << i); k++) {
                if ((j + k) < n) {
                    parity ^= hammingCode[j + k];
                }
            }
        }
        hammingCode[parityIndex] = parity;
    }
}

// Function to correct errors in the received Hamming code
void correctError(int *receivedCode, int n) {
    int r = calculateParityBits(n);
    int i, j, k;
    int errorIndex = 0;

    // Calculate the error position
    for (i = 0; i < r; i++) {
        int parityIndex = (1 << i) - 1;
        int parity = 0;
        for (j = parityIndex; j < n; j += (1 << (i + 1))) {
            for (k = 0; k < (1 << i); k++) {
                if ((j + k) < n) {
                    parity ^= receivedCode[j + k];
                }
            }
        }
        errorIndex |= (parity << i);
    }

    // Correct the error if detected
    if (errorIndex != 0) {
        printf("Error at position: %d\n", errorIndex);
        receivedCode[errorIndex - 1] ^= 1;
        printf("Corrected code: ");
        for (i = 0; i < n; i++) {
            printf("%d", receivedCode[i]);
        }
        printf("\n");
    } else {
        printf("No error detected\n");
    }
}

int main() {
    int data[] = {1, 0, 1, 0}; // Example data bits
    int m = sizeof(data) / sizeof(data[0]);
    int r = calculateParityBits(m);
    int n = m + r;
    int hammingCode[n];

    printf("Original data: ");
    for (int i = 0; i < m; i++) {
        printf("%d", data[i]);
    }
    printf("\n");

    calculateHammingCode(data, m, hammingCode);

    printf("Hamming code: ");
    for (int i = 0; i < n; i++) {
        printf("%d", hammingCode[i]);
    }
    printf("\n");

    // Simulating error
    hammingCode[2] ^= 1; // Introducing an error

    printf("Received code with error: ");
    for (int i = 0; i < n; i++) {
        printf("%d", hammingCode[i]);
    }
    printf("\n");

    correctError(hammingCode, n);

    return 0;
}