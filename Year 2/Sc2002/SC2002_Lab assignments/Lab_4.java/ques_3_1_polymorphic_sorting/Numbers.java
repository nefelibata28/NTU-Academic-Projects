package ques_3_1_polymorphic_sorting;
import java.util.Arrays;
import java.util.Scanner;
public class Numbers
{
// --------------------------------------------
// Reads in an array of integers, sorts them,
// then prints them in sorted order.
// --------------------------------------------
public static void main (String[] args)
{
	int[] intList;
	int size;
	Scanner scan = new Scanner(System.in);
	System.out.print ("\nHow many integers do you want to sort? ");
	size = scan.nextInt();
	intList = new int[size];
	System.out.println ("\nEnter the numbers...");
	for (int i = 0; i < size; i++)
		intList[i] = scan.nextInt();
		//Sorting.selectionSort(intList);
	/*	In this modified code, I imported the Arrays class and used the Arrays.sort method to 
	 * sort the array of integers. This eliminates the need for a custom selectionSort method. 
	 * Java's autoboxing feature will handle the conversion of primitive integers to Integer objects when using Arrays.sort.*/
	
	Arrays.sort(intList);//using arrays.sort to sort the array
	
		System.out.println ("\nYour numbers in sorted order...");
	for (int i = 0; i < size; i++)
		System.out.print(intList[i] + " ");
	System.out.println ();
	
	 insertionSort(intList);
	 System.out.println ("\nYour numbers in sorted order using insertion sort...");
	 for (int i = 0; i < size; i++)
			System.out.print(intList[i] + " ");
		System.out.println ();
	
	
	}
public static void insertionSort(int[] list) {
    for (int index = 1; index < list.length; index++) {
        int key = list[index];
        int position = index;

        // Shift smaller values to the right for descending order
        while (position > 0 && key > list[position - 1]) {
            list[position] = list[position - 1];
            position--;
        }

        list[position] = key;
    }
}

}





