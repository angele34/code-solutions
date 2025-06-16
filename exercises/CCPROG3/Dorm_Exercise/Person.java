package Exercises.CCPROG3.Dorm_Exercise;

public class Person {
    /**
     * Constructs a Person with the given name and nationality.
     * 
     * @param n the name of the guest
     * @param nat the nationality of them guest
     */
    public Person(String n, String nat) {
        name = n;
        nationality = nat;
    }
    /**
     * Returns the name of the guest
     * 
     * @return the guest name
     */
    public String getName() {
        return name;
    }
    /**
     * Returns the nationality of the guest
     * 
     * @return the nationality of the guest
     */
    public String getNationality() {
        return nationality;
    }
    private String name;
    private String nationality;
}
