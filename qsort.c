#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 1000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1); // Index of smaller element
    int j;
    for (j=low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        #pragma omp parallel sections
        {
            #pragma omp section
            quicksort(arr, low, pi - 1); // Sort left partition

            #pragma omp section
            quicksort(arr, pi + 1, high); // Sort right partition
        }
    }
}

int main() {
    int arr[SIZE];

    // Initialize array with random numbers
    int i;
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000; // Random numbers between 0 and 999
    }

    printf("Unsorted array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Perform QuickSort
    quicksort(arr, 0, SIZE - 1);

    printf("Sorted array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}