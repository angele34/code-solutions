package Exercises.CCPROG3;
import java.util.*;

/**
 Second mini activity for CCPROG3.
 * @author Angel
 * @version 1.0
*/

public class JustMeNow {
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        // Discount percentage
        int numOne = 25;
        // Quantity
        System.out.print("Quantity of items to purchase: ");
        int numTwo = sc.nextInt();
        // Amount per item (before discount)
        System.out.print("Price: ");
        double dbOne = sc.nextDouble();
        sc.nextLine();
        // Item name
        System.out.print("Item name: ");
        String str = sc.nextLine();

        // Get discount
        double discount = ((dbOne * numOne) / 100.0);
        System.out.println();

        // Print out transaction details
        System.out.println("Quantity: " + numTwo + " " + "Item name: " + str + " Price: " + dbOne);
        System.out.println("Less " + numOne + "% " + "= " + discount);
        System.out.println("Total due: Php " + (dbOne - discount));

        sc.close();
    }
}
