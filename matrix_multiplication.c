#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100 // Define the size of the matrices

void matrix_multiply(int a[N][N], int b[N][N], int c[N][N]) {
    int i, j, k;

    #pragma omp parallel for private(j, k)
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            c[i][j] = 0; // Initialize the result cell
            for (k = 0; k < N; k++) {
                c[i][j] += a[i][k] * b[k][j]; // Perform multiplication and addition
            }
        }
    }
}

int main() {
    int a[N][N], b[N][N], c[N][N];
    int i,j;
    
    // Initialize matrices a and b with random values
    for (i = 0; i < N; i++) {
        for ( j = 0; j < N; j++) {
            a[i][j] = rand() % 10; // Random values between 0 and 9
            b[i][j] = rand() % 10; // Random values between 0 and 9
        }
    }

    // Perform matrix multiplication
    matrix_multiply(a, b, c);

    // Print the resulting matrix c
    printf("Resulting Matrix C after multiplication:\n");
    for (i = 0; i < N; i++) {
        for ( j = 0; j < N; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}