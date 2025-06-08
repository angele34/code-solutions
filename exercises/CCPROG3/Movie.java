package Exercises.CCPROG3;

/**
 * Represents an online movie with details such as title, genre, year released,
 * a list of actors, and rental tracking.
 * 
 * @author Angel Arwen E. Reyes
 * @author Tara Ysabel P. Uy
 * @version 1.0
 */
public class Movie {
    
	/**
     * Constructs a Movie with title, genre, and year released.
	 * If the genre is invalid, defaults to "comedy".
     * @param t title
     * @param g genre
     * @param y year released
     */
    public Movie(String t, String g, int y) {
        this.title = t;
        if (isValidGenre(g)) {
			this.genre = g;
		} else {
			this.genre = "comedy";
		}
        this.yearReleased = y;
        this.actors = new String[5];
        this.timesRented = 0;
        this.numActors = 0;
        totalMovies++;
    }
	
    /**
     * Constructs a Movie with title and genre. Year defaults to 2020.
     * @param t title
     * @param g genre
     */
    public Movie(String t, String g) {
        this(t, g, 2020);
    }
	
    /**
     * Constructs a Movie with title, genre, and one actor. Year defaults to 2020.
     * @param t title
     * @param g genre
     * @param a one actor name
     */
    public Movie(String t, String g, String a) {
        this(t, g, 2020);
        addActor(a);
    }
	
    /**
     * Constructs a Movie with title and year. Genre defaults to comedy.
     * @param t title
     * @param y year released
     */
    public Movie(String t, int y) {
        this(t, "comedy", y);
    }
	
    /**
     * Checks if the provided genre is valid.
     * @param g the genre to check
     * @return true if genre is valid; false otherwise
     */
    public boolean isValidGenre(String g) {
        int i = 0;
        while (i < VALID_GENRES.length) {
            if (VALID_GENRES[i].equalsIgnoreCase(g)) {
                return true;
            }
            i++;
        }
        return false;
    }
	
    /**
     * Sets the genre if valid.
     * @param g new genre
     */
    public void setGenre(String g) {
        if (isValidGenre(g)) {
            this.genre = g;
        }
    }
	
    /**
     * Updates the genre (alias of setGenre).
     * @param g new genre
     */
    public void updateGenre(String g) {
        setGenre(g);
    }
	
    /**
     * Sets the year released.
     * @param y year
     */
    public void setYear(int y) {
        this.yearReleased = y;
    }

    /**
     * Updates the year released (alias of setYear).
     * @param y year
     */
    public void updateYear(int y) {
        setYear(y);
    }

    /**
     * Adds an actor to the movie if space is available.
     * @param a the actor's name
     * @return true if the actor was added; false if full
     */
    public boolean addActor(String a) {
        if (numActors < 5) {
            actors[numActors] = a;
            numActors++;
            return true;
        }
        return false;
    }

    /**
     * Increments the rental count for the movie.
     */
    public void rent() {
        timesRented++;
    }

    /**
     * Determines if the movie is a blockbuster (rented at least 10000 times).
     * @return true if blockbuster; false otherwise
     */
    public boolean isBlockBuster() {
        if (timesRented >= 10000) {
            return true;
        }
        return false;
    }

    /**
     * Gets the title of the movie.
     * @return the movie title
     */
    public String getTitle() {
        return title;
    }

    /**
     * Gets the movie genre.
     * @return the movie genre
     */
    public String getGenre() {
        return genre;
    }

    /**
     * Gets the release year of the movie.
     * @return the release year
     */
    public int getYear() {
        return yearReleased;
    }

    /**
     * Gets the list of actors.
     * @return array of actor names
     */
    public String[] getActors() {
        String[] result = new String[numActors];
        for (int i = 0; i < numActors; i++) {
            result[i] = actors[i];
        }
        return result;
    }
	
	/**
     * Gets the number of times the movie was rented.
     * @return rental count
     */
    public int getTimesRented() {
        return timesRented;
    }
	
    /**
     * Gets the total number of Movie instances.
     * @return total number of movies
     */
    public static int getTotalMovies() {
        return totalMovies;
    }

    /**
     * Decrements the total number of Movie instances.
     */
    public static void decrementTotalMovies() {
        if (totalMovies > 0) {
            totalMovies--;
        }
    }

    /**
     * Returns a string summary of the movie.
     * @return movie title, year, and genre
     */
    @Override
    public String toString() {
        return title + " (" + yearReleased + ") - " + genre;
    }

    /**
     * Compares this movie to another movie based on title, genre, and year.
     * @param obj another object
     * @return true if movies are equal; false otherwise
     */
    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Movie) {
            Movie other = (Movie) obj;
            return title.equals(other.title)
                && genre.equals(other.genre)
                && yearReleased == other.yearReleased;
        }
        return false;
    }
	
	private final String title;
    private String genre;
    private int yearReleased;
    private String[] actors;
    private int timesRented;
    private int numActors;
    private static int totalMovies = 0;
	private static final String[] VALID_GENRES = {
        "drama", "horror", "comedy", "biography", "sci-fi", "action", "romance", "kids"
    };
}
