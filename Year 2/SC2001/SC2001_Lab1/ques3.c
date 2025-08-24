

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define S 10 // Threshold for switching to Insertion Sort

/*
// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

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

    // Define the range of array sizes
    int min_size = 1000;
    int max_size = 10000000;

    // Define the maximum value for random integers
    int max_value = 1000000; // Example: maximum value allowed for datasets

    // Open file for writing data
    FILE *fp = fopen("comparisons_data.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Generate arrays of increasing sizes and record number of comparisons
    for (int size = min_size; size <= max_size; size *= 10) {
        int *array = (int *)malloc(size * sizeof(int));
        if (array == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        int comparisons = 0;

        for (int i = 0; i < 10; i++) { // Run each size 10 times for statistical accuracy
            // Generate random dataset for the array
            for (int j = 0; j < size; j++) {
                array[j] = rand() % max_value + 1;
            }

            // Perform hybrid merge sort and record number of comparisons
            hybridMergeSort(array, size, &comparisons);
        }

        // Write size and number of comparisons to file
        fprintf(fp, "%d %d\n", size, comparisons);

        free(array);
    }

    fclose(fp);
    printf("Data recorded successfully.\n");

    return 0;
}
*/
