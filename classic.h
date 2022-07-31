#ifndef classic_h
#define classic_h
#include "movie.h"

#include <iostream>
#include <iomanip>
using namespace std;

/**
* @brief This class holds information about
* the classic type of movies. Including other
* operations
* @author Ahmed Abdullahi
*/
class Classic : public Movie{
   
   public:
   /**
   * @brief Construct a new Classic object
   * @param genre
   * @param stockCount
   * @param director
   * @param title
   * @param releaseMonth
   * @param majorActor
   * @param releaseYear
   */
   Classic(char genre, int stockCount, string director, string title,  int releaseMonth, string majorActor, int releaseYear);
   
   /**
   * @brief this is the hash function for
   * the action classic hash table
   * @return int a hash value
   */
   int hash();
   
   /**
   * @brief overlaoding the == operator
   * to check if two movies are ==
   * @param m a Movie object
   * @return true if ==
   * @return false otherwise
   */
   bool operator==(Movie& m);
   
   /**
   * @brief Get the Major Actor
   * @return string
   */
   string getMajorActor();
   
   /**
   * @brief Get the Release Month
   * @return int
   */
   int getReleaseMonth();
   
   
   private:
   //specific for classic movies
   int releaseMonth;
   string majorActor;
   
};
#endif