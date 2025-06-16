package Exercises.CCPROG3.Dorm_Exercise;
import java.util.*;

public class DormDriver
{
    public void display(Room room)
	{
		/* display all the guests in the room */
		for (Person g : room.getGuests()) {
			if (g != null)
				System.out.println("Name: " + g.getName() + ", Nationality: " + g.getNationality());
		}
	}
	
	public void displayDorms(Dormitory[] dorms)
	{
		int i;
		for (i = 0; i < dorms.length; i++)
		{
			/* display the name of the dorm, the total
			   number of rooms, and the number of rooms
			   that are not full yet */
			System.out.println("Dorm name: " + dorms[i].getName());
			System.out.println("Total number of rooms: " + dorms[i].getRooms().length);
			int notFull = 0;
			for (Room r : dorms[i].getRooms()) {
				if (!r.isFull()) 
					notFull++;
			}
			System.out.println("Number of rooms that are not full: " + notFull);
			/* 
			   Display all the names and nationalities
			   of the guests in each room. Part of the 
			   solution is to call the method display() 
			   in DormDriver. Provide your code */
			for (Room r : dorms[i].getRooms()) {
				display(r);
			}
		}
	}
	
	public static void main(String[] args)
	{
		Dormitory[] dorms = new Dormitory[2];
		
		dorms[0] = new Dormitory("LS Dorm", 3);
		dorms[1] = new Dormitory("STC Dorm", 5, 4);

		ArrayList<Person> guests = new ArrayList<Person>();
		guests.add(new Person("Andrew", "Filipino"));
		guests.add(new Person("Miguel", "Filipino"));
		guests.add(new Person("Henry", "American"));
		guests.add(new Person("Ray", "Filipino"));
		guests.add(new Person("Bernie", "Filipino"));
		guests.add(new Person("Michael", "Singaporean"));
		guests.add(new Person("Victor", "Filipino"));
		guests.add(new Person("Dennis", "Filipino"));
		guests.add(new Person("Jaime", "Filipino"));
		
		/* Have all Filipinos be in the same room, as
		   long as they fit.  Following first come, first
		   served, those who do not fit will be assigned 
		   to the next room. Use the first dormitory for 
		   the Filipinos.  For the other nationalities, 
		   they will be assigned to the second dormitory in
		   separate rooms. Provide your code.
		*/

		// Assign Filipinos to first dorm
		int LSDorm = 1;
		for (Person p : guests) {
			if (p.getNationality().equals("Filipino")) {
				while (dorms[0].getRooms()[LSDorm-1].isFull()) {
					LSDorm++;
				}
				dorms[0].acceptGuests(LSDorm, p);
			}
		}

		int STCDorm = 1;
		for (Person p : guests) {
			if (!p.getNationality().equals("Filipino")) {
				dorms[1].acceptGuests(STCDorm, p);
				STCDorm++;
			}
		}
		
		/* Provide your code to call displayDorms() in
		   class DormDriver. */
		   DormDriver driver = new DormDriver();
		   driver.displayDorms(dorms);
 		   
		/* Provide code to transfer Ray to STC Dorm, and
			he wants to be assigned to a currently unoccupied
			room. */
		boolean added = false;
		System.out.println("\n\nTransfering Ray");
		for (Person p : guests) {
			if (p.getName().equals("Ray")) {
				// Check for unoccupied rooms in STC Dorm
				for (Room r : dorms[1].getRooms()) {
					if (r.isEmpty() && !added) {
						r.addGuest(p);
						added = true;
					}
				}
			}
		}
		// Remove Ray from LSDorm
		for (Room r : dorms[0].getRooms()) {
			for (int i = 0; i < r.getGuests().length; i++) {
				Person g = r.getGuests()[i];
				if (g != null && g.getName().equals("Ray")) {
					r.removeGuest(i);
					i = r.getGuests().length;
				}
			}
		}
	
		/* Provide code to transfer Michael to the same room 
		   as Miguel */
		System.out.println("\n\nTransfering Michael");  
		
		// Remove Michael from STC dorm
		for (Room r : dorms[1].getRooms()) {
			for (int i = 0; i < r.getGuests().length; i++) {
				Person g  = r.getGuests()[i];
				if (g != null && g.getName().equals("Michael")) {
					r.removeGuest(i);
					i = r.getGuests().length;
				}

			}
		}

		added = false;
		for (Person p : guests) {
			if (p.getName().equals("Michael")) {
				for (Room r : dorms[0].getRooms()) {
					for (Person g : r.getGuests()) {
						if (!added && g != null && g.getName().equals("Miguel")) {
							r.addGuest(p);
							added = true;
						}
					}
				}
			}
		}
		
		/* Provide your code to call displayDorms() in
		   class DormDriver. */
		driver.displayDorms(dorms);

		guests = null;
		dorms = null;
		System.gc();
	}
}