package Exercises.CCPROG3.Vehicle;

public class Bus extends Vehicle implements Public {
    public Bus(String start, String end) {
        super(30, start, end);
    }

    @Override
    public int computeFare(int km) {
        return 30;
    }
}
