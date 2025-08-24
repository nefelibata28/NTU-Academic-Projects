
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000 // Fixed input size
#define MIN_S 1   // Minimum value of S
#define MAX_S 50  // Maximum value of S
#define STEP_S 5  // Step size for varying S
/*
#ifndef SWAP_H
#define SWAP_H



// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//#endif /* SWAP_H

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
void hybridMergeSort(int array[], int n, int *comparisons, int S) {
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
        hybridMergeSort(left, mid, comparisons, S);
        hybridMergeSort(right, n - mid, comparisons, S);
        merge(array, left, mid, right, n - mid, comparisons);
        free(left);
        free(right);
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Open file for writing data
    FILE *fp = fopen("comparisons_data_fixed_n.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Fix input size n and vary the value of S
    for (int S = MIN_S; S <= MAX_S; S += STEP_S) {
        int *array = (int *)malloc(N * sizeof(int));
        if (array == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        int comparisons = 0;

        for (int i = 0; i < 10; i++) { // Run each size 10 times for statistical accuracy
            // Generate random dataset for the array
            for (int j = 0; j < N; j++) {
                array[j] = rand() % 1000 + 1; // Example: maximum value allowed for datasets
            }

            // Perform hybrid merge sort and record number of comparisons
            hybridMergeSort(array, N, &comparisons, S);
        }

        // Write S and number of comparisons to file
        fprintf(fp, "%d %d\n", S, comparisons);

        free(array);
    }

    fclose(fp);
    printf("Data recorded successfully.\n");

    return 0;
}


// The input size `n` is fixed to `N = 1000000`.
//- The value of `S` is varied from `MIN_S` to `MAX_S` with a step size of `STEP_S`.
//- For each value of `S`, random datasets are generated and hybrid merge sort is performed, and the number of comparisons is recorded.
//- The data (value of `S` and number of comparisons) are written to a file named `comparisons_data_fixed_n.txt`.

*/
