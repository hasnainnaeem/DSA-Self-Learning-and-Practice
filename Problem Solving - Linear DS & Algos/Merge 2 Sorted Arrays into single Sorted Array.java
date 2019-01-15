/*
Title: Program to Merge Two Sorted arrays into a Sorted array in Java
Written by: Muhammad Hasnain Naeem
Dated: 7/17/2018
 */

import java.util.Scanner;

public class Record {

    public static void main(String[] argz){

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of elements for array 1: ");
            int capacity1 = sc.nextInt();

        System.out.print("Enter number of elements for array 2: ");
            int capacity2 = sc.nextInt();

        int[] array1 = arrayInput(capacity1); //Input of first array
        int[] array2 = arrayInput(capacity2); //Input of second array
        int[] array3 = merger(array1, array2, capacity1, capacity2 ); //Merged two sorted arrays into third sorted array

        //Printing merged array
        System.out.print("\nMerged array:\t");
            arrayPrinter(array3);
    }

    public static int[] merger(int[] array1, int[] array2, int capacity1, int capacity2){

        int[] array3 = new int[capacity1+capacity2];

        //Merging two arrays:
        int i = 0, j = 0, k = 0; // i for array, j for array2, k for array3 indices.

        while(i < capacity1 && j < capacity2){
            if ( array1[i] < array2[j] ) {
                array3[k] = array1[i];
                i++;
            }

            else{
                array3[k] = array2[j];
                j++;
            }
            k++;
        }

        //If elements of one array are finished. Then copying all remaining elements of other array.
        while(i < capacity1){
            array3[k] = array1[i];
            i++;
            k++;
        }
        while(j < capacity2){
            array3[k] = array2[j];
            j++;
            k++;
        }

        return array3;
    }

    public static int[] arrayInput(int capacity){
        System.out.println();

        Scanner sc = new Scanner(System.in);
        int[] array = new int[capacity];

        for (int i = 0; i < capacity; i++){
            System.out.print("Enter element for index "+i+" : ");
            array[i] = sc.nextInt();
        }

        return array;
    }

    public static void arrayPrinter(int[] array){
        for (int element: array)
            System.out.print(element+"\t");
    }

}
