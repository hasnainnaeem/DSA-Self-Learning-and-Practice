/*
Written on 9/26/2018
*/

import java.util.Scanner;

public class Main {

    public static void main(String argv[]){
        String str1, str2;
        Scanner input = new Scanner(System.in);

        System.out.println("Enter first string: ");
        str1 = input.nextLine();

        System.out.println("Enter second string: ");
        str2 = input.nextLine();

        System.out.println("Largest common substring: " + largestCommonSubstring(str1,
                str2) );

    }


    public static String largestCommonSubstring(String str1, String str2){
        int length = Math.min(str1.length(), str2.length()); //We'll compare upto length of smaller string

        String substring = "";
        String prevSubstring = "";
        Boolean flag = false; // true when substring found

        for (int i = 0; i < length; i++) {

            if (str1.charAt(i) == str2.charAt(i)) {
                substring += str1.charAt(i);

                if(flag && (substring.length() > prevSubstring.length())) {
                    prevSubstring = substring;
                }
            }

            else{
                prevSubstring = substring;
                substring = "";
                flag = true;
            }


        }

        if (prevSubstring != "")
            return prevSubstring;
        else
            return substring;
    }

}