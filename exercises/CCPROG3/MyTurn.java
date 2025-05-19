package Exercises.CCPROG3;
import java.util.*;

/**
 Third mini activity for CCPROG3.
 * @author Angel
 * @version 1.0
*/

/*
 * compile: 
 > javac -d . MyTurn.java
 > java Exercises.CCPROG3.MyTurn
*/

public class MyTurn {
    public static void main(String[] args) {
        // ask # of students input from user
        Scanner sc = new Scanner(System.in);
        int numStudents = sc.nextInt();
        // ask # of exercises the student submitted
        int numExercises = sc.nextInt();
        int[][] exercises = new int[numStudents][numExercises];
        for (int i = 0; i < numStudents; i++) {
            for (int j = 0; j < numExercises; j++) {
                // input validation
                double score;
                do {
                    score = sc.nextDouble();
                } while (score < 0.0 || score > 100.0);
                exercises[i][j] = (int)score;
            }
        }
        // Display the average of each student's exercise score
        displayAverage(exercises, numStudents, numExercises);
        sc.close();
    }

    public static void displayAverage(int [][] exercises, int numStudents, int numExercises) {
        for (int i = 0; i < numStudents; i++) {
            double sum = 0;
            for (int j = 0; j < numExercises; j++) {
                sum += exercises[i][j];
            }
            System.out.println();
            System.out.println("Average of scores per student");
            System.out.println("Student " + (i+1) + ": " + (sum / numExercises));
        }
    }
}