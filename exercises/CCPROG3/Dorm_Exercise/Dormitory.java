package Exercises.CCPROG3.Dorm_Exercise;
/**
 * Object-based Programming homework #4 for CCPROG3
 * This program implements the Dormitory UML class diagram in code.
 *
 * @author Angel Arwen E. Reyes
 * @author Tara Ysabel P. Uy
 * @version 1.0
*/
public class Dormitory {
    /**
     * Creates a Dormitory with the given name and number of rooms
     * Each room is automatically created with a default maximum capacity of 6 guests.
     * 
     * @param n the name of the dormitory
     * @param num the number of rooms in the dormitory
    */
    public Dormitory(String n, int num) {
        name = n;
        rooms = new Room[num];
        for (int i = 0; i < num; i++) {
            rooms[i] = new Room(i+1,6);
        }
    }
    /**
     * Creates a Dormitory with the given name, number of rooms, and specificied room capacity.
     * Each room is automatically created with the provided maximum capacity.
     * 
     * @param n the name of dormitory
     * @param num the number of rooms in the dormitory
     * @param m the maximum capacity for each room
    */
    public Dormitory(String n, int num, int m) {
        name = n;
        rooms = new Room[num];
        for (int i = 0; i < num ;i++) {
            rooms[i] = new Room(i+1, m);
        }
    }
    /**
     * Adds a guest to the specified room if the room number is valid and not full.
     *
     * @param roomNum the room number to add the guest to (must be valid)
     * @param g the guest to add
     * @return false if the room is full or the room number is invalid; true if the guest was added successfully
    */
    public boolean acceptGuests(int roomNum, Person g) {
        if (roomNum < 1 || roomNum > rooms.length) 
            return false;
        return rooms[roomNum-1].addGuest(g);
    }
    /**
     * Returns the list of guests currently in the specified room.
     *
     * @param roomNum the room number to get guests from
     * @return an array of guests in the room, or null if the room number is invalid
    */
    public Person[] getGuests(int roomNum) {
        if (roomNum < 1 || roomNum > rooms.length) 
            return null;
        return rooms[roomNum-1].getGuests();
    }
    /**
     * Returns the name of the dormitory.
     *
     * @return the dormitory name
    */
    public String getName() {
        return name;
    }
    /**
     * Returns the array of rooms in the dormitory.
     * 
     * @return an array of Room objects
     */
    public Room[] getRooms() {
        return rooms;
    }
    private String name;
    private Room[] rooms;
}
