#include <iostream>
#include <iomanip>
#include"movie.h"
using namespace std;
/**
* @brief super class of different genres of movies
* specifications and assumptions:
* keeps track of movie objects, and
* @author Daniel Wang
*/

/**
* @brief creates movie obj with default values
*
*/
Movie::Movie() {
   this->releaseYear = 0;
   this->stock = 0;
   this->director = "";
   this->title = "";
   this->genre = 0;
   this->available = false;
}

/**
* @brief creates movie obj with specified parameters
*
* @param genre genre of movie
* @param stockCount current stock of movie
* @param director director of movie
* @param title title of movie
* @param releaseYear year movie was r eleased
*
*/
Movie::Movie(char genre, int stockCount, string director, string title, int releaseYear) {
   this->stock = stockCount;
   this->director = director;
   this->title = title;
   this->genre = genre;
   this->releaseYear = releaseYear;
   this->available = false;
}

/**
* @brief returns stock count
* @return int
*/
int Movie::getStockCount() {
   return this->stock;
}

/**
* @brief sets the stock count of the current movie
* @return void
*/
void Movie::setStockCount(int i)
{
   this->stock = i;
}

/**
* @brief returns the title of the movie
* @return string
*/
string Movie::getTitle() {
   return this->title;
}

/**
* @brief returns director of movie
* @return string
*/
string Movie::getDirector() {
   return this->director;
}

/**
* @brief returns releaseYear of movie
* @return int
*/
int Movie::getReleaseYear()
{
   return this->releaseYear;
}

/**
* @brief returns genre of movie
* @return char
*/
char Movie::getGenre() {
   return this->genre;
}

/**
* @brief returns major actor
* @return string
*/
string Movie::getMajorActor() {
   return "";
}

/**
* @brief checks to see if movie is currently being borrowed
* @return void
*/
bool Movie::isBorrowed() {
   return this->available;
}

/**
* @brief checks to see if rhs movie is equal to lhs movie
* @return bool
*/
bool Movie::operator==(Movie& m)
{
   return (this->getTitle() == m.getTitle());
}

/**
* @brief borrows the movie
* @return bool
*/
bool Movie::borrow()
{
   bool borrowed = false;
   if (this->stock > 0)
   {
      this->stock--;
      borrowed = true;
   }
   
   return borrowed;
}

/**
* @brief returns the movie
* @return void
*/
void Movie::returnMovie()
{
   this->stock++;
}
