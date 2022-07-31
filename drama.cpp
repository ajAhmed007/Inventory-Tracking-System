#include <iostream>
#include <fstream>
#include<vector>
#include"drama.h"

/**
* @brief This class holds information about the movie genre of
* Drama and specific methods that only apply to the drama
* genre of movies
* @authors Daniel Wang
*/

/**
* @brief Construct a new Drama object
*
* @param genre char representation genre of movie, in this case it will be D
* @param stockCount int value of number of movies in stock
* @param director string value of director's name
* @param title string value of title of movie
* @param releaseYear int value of year movie was released
*/
Drama::Drama(char genre, int stockCount, string director, string title, int
releaseYear):Movie(genre, stockCount, director, title, releaseYear) {
}

/**
* @brief hash table to store the genre of Drama Movies
* @return returns int value of key
*/
int Drama::hash()
{
   string title = this->getTitle();
   string director = this->getDirector();
   
   int key = title.length() +
   director.length() +
   title.at(0) +
   title.at(1) +
   director.at(2) +
   director.at(3);
   
   return key;
}