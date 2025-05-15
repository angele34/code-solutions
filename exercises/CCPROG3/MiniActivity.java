package Exercises.CCPROG3;
import java.util.*;

/**
 First mini activity for CCPROG3.
 * @author Angel
 * @version 1.0
*/

public class MiniActivity {
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        Float num1 = sc.nextFloat();
        System.out.print("Enter another number: ");
        Float num2 = sc.nextFloat();

        // Can also use double since floating point numbers are 
        // double by default in Java

        System.out.println(num1 + num2);
        System.out.println(num1 - num2);
        System.out.println(num1 * num2);
        System.out.println(num1 / num2);
        System.out.println(num1 > num2);
        System.out.println(num1 <= num2);
        System.out.println(!(num1 == num2));

        sc.close();
    }
}

/*

                                        *-------------------*
                                           Lecture Notes #2
                                        *-------------------*


    ** Strings **
    To represent a string in Java, the reference type String can be used.
    - A String object is immutable. Once created, its value cannot be changed.
        # Two ways to create a String object:
            (1) by assigning a literal;
                String strWord = "Good Day!";
            (2) by using the keyword new // creates a new space in the memory
                String strWord = new String ("Good Day!"); 


    ** Wrapper Clsses **
    - a class whose object contains a primitive data type.
    - is used for converting primitive types to reference types.
    - provides several methods to convert primitive type to String and vice versa.
        int x = Integer.parseInt("12345");


    ** Arrays in Java **
    - dynamically created objects
    - hold a fixed num of values of a single type
    - length is established at declaration
    - the number of brackets determine depth of the array ([], [][], [][][]) 1D -> 2D -> 3D
        # declaration
            int[] numbers; 
            boolean[] truths; 

        # dynamically allocated
            numbers = new int[5]; 
            int nSize = 3;
            truths = new booleans[nSize];

        # length attribute
            numbers.length or truths.length

        # access
            int j;
            for (j = 0; j < numbers.length; j++) 
                numbers[j] = j + 1;
            truths[1] = true;

        # assigning null
            numbers = null;
            truths = null;
        
        # All objects are created in the Heap section of the memory
        # Java's automatic garbage collection
        

        ----

        ** More arrays **
        # multi-dimensional arrays
            int[][] cells;
            cells = new int[2][3];

            int[][] spaces;
            spaces = new int[3][];
            int j;
            for (j = 0; j < spaces.length; j++) 
                spaces[j] = new int[j+1];

 
 */
