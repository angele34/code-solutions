package Exercises.CCPROG3.Vehicle;

public class Jeepney extends Vehicle implements Public{
    public Jeepney(String start, String end) {
        super(20, start, end);
    }

    @Override
    public int computeFare(int km) {
        if (km <= 4) 
            return 7;
        else   
            return 7 + (km-4);
    }
}
