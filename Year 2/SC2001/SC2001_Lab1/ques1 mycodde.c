
#include <stdio.h>
#include <stdlib.h>

int main1()
{
   int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];

    printf("Enter %d elements of the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("The array you entered is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    printf("The sorted array through hybridsort is:");
    hybridsort();
    printf("\n");

    return 0;
}

/*In Mergesort, when the sizes of subarrays are small, the overhead of many recursive
calls makes the algorithm inefficient. Therefore, in real use, we often combine
Mergesort with Insertion Sort to come up with a hybrid sorting algorithm for better
efficiency. The idea is to set a small integer S as a threshold for the size of subarrays.
Once the size of a subarray in a recursive call of Mergesort is less than or equal to S,
the algorithm will switch to Insertion Sort, which is efficient for small-sized input.*/

//S= threshold for the size of subarrays.
// If size of subarray in recursive call <=S then switch to Insertion Sort

//Implementing hybrid algorithm

void swap(int a , int b, int temp){
temp=a;
a=b;
b= temp;
}

void Mergesort(int n, int m ){
 int mid = (n+m)/2;
 int a = n, b = mid+1, i, tmp;
 if (m-n <= 0) return;
 while (a <= mid && b <= m) {
 int cmp = compare(slot[a], slot[b]);
 if (cmp > 0) { //slot[a] > slot[b]
 tmp = slot[b++];
 for (i = ++mid; i > a; i--)
 slot[i] = slot[i-1];
  slot[a++] = tmp;
 } else if (cmp < 0) //slot[a] < slot[b]
 a++;
else {   //slot[a] == slot[b]
 if (a == mid && b == m)
break;
 tmp = slot[b++];
 a++;
 for (i = ++mid; i > a; i--)
 slot[i] = slot[i-1];
 slot[a++] = tmp;
 }
 } // end of while loop;
 } // end of merge}

void InsertionSort(){
for (int i=1;i<n;i++)
    for (int j=i;j>0;j--){
        if (slot[j].key<slot[j-1].key)
            swap(slot[j],slot[j-1]);
        else break;
    }

}

void divideArray(int original[], int size, int **left, int *leftSize, int **right, int *rightSize) {
    *leftSize = size / 2;
    *rightSize = size - *leftSize;

    // Allocate memory for the left array
    *left = (int *)malloc(*leftSize * sizeof(int));
    if (*left == NULL) {
        printf("Memory allocation failed for left array.\n");
        exit(1);
    }

    // Allocate memory for the right array
    *right = (int *)malloc(*rightSize * sizeof(int));
    if (*right == NULL) {
        printf("Memory allocation failed for right array.\n");
        exit(1);
    }

    // Copy elements from the original array to the left and right arrays
    for (int i = 0; i < *leftSize; i++) {
        (*left)[i] = original[i];
    }
    for (int i = 0; i < *rightSize; i++) {
        (*right)[i] = original[i + *leftSize];
    }
}


void hybridsort(int array){
    array_length=sizeof(array)/sizeof(array[0]);
    hybridsort(leftSize);
    hybridsort(rightSize);
    hybridMerge(leftSize, rightSize);
}
hybridMerge(left, right){
   if(array_length<=S){
      InsertionSort();
   }else{
      MergeSort();
   }
}
}
