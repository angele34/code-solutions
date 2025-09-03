package Exercises.CCPROG3.Vehicle;

public abstract class Vehicle {

    public Vehicle(int c, String start, String end) {
        capacity = c;
        startPoint = start;
        endPoint = end;
        passengers = 0;
    }

    public int getCapacity() {
        return capacity;
    }
    
    public int getPassengers() {
        return passengers;
    }
    
    public String getStartPoint() {
        return startPoint;
    }

    public String getEndPoint() {
        return endPoint;
    }
    
    private int capacity;
    private String startPoint;
    private String endPoint;
    private int passengers;
}
