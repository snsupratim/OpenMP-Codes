#include <stdio.h>
#include <omp.h>

int main() {
    double pi;

    // Parallel region starts
    #pragma omp parallel
    {
        // Only one thread will execute this block
        #pragma omp single
        {
            pi = 22.0 / 7.0;
            printf("The value of Pi using 22/7 approximation is: %f\n", pi);
        }
    } // Parallel region ends

    return 0;
}
