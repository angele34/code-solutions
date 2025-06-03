import java.util.Scanner;

/**
* Object-based Programming homework #2 for CCPROG3 (Part B).
* @author Angel Arwen E. Reyes
* @author Tara Ysabel P. Uy
* @version 1.0
*/

/*
Compile:
javac Pageant.java
Run:
java Pageant
*/

public class Pageant {
    public static void main(String[] args) {
        // Declare and instantiate an array of 5 Contestant objects
        Contestant[] contestant = new Contestant[5];
        // Ask user to input name, country, and age of beauty queen contestants. 
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 5; i++) {
            System.out.println("Enter name of contestant " + (i+1) + ": ");
            String name = sc.nextLine();
            System.out.println("Enter country of contestant " + (i+1) + ": ");
            String country = sc.nextLine();
            System.out.println("Enter age contestant " + (i+1) + ": ");
            int age = Integer.parseInt(sc.nextLine());
            
            contestant[i] = new Contestant(name, country, age);
        }

        // Ask user to input 2 talents and add these as talents of the first constestant object
        System.out.println("Enter 2 talents for Contestant 1: ");
        for (int i = 0; i < 2; i++) {
            System.out.println("Talent " + (i+1) + ": ");
            String talent = sc.nextLine();
            contestant[0].addTalent(talent);
        }

        // Check if first contestant can compete in "singing"
        boolean finalResult = contestant[0].canCompete("Singing") && contestant[0].canCompete(25);
        // Display the result of checking if first contestant is qualified to compete in "singing" 
        // The result is true only if the first contestant is at least (not at most) 25 years old.
        System.out.println("Can contestant 1 compete in Singing (age 25+)? " + finalResult);
        sc.close();
    }

}
