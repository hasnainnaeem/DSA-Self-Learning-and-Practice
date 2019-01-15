/*
Title: Program to Merge Two Sorted arrays into a Sorted array in Java
Written by: Muhammad Hasnain Naeem
Date: 7/21/2018
 */

import java.util.Scanner;

public class Record {

    public static void main(String[] argz) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of elements for array 1: ");
        int capacity1 = sc.nextInt();

        int[] array1 = arrayInput(capacity1); //Input of first array

        arrayPrinter(insertionSort(array1));

    }

    public static int[] insertionSort(int[] array) {

        int len = array.length;
        if (len == 1)
            return array;

        //Real game starts:
        int j = 0, item = 0;

        for (int i = 1; i < len; i++) {
            item = array[i];
            j = i - 1;
            //if previous items are greater than specific item then 
            //move all those items forward and place that specific item just before them
            while( j >= 0 && array[j] > item){ 
                array[j+1] = array[j];
                j = j-1;
            }
            array[j+1] = item;
        }
        return array;
    }

    public static int[] arrayInput(int capacity) {
        System.out.println();

        Scanner sc = new Scanner(System.in);
        int[] array = new int[capacity];

        for (int i = 0; i < capacity; i++) {
            System.out.print("Enter element for index " + i + " : ");
            array[i] = sc.nextInt();
        }

        return array;
    }

    public static void arrayPrinter(int[] array) {
        for (int element : array)
            System.out.print(element + "\t");
    }
}