package Exercises.CCPROG3.Vehicle;

import java.util.*;

public class ConsoleDriver {
    public static void main(String[] args) {
        ArrayList<Vehicle> vehicles = new ArrayList();
        Scanner sc = new Scanner(System.in);

        ConsoleDriver driver = new ConsoleDriver();

        while(true) {
            System.out.println("Which vehicle do you want to add?");
            System.out.println("[1] Bus");
            System.out.println("[2] Jeepney");
            System.out.println("[3] Helicopter");
            System.out.println("[4] Exit");

            int ans = Integer.parseInt(sc.nextLine());
            
            if (ans == 4) 
                break; 
            
            if (ans < 1 || ans > 3) {
                System.out.println("Please enter a valid vehicle (1-3)");
                continue; 
            }

            System.out.print("Enter start point: ");
            String start = sc.nextLine();

            System.out.print("Enter end point: ");
            String end = sc.nextLine();

            switch(ans) {
                case 1:
                    vehicles.add(new Bus(start, end));
                    break;
                case 2:
                    vehicles.add(new Jeepney(start, end));
                    break;
                case 3:
                    vehicles.add(new Helicopter(start, end));
                    break;
            }

            for (Vehicle v : vehicles) {
                System.out.println("Vehicle: " + v.getClass().getSimpleName());
                System.out.println("Maximum Capacity: " + v.getCapacity());
                System.out.println("Start point: " + v.getStartPoint());
                System.out.println(("End point: " + v.getEndPoint()));

                if (v instanceof Public) {
                    System.out.print("Enter distance in km: ");
                    int km = Integer.parseInt(sc.nextLine());
                    System.out.println("Fare: " + ((Public)v).computeFare(km));
                }
            }
            System.out.println();
        }
        sc.close();
    }   

    
}