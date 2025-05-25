package Exercises.CCPROG3;
import java.lang.*;
import java.util.*;

/**
 Programming with Arrays homework #1 for CCPROG3.
 * @author Angel Arwen E. Reyes
 * @author Tara Ysabel P. Uy
 * @version 1.0
*/

/* 
 Compile:
 javac -d . Ages.java
 Run:
 java Exercises.CCPROG3.Ages
*/

public class Ages {
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        // Ask how many humans for memory allocation
        System.out.print("Number of humans to input: ");
        int numHumans = Integer.parseInt(sc.nextLine());
        double [][] ages = new double[numHumans][];  

        // Function calls
        getAges(ages, sc);
        computeAges(ages);
        displayAges(ages);
        sc.close();
    }

    public static void getAges(double [][] ages, Scanner sc) 
    {
        for (int i = 0; i < ages.length; i++) {
            System.out.println("Input age for Human " + (i+1) + ": ");
            // Allocate the first index (col) of the array to the age of human
            int humanAge = Integer.parseInt(sc.nextLine());

            System.out.println("Number of dogs to input for Human " + (i+1) + ": ");            
            int numPets = Integer.parseInt(sc.nextLine());
            ages[i] = new double[numPets+1];
            ages[i][0]= humanAge;

            for (int j = 1; j <= numPets; j++) {
                System.out.println("Input age for Dog " + j + ": ");
                ages[i][j] = Integer.parseInt(sc.nextLine());
            }
        }
    }

    public static void computeAges(double [][] ages)
    {
        // Compute for the real dog age using the formula 16 x log(age of dog in human years) + 31
        for (int i = 0; i < ages.length; i++) {
            for (int j = 1; j < ages[i].length; j++) {
                double realDogAge = (Math.log(ages[i][j]) * 16) + 31;
                // Replace the dog (human calendar) age with the computed age
                ages[i][j] = Math.ceil(realDogAge);
            }
        }
    } 

    /*
                                        *-------------------*
                                            Sample Input
                                        *-------------------*
    Number of humans to input:
    1
    Input age for Human 1:
    56
    Number of dogs to input for Human 1:
    2
    Input age for Dog 1:
    2
    Input age for Dog 2:
    10
                                        *-------------------*
                                            Sample Output
                                        *-------------------*
    Human 1, age <56>
        > 42
        < 68
    */
    
    public static void displayAges(double [][] ages)
    {
        System.out.println();
        for (int i = 0; i < ages.length; i++) {
            double humanAge = ages[i][0];
            System.out.println("Human " + (i+1) + ", age " + (int)(humanAge));
            for (int j = 1; j < ages[i].length; j++) {
                double dogAge = ages[i][j];
                // Case 1: if human is younger than real dog age '<'
                if (humanAge < dogAge) 
                    System.out.printf("%3s< %d\n", "", (int)dogAge);
                // Case 2: if human is older than real dog age '>'
                else if (humanAge > dogAge)
                    System.out.printf("%3s> %d\n", "", (int)dogAge);
                // Case 3: if human and dog ages are equal '='
                else 
                    System.out.printf("%3s= %d\n", "", (int)dogAge);
            }
            System.out.println();
        }
    }
}
