package Exercises.CCPROG3;
import java.util.*;
 
public class MyDate
{
    public MyDate()
    {
        month = 7;
        day = 1;
        year = 2020;
    }
    // public MyDate(int m, int d, int y)
    // {
    //     if (isValidDate(m, d, y)) {
    //         month = m;
    //         day = d;
    //         year = y;
    //     } else {
    //         month = 7;
    //         day = 1;
    //         year = 2020;
    //     }
    // }
    public MyDate(int m, int d)
    {
        month = m;
        day = d;
    }
    // public int getMonth()
    // {
    //     Scanner sc = new Scanner(System.in);
    //     int m = sc.nextInt();
    //     if (isValidMonth(m))
    //         month = m;
    //     return month;
    // }
    public int getDay()
    {
        
        return day;
    }
    public int getYear()
    {
        
        return year;
    }
    public void displayDate()
    {
        System.out.print(month + "/" + day + "/" + year);
    }
    // public void setDate(int m, int d, int y)
    // {
        
    // }
    // public boolean isValidDate(int m, int d, int y)
    // {

    // }
    // private boolean isValidMonth(int m)
    // {
    //     if (m > 0 && m < 13)
    //     return true;
    //     else return false;
    // }
    // private boolean isValidDay(int m, int d)
    // {

    // }
    // private boolean isValidYear(int y)
    // {

    // }

    /* For Practice:
    1. Create a constructor that will accept a String month and
    integer day to initialize the date.
    2. Create a constructor that will accept a String month and
    integers day and year to initialize the date.
    3. Create a private method that will return the String
    equivalent of a given integer month.
    4. Create a public method to display the date, with the month
    displayed as a string. (Eg. month = 7, displayed as July)
    5. Create an overloaded method setDate() that can accept a
    String for the month, and integers day and year.
    6. Put in appropriate internal documentation for class Date,
    so documentation can be generated via Javadoc.
    7. Update UML class diagram to reflect the additions
    */
    private int month;
    private int day;
    private int year;
   
}