#include <stdio.h>
#include <omp.h>

int main() {
    // OpenMP parallel region starts here
    #pragma omp parallel
    {
        // Get the total number of threads in the current team
        int num_threads = omp_get_num_threads();
        
        // Get the thread number (0-indexed) of the current thread
        int thread_num = omp_get_thread_num();
        
        // Print "Hello, World!" with thread information
        printf("Hello, World! I'm thread %d out of %d threads.\n", thread_num, num_threads);
    } // OpenMP parallel region ends here
    
    return 0;
}
