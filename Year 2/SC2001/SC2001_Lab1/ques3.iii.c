

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_N 1000    // Minimum value of N
#define MAX_N 1000000 // Maximum value of N
#define STEP_N 1000   // Step size for varying N
#define S 10          // Fixed value of S

#ifndef SWAP_H
#define SWAP_H

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

#endif /* SWAP_H */

// Function to perform insertion sort
void insertionSort(int array[], int n, int *comparisons) {
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
            (*comparisons)++;
        }
        array[j + 1] = key;
    }
}

// Function to perform merge operation
void merge(int array[], int left[], int leftSize, int right[], int rightSize, int *comparisons) {
    int i = 0, j = 0, k = 0;
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            array[k++] = left[i++];
        } else {
            array[k++] = right[j++];
        }
        (*comparisons)++;
    }
    while (i < leftSize) {
        array[k++] = left[i++];
    }
    while (j < rightSize) {
        array[k++] = right[j++];
    }
}

// Function to perform hybrid merge sort
void hybridMergeSort(int array[], int n, int *comparisons) {
    if (n <= S) {
        insertionSort(array, n, comparisons);
    } else {
        int mid = n / 2;
        int *left = (int *)malloc(mid * sizeof(int));
        int *right = (int *)malloc((n - mid) * sizeof(int));
        for (int i = 0; i < mid; i++) {
            left[i] = array[i];
        }
        for (int i = mid; i < n; i++) {
            right[i - mid] = array[i];
        }
        hybridMergeSort(left, mid, comparisons);
        hybridMergeSort(right, n - mid, comparisons);
        merge(array, left, mid, right, n - mid, comparisons);
        free(left);
        free(right);
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Open file for writing data
    FILE *fp = fopen("comparisons_data_variable_n.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Vary input size N and fix value of S
    for (int N = MIN_N; N <= MAX_N; N += STEP_N) {
        int *array = (int *)malloc(N * sizeof(int));
        if (array == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        int total_comparisons = 0;

        for (int i = 0; i < 10; i++) { // Run each size 10 times for statistical accuracy
            int comparisons = 0;
            // Generate random dataset for the array
            for (int j = 0; j < N; j++) {
                array[j] = rand() % 1000 + 1; // Example: maximum value allowed for datasets
            }

            // Perform hybrid merge sort and record number of comparisons
            hybridMergeSort(array, N, &comparisons);
            total_comparisons += comparisons;
        }

        // Calculate average number of comparisons
        int average_comparisons = total_comparisons / 10;

        // Write N and average number of comparisons to file
        fprintf(fp, "%d %d\n", N, average_comparisons);

        free(array);
    }

    fclose(fp);
    printf("Data recorded successfully.\n");

    return 0;
}


//- The input size `N` is varied from `MIN_N` to `MAX_N` with a step size of `STEP_N`.
//- The value of `S` is fixed.
//- For each value of `N`, random datasets are generated, hybrid merge sort is performed, and the number of comparisons is recorded.
//- The average number of comparisons is calculated for each value of `N`.
//- The data (value of `N` and average number of comparisons) are written to a file named `comparisons_data_variable_n.txt`.

