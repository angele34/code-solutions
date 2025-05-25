package Exercises.CCPROG3;
import java.util.*;

/**
 * Programming with Arrays homework #1 for CCPROG3.
 * This program reads and stores human and dog ages in a ragged 2D array,
 * converts the dog ages to real ages using a log formula,
 * and displays comparisons between the human age and each dog's real age.
 * 
 * Sample output:
 * Human 1, age <56>
 *   > 43
 *   < 68
 *
 * @author Angel Arwen E. Reyes
 * @author Tara Ysabel P. Uy
 * @version 1.0
*/

/* 
 Compile (in your local machine):
 javac Ages.java
 Run:
 java Ages

 Compile (working directory):
 javac -d . Ages.java
 Run:
 java Exercises.CCPROG3.Ages
*/



public class Ages {
    /** 
	 * The main method to run the program.
     * Initializes the ragged array, gathers input, computes dog ages,
     * and displays the formatted result.
	*/
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        // Ask how many humans for memory allocation
        System.out.print("Number of humans to input: ");
        int numHumans = Integer.parseInt(sc.nextLine());
        double [][] ages = new double[numHumans][];  

        // Function calls
        getAges(ages, sc);	// Collect human and dog ages from user
        computeAges(ages);	// Convert dog ages to real ages
        displayAges(ages);	// Show comparison of ages
        
		// Close the Scanner
		sc.close();
    }

    /**
     * Prompts the user to input human ages and dog ages for each human.
     * Stores the data in a ragged 2D array where the first element per row
     * is the human's age and the rest are their dogs' ages.
     *
     * @param ages 	the ragged 2D array to be filled with ages
     * @param sc 	the Scanner object for user input
    */

    public static void getAges(double [][] ages, Scanner sc) 
    {
        for (int i = 0; i < ages.length; i++) {
            System.out.println("Input age for Human " + (i+1) + ": ");
            // Allocate the first index (col) of the array to the age of human
            int humanAge = Integer.parseInt(sc.nextLine());

            System.out.println("Number of dogs to input for Human " + (i+1) + ": ");            
            int numPets = Integer.parseInt(sc.nextLine());

            // Create row with 1 slot for human + n slots for each dog
            ages[i] = new double[numPets+1];
            ages[i][0]= humanAge;

            for (int j = 1; j <= numPets; j++) {
                System.out.println("Input age for Dog " + j + ": ");
                ages[i][j] = Integer.parseInt(sc.nextLine());
            }
        }
    }

    /**
     * Converts each dog's age (in human years) in the array
     * to its real age using the formula:
     * 16 x log(age of dog in human years) + 31, then replaces the original value.
     *
     * @param ages 	the ragged 2D array containing human and dog ages
    */

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
        > 43
        < 68
    */

    /**
     * Displays each human's age followed by the comparison ('<', '>', or '=') 
	 * of their age to each of their dogs’ real ages using the specified format.
	 * '<' if dog is older
     * '>' if dog is younger
     * '=' if equal in age
     *
     * @param ages 	the ragged 2D array containing human and real dog ages
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
