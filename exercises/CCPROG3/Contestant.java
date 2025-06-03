/**
 * Object-based Programming homework #2 for CCPROG3 (Part A).
 * This program implements the Contestant UML class diagram in code.
 *
 * @author Angel Arwen E. Reyes
 * @author Tara Ysabel P. Uy
 * @version 1.0
*/

public class Contestant {
    /**
     * Initializes the name, country, and age of the participant.
     * Also initializes the array of talents to contain at most 3 Strings.
     *
     * @param n name of participant
     * @param c country participant is representing
     * @param a age of the participant
     */
    public Contestant(String n, String c, int a) {
        name = n;
        country = c;
        talents = new String[3];
        age = a;
    }

    /**
     * Initializes the name and country of the participant.
     * Also initializes the array of talents to contain at most 3 Strings and sets age to 18.
     *
     * @param n name of participant
     * @param c country participant is representing
     */
    public Contestant(String n, String c) {
        name = n;
        country = c;
        talents = new String[3];
        age = 18;
    }

    /**
     * Returns the name of the participant.
     *
     * @return name of participant
     */
    public String getName() {
        return name;
    }

    /**
     * Returns the country the participant is representing.
     *
     * @return country represented by participant
     */
    public String getCountry() {
        return country;
    }

    /**
     * Adds the talent to the list if there is available space.
     *
     * @param t a talent of the participant
     */
    public void addTalent(String t) {
        for (int i = 0; i < talents.length; i++) {
            if (talents[i] == null) {
                talents[i] = t;
                break;
            }
        }
    }

    /**
     * Checks if the participant has the given talent.
     *
     * @param t string to compare against the list of talents
     * @return true if t is one of the talents, false otherwise
     */
    public boolean canCompete(String t) {
        if (talents == null) return false;
        for (String talent : talents) {
            if (talent != null && talent.equalsIgnoreCase(t))
                return true;
        }
        return false;
    }

    /**
     * Checks if participant has the talent and is at most maxAge.
     *
     * @param t string to compare against talents
     * @param maxAge age limit to join
     * @return true if talent matches and age <= maxAge, false otherwise
     */
    public boolean canCompete(String t, int maxAge) {
        return canCompete(t) && age <= maxAge;
    }

    /**
     * Checks if participant is at least minAge.
     *
     * @param minAge minimum age to qualify
     * @return true if participant is at least minAge, false otherwise
     */
    public boolean canCompete(int minAge) {
        return age >= minAge;
    }

    /**
     * Returns a string representation: "name, country, age".
     *
     * @return concatenation of name, country, and age
     */
    @Override
    public String toString() {
        return name + ", " + country + ", " + age;
    }

    private String name;
    private String country;
    private String[] talents;
    private int age;
}
