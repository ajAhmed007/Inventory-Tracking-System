#ifndef comedy_h
#define comedy_h
#include "movie.h"

#include <iostream>
#include <iomanip>
using namespace std;
/**
* @brief This class holds information about the comedy movies 
* @authors Rashid Ibrahim
*/

/**
* @brief This class holds information about
* the comedy type of movies. Including other
* operations
*/
class Comedy : public Movie {
   public:
   /**
   * @brief Construct a new Comedy object
   * @param genre
   * @param stockCount
   * @param director
   * @param title
   * @param releaseYear
   */
   Comedy(char genre, int stockCount, string director, string title, int releaseYear);
   
   /**
   * @brief the hash function for
   * the comedy hash table
   * @return int hash value
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
   
};
#endif