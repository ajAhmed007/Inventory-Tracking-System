#ifndef INVENTORY_H_
#define INVENTORY_H_
#include <iostream>
#include <fstream>
#include<map>

#include"customer.h"
#include"movie.h"
#include"comedy.h"
#include"drama.h"
#include"comedy.h"
#include "movietable.h"

using namespace std;

#define MAX_MOVIES 1000

/**
* @brief This class holds information about the movie inventory
* @authors Daniel Wang
*/
class Inventory {
   
   private:
   int hash_table_size;
   int listSize;
   
   MovieTable mList;
   
   public:
   /**
   * @brief inventory constructor, constructs an inventory obj
   */
   Inventory();
   
   /**
   * @brief prints out to system the list of movies that are available
   * in the inventory
   * @return void
   */
   void listInventory();
   
   /**
   * @brief add a movie obj to the inventory l ist
   * @return void
   */
   void add(Movie* _movie);
   
   /**
   * @brief takes in an input file and reads it in order to build the list
   * of movies that will be stored in the inventory
   * @return void
   */
   void buildInventory(ifstream &infile);
   
   /**
   * @brief if genre is found to be classic, will break apart the string
   * to put into the constructor of the classic class
   * @return void
   */
   void initializeClassicConstructor(vector<string> vStrings);
   
   /**
   * @brief if genre is found to be drama, will break apart the string
   * to put into the constructor of the drama class
   * @return void
   */
   void initializeDramaConstructor(vector<string> vStrings);
   
   /**
   * @brief if genre is found to be Comedy, will break apart the string
   * to put into the constructor of the Comedy class
   * @return void
   */
   void initializeCommedyConstructor(vector<string> vStrings);
   
   /**
   * @brief will display the hashtable of the inventory
   * @return void
   */
   void display();
   
   /**
   * @brief will print to the system the availablemovies in inventory
   * @return void
   */
   void show();
   
   /**
   * @brief find movie by title and year released
   * @return Movie
   */
   Movie* findMovie(string title, int year);
   
   /**
   * @brief find movie by director and title
   * @return Movie
   */
   Movie* findMovie(string director, string title);
   
   /**
   * @brief find movie by month and year released, and the major actor
   *
   * @return Movie
   */
   Movie* findMovie(int month, int year, string majorActor);
   
};
#endif