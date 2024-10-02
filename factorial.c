#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// Function to calculate factorial recursively
long long factorial(int n) {
    if (n == 0) // Base case: 0! = 1
        return 1;
    else
        return n * factorial(n - 1); // Recursive call
}

int main(int argc, char *argv[]) {
    if (argc != 2) { // Check for the correct number of arguments
        printf("Usage: %s <non-negative integer>\n", argv[0]);
        return 1;
    }

    int number = atoi(argv[1]); // Convert argument to integer

    if (number < 0) { // Check if the number is negative
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }

    long long result;

    // Parallel region for calculating factorial
    #pragma omp parallel
    {
        #pragma omp single // Only one thread executes this block
        {
            result = factorial(number); // Calculate factorial
        }
    }

    printf("Factorial of %d is %lld\n", number, result); // Print result

    return 0;
}