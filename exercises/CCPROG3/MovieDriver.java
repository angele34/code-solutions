package Exercises.CCPROG3;
/**
 * Object-based Programming homework #3 for CCPROG3.
 * Demonstrates the use of the Movie class by creating and manipulating Movie objects.
 *
 * @author Angel Arwen E. Reyes
 * @author Tara Ysabel P. Uy
 * @version 1.0
*/

public class MovieDriver {
    /**
     * The main method tests creation, updating, renting, and displaying Movie objects.
     * @param args command line arguments (not used)
     */
    public static void main(String[] args) 
    {
        // 1 : Declare and instantiate an array of 5 Movie objects called mustWatch
        Movie[] mustWatch = new Movie[5];
        // 2: Instantiate the first Movie object 
        mustWatch[0] = new Movie("X-Men", "Thriller", 2000);
        // 3: Instantiate the second Movie object 
        mustWatch[1] = new Movie("Pokemon the movie", "kids");
        // Instantiate the third Movie object 
        mustWatch[2] = new Movie("Thor", "action", "Chris Hemsworth");
        // Instantiate the fourth Movie object 
        mustWatch[3] = new Movie("Frozen", 2019);

        // 6 : Display the total number of movies instantiated
        System.out.println("Total number of movies: " + Movie.getTotalMovies());

        MovieDriver driver = new MovieDriver();
        // 7 :  Display the title, genre, and year of all movies in mustWatch
        driver.displayMovies(mustWatch);
        // 8 : Modify genre of first movie in mustWatch to sci-fi
        mustWatch[0].updateGenre("sci-fi");
        // 9 : Modify genre of 4th movie in mustWatch to kids
        mustWatch[3].updateGenre("kids");
        // 10 : Modify year released of second movie in mustWatch to 2019
        mustWatch[1].updateYear(2019);
        // 11 : Modify year released of third movie in mustWatch to 2011
        mustWatch[2].updateYear(2011);
        // 12 : Display the title, genre, and year of all movies in mustWatch
        System.out.println("\nAfter updates:");
        driver.displayMovies(mustWatch);
        // 13 : Add Natalie Portman as another actor to the third movie stored in mustWatch
        mustWatch[2].addActor("Natalie Portman");
        // 14 : Add the following actors (in sequence) to the second movie stored in mustWatch:
        // Pikachu, Charizard, Squirtle, Ditto, Mewtwo, Psyduck
        mustWatch[1].addActor("Pikachu");
        mustWatch[1].addActor("Charizard");
        mustWatch[1].addActor("Squirtle");
        mustWatch[1].addActor("Ditto");
        mustWatch[1].addActor("Mewtwo");
        mustWatch[1].addActor("Psyduck");
        // 15 : Display all actors of the third movie stored in mustWatch
        System.out.println("\nActors in Thor:");
        driver.displayActors(mustWatch[2]);
        // 16 : Display all actors of the second movie stored in mustWatch
        System.out.println("\nActors in Pokemon:");
        driver.displayActors(mustWatch[1]);
        System.out.println();
        // 17 : Declare and instantiate another array of at most 3 movies called myRental
        Movie[] myRental = new Movie[3];
        // 18 : Rent all movies that are in the genre of kids from mustWatch. 
        // These movies should now be associated also to myRental
        int rentalIndex = 0;
        for (int i = 0; i < mustWatch.length; i++) {
            if (mustWatch[i] != null && mustWatch[i].getGenre().equalsIgnoreCase("kids")) {
                mustWatch[i].rent();
                if (rentalIndex < myRental.length) {
                    myRental[rentalIndex] = mustWatch[i];
                    rentalIndex++;
                }
            }
        }
        // 19 : Display the total number of movies instantiated
        System.out.println("Total number of movies: " + Movie.getTotalMovies());
        // 20 : Display the title, genre, and year of all movies in mustWatch
        System.out.println("\nMustWatch Movies:");
        driver.displayMovies(mustWatch);
        // 21 : Display the title, genre, and year of all movies in myRental
        System.out.println("\nMyRental Movies:");
        for (Movie m : myRental) {
            if (m != null) 
                System.out.println(m);
        }
        // 22 : Rent the movie Frozen 2 again and store that as the last element to myRental
        mustWatch[3].rent();
        if (rentalIndex < mustWatch.length)
            myRental[rentalIndex] = mustWatch[3];
        // 23 : Display the number of times the movie stored in the second element of myRental was rented
        // and display the result of isBlockBuster() for that movie
        System.out.println("\nFrozen 2 has been rented: " + myRental[1].getTimesRented());
        System.out.println("Is it a blockbuster? " + myRental[1].isBlockBuster());
        // 24 : Set myRental to null
        myRental = null; 
         // 25 : Delete the movie object with title X-Men
        mustWatch[0] = null; 
        Movie.decrementTotalMovies();
        // 26 : Update the total number of movies instantiated. Display the total number of movies instantiated
        System.out.println("\nFinal Total Movies: " + Movie.getTotalMovies());
    }

   public void displayMovies(Movie[] mustWatch) {
        for (Movie m : mustWatch) {
            if (m != null) {
                System.out.printf("%-25s %-10s %-4d\n",
                    m.getTitle(), m.getGenre(), m.getYear());
            }
        }
    }   

    public void displayActors(Movie m) 
    {
        if (m == null) return;
        String[] actors = m.getActors();

        for (String a : actors) {
            if (a != null)
                System.out.println(a);
        }
    }
}
