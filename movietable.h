#ifndef hashtable_h
#define hashtable_h
#include <iostream>
#include <vector>
#include "movie.h"
using namespace std;

/**
 * @brief this class performs operations on
 * movie hash table
 * @author Rashid Ibrahim
 */

class MovieTable
{
   // size of the hash table
   int table_size;
   // Pointer to an array containing the keys
   vector<Movie*> *table;
   
   public:
   
   /**
   * @brief creates movieTable obj with the given size
   */
   MovieTable(int table_size);
   
   /**
   * @brief creates movieTable obj
   */
   MovieTable();
   
   /**
   * @brief sets the table size
   * @return void
   */
   void setTableSize(int table_size);
   
   /**
   * @brief inserts key into the hash table
   */
   void insertElement(Movie *m);
   
   /**
   * @brief deletes the key from the hash table
   */
   void deleteElement(Movie *m);
   
   
   /**
   * @brief displays the hashTable
   */
   void displayHashTable();
   
   /**
   * @brief the hashFunction to get the index for the movie
   * @return int has value
   */
   int hashStringFunction(Movie *m);
   
   /**
   * @brief finds an element from the hashtable using a movie obj
   * @return movie a movie pointer
   */
   Movie* findElement(Movie *m);
   
   /**
   * @brief returns all movies in the hash
   *
   * @return vector
   */
   vector<Movie*> getAllMovies();
};

#endif
