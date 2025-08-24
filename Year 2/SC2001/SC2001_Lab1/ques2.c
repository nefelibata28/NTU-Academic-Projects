/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Function to generate random integer between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to generate a random dataset for the given array
void generateRandomDataset(int array[], int size, int max_value) {
    for (int i = 0; i < size; i++) {
        array[i] = generateRandomNumber(1, max_value);
    }
}

int main2() {
    // Seed the random number generator
    srand(time(NULL));

    // Define the range of array sizes
    int min_size = 1000;
    int max_size = 10000000;

    // Define the maximum value for random integers
    int max_value = 1000000; // Example: maximum value allowed for datasets

    // Generate arrays of increasing sizes
    for (int size = min_size; size <= max_size; size *= 10) {
        // Allocate memory for the array
        int *array = (int *)malloc(size * sizeof(int));
        if (array == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        // Generate random dataset for the array
        generateRandomDataset(array, size, max_value);

        // Print the generated dataset (optional)

        /*printf("Generated dataset for array of size %d:\n", size);
        for (int i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");*/


        // Free the memory allocated for the array
 /*       free(array);
    }

    return 0;
}
*/
