/*
Title: Selection sort algorithm implementation in Java
Written by: Muhammad Hasnain Naeem
Date: 7/17/2018
 */

import java.util.Scanner;

public class Record {

    public static void main(String[] argz){

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of elements for array 1: ");
            int capacity1 = sc.nextInt();

        int[] array1 = arrayInput(capacity1); //Input of first array

        arrayPrinter(selectionSort(array1));

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

    public static int[] selectionSort(int[] array){

        int len = array.length;
        if (len == 1)
            return array;

        //Real game starts:
        int i, j, minIndex;

        for(j = 0; j < len - 1; j++) {
            int min = array[j];
            minIndex = j;
            for (i = j+1; i < len; i++) {
                //if any number is smaller than supposed than update min
                if (min > array[i]) {
                    minIndex = i;
                }
            }
            //Placing minimum numbers in the start
            int temp = array[j];
            array[j] = array[minIndex];
            array[minIndex] = temp;
            //in next iteration minimum numbers in the start remain unprocessed 
        }

        return array;
    }

}
