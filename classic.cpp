#include <iostream>
#include <fstream>
#include<vector>
#include"classic.h"
#include"movie.h"

/**
* @brief This class holds information about the classic movies 
* @authors Ahmed Abdullahi
*/

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
Classic::Classic(char genre, int stockCount, string director, string title, int releaseMonth, string majorActor, int releaseYear):Movie(genre, stockCount, director, title, releaseYear) {
   this->releaseMonth = releaseMonth;
   this->majorActor = majorActor;
}

/**
* @brief Get the Major Actor
* @return string
*/
string Classic::getMajorActor()
{
   return this->majorActor;
}

/**
* @brief Get the Release Month
* @return int
*/
int Classic::getReleaseMonth()
{
   return this->releaseMonth;
}

/**
* @brief this is the hash function for
* the action classic hash table
* @return int a hash value
*/
int Classic::hash()
{
   string actor = this->getMajorActor();
   
   int key = actor.length() +
   this->getReleaseYear() +
   this->getReleaseMonth() +
   actor.at(0) +
   actor.at(1) +
   actor.at(2) +
   actor.at(3);
   
   return key;
}

/**
* @brief overlaoding the == operator
* to check if two movies are ==
* @param m a Movie object
* @return true if ==
* @return false otherwise
*/
bool Classic::operator==(Movie& m)
{
   return (this->getTitle() == m.getTitle());
}