#ifndef movie_h
#define movie_h
#include <iostream>
#include <iomanip>
using namespace std;

/**
* @brief super class of different genres of movies
* specifications and assumptions:
* keeps track of movie objects, and
* @author Daniel Wang
*/

class Movie{
   public:
   /**
   * @brief constructs movie obj
   */
   Movie();
   
   /**
   * @brief constructs movie obj with the parameters passed in
   *
   */
   Movie(char genre, int stockCount, string director, string title, int releaseYear);
   
   /**
   * @brief returns the title of the movie
   * @return string
   */
   string getTitle();
   
   /**
   * @brief returns director of movie
   * @return string
   */
   string getDirector();
   
   /**
   * @brief returns stock count
   * @return int
   */
   int getStockCount();
   
   /**
   * @brief returns releaseYear of movie
   * @return int
   */
   int getReleaseYear();
   
   /**
   * @brief returns genre of movie
   * @return char
   */
   char getGenre();
   
   /**
   * @brief sets the stock count of the current movie
   * @return void
   */
   void setStockCount(int i);
   
   /**
   * @brief checks to see if movie is currently being borrowed
   * @return void
   */
   bool isBorrowed();
   
   /**
   * @brief borrows the movie
   * @return bool
   */
   bool borrow();
   
   /**
   * @brief returns the movie
   * @return void
   */
   void returnMovie();
   
   /**
   * @brief has function for movie
   * hash table
   * @return * int has value
   */
   virtual int hash()
   {
      return 0;
   }
   
   /**
   * @brief returns major actor
   *
   * @return string
   */
   virtual string getMajorActor();
   
   /**
   * @brief checks to see if rhs movie is equal to lhs movie
   *
   * @return bool
   */
   virtual bool operator==(Movie& m);
   
   private:
   // Character for the genre of a movie as classic(c), comedy(F), drama(D)
   char genre;
   //Character for type of media. D is for DVD
   char mediaType;
   // Title of a movie
   string title;
   //director of a movie
   string director;
   int releaseYear;
   //
   int stock;
   bool available;
   
};
#endif