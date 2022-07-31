#include <iostream>
#include <fstream>
#include<vector>
#include"comedy.h"
/**
* @brief This class holds information about the comedy movies 
* @authors Rashid Ibrahim
*/

/**
* @brief Construct a new Comedy object
* @param genre
* @param stockCount
* @param director
* @param title
* @param releaseYear
*/
Comedy::Comedy(char genre, int stockCount, string director, string title, int releaseYear): Movie(genre, stockCount, director, title, releaseYear) {
}

/**
* @brief the hash function for
* the comedy hash table
* @return int hash value
*/
int Comedy::hash()
{
   string title = this->getTitle();
   int key = title.length() +
   this->getReleaseYear() +
   title.at(0) +
   title.at(1) +
   title.at(2) +
   title.at(3);
   
   return key;
}

/**
* @brief overlaoding the == operator
* to check if two movies are ==
* @param m a Movie object
* @return true if ==
* @return false otherwise
*/
bool Comedy::operator==(Movie& m)
{
   return (this->getTitle() == m.getTitle());
}