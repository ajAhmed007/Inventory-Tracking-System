#ifndef drama_h
#define drama_h
#include "movie.h"
#include <iostream>
#include <iomanip>
using namespace std;

/**
* @brief This class holds information about the movie genre of
* Drama and specific methods that only apply to the drama
* genre of movies
* @authors Daniel Wang
*/
class Drama : public Movie{
   public:
   /**
   * @brief Construct a new Drama object
   *
   * @param genre char representation genre of movie, in this case it will be D
   * @param stockCount int value of number of movies in stock
   * @param director string value of director's name
   * @param title string value of title of movie
   * @param releaseYear int value of year movie was released
   */
   Drama(char genre, int stockCount, string director, string title, int releaseYear);
   
   /**
   * @brief hash table to store the genre of Drama Movies
   *
   * @return returns int value of key
   */
   int hash();
   
};
#endif