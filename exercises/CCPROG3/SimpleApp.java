package Exercises.CCPROG3;
import java.util.*;

// Javadoc comments (NOTE: refer to "How to write Javadoc comments")

/*
 > javac -d . SimpleApp.java
 > java Exercises.CCPROG3.SimpleApp
 */

/**
 SimpleApp is the first class to be created for this course.
 * @author Angel
 * @version 1.0
*/

// only one public class is allowed per file
// public is an access modifier indicating accessibility/scope
public class SimpleApp { // className
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int x = sc.nextInt();
        System.out.print("Enter another number: ");
        int y = sc.nextInt();
        System.out.println("Sum is " + (x + y));
        sc.close();

        for (int i = 1; i <= x + y; i++) 
            System.out.print(i + " ");
        
        System.out.println();
        System.out.println("Pyramid");
        for (int i = 1; i <= x + y; i++) {
            for (int j = i+1; j <= x + y; j++) 
                System.out.print(" ");
            for (int j = 1; j < i+1; j++) 
                System.out.print("#");
            System.out.println();
        }

    }
}

/*  
                                        *-------------------*
                                           Lecture Notes #1
                                        *-------------------*

** Write once run anywhere **
- Java is an interpreted language (compiler translates the source code into machine code (bytecode))
- Java bytecode is the machine language for the Java Virtual Machine (JVM)

** Data **
- Java is a strongly-typed language (you have to declare your data types)

    Primitive Types
    - boolean
    - int
    - byte
    - long
    - char
    - float
    - short
    - double

    Reference Types
    - all non-primitive types, e.g classes
    - stores addresses


** Output statements **
- System.out.print()
- System.out.println()

ex.
    System.out.print(3 + 5);
    System.out.print("ID" + 19) converts data from left to right = ID19


** Scanner **
- used to read inputs from the console
- found in the java.util package

1. import java.util.*;
2. declare a variable of type Scanner
3. instantiate a Scanner object and specify System.in as the input source
    Scanner sc = new Scanner(System.in);
4. call the appropriate methods to read the input
    int nVal = sc.nextInt();
5. close this Scanner
    sc.close();

- To resolve issues when reading inputs, instead of directly using these methods, read
the input as a String then convert to the appropriate type:
    * to read integer inputs
        int nOne = Integer.parseInt(sc.nextLine());
    * to read real number inputs
        double dVal = Double.parseDouble(sc.nextLine());


** Compiling and Running **

Compile
cmd: javac Main.java
Java Bytecode: Main.class
Run
cmd: java Main


*/

