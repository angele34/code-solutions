package Exercises.CCPROG3.Dorm_Exercise;

public class Room
{
	public Room(int roomNum, int maxCapacity)
	{
		NUM = roomNum;
		MAX = maxCapacity;
		guests = new Person[MAX];
		size = 0;
	}
	public boolean addGuest(Person guest)
	{ 
		if (isFull())
			return false;
		guests[size] = guest;
		size++;
		return true;
	}
	
	public boolean isFull()
	{
		return size == MAX;
	}
	
	public boolean isEmpty()
	{
		return size == 0;
	}
	
	public int getMaxCapacity()
	{
		return MAX;
	}

	public int getRoomNum()
	{
		return NUM;
	}
	
	public Person[] getGuests()
	{
		return guests;
	}
	
	public int getNumOccupants()
	{
		return size;
	}
	
	public void removeGuest(int index)
	{
		if (index >= 0 && index < size) {
			for (int i = index; i < size-1; i++) 
				guests[i] = guests[i+1];
		}
		guests[size-1] = null;
		size--;
	}
	
	private final int MAX; //max number of guests
	private final int NUM; //room number
	private Person[] guests;  //do not change to ArrayList
	private int size; //current number of guests in room
}