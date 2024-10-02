#include <stdio.h>
#include <omp.h>

#define MAX_FIB 100

void generate_fibonacci(int *fib_sequence, int n) {
    if (n >= 1) fib_sequence[0] = 0; // First Fibonacci number
    if (n >= 2) fib_sequence[1] = 1; // Second Fibonacci number

    // Declare loop variable outside of the for loop
    int i;
    #pragma omp parallel for
    for (i = 2; i < n; i++) {
        fib_sequence[i] = fib_sequence[i - 1] + fib_sequence[i - 2];
    }
}

int main() {
    int fib_sequence[MAX_FIB];

    // Generate Fibonacci numbers up to the largest number less than or equal to 100
    generate_fibonacci(fib_sequence, MAX_FIB);
	int j;
    printf("Fibonacci numbers from 1 to 100:\n");
    for (j = 0; j < MAX_FIB; j++) {
        if (fib_sequence[j] > 100) break;
        printf("%d ", fib_sequence[j]);
    }
    printf("\n");

    return 0;
}