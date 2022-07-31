#include"utilities.h"
#include "action.h"
/**
* @brief This class holds information about the customer
* It also has details about the actions a customer is
* able to do
* @authors Ahmed Abdullahi
*/

/**
* @brief Construct a new Action:: Action object
* Initializing the fields
*/
Action::Action()
{
   action = 0;
   customerID = 0;
   typeOfMedia = 0;
   genre = 0;
   title.clear();
   releaseYear = 0;
   director.clear();
   releaseMonth = 0;
   majorActor.clear();
}

/**
* @brief Method responsible for populating the
* different actions
*
* @param action char representing the action to take
* @param customerID unique id for each customer
* @param typeOfMedia the kind of media available
* @param genre movie genre
* @param title movie title
* @param releaseYear of movie
* @param director of movie
* @param releaseMonth of movie
* @param majorActor of movie
*/
void Action::setAction(char action, int customerID, char typeOfMedia, char genre, string title, int releaseYear = 0, string director = "", int releaseMonth = 0, string majorActor = "")
{
   //setting everything about the customer and movies
   this->action = action;
   this->customerID = customerID;
   this->typeOfMedia = typeOfMedia;
   this->genre = genre;
   this->title = title;
   this->releaseYear = releaseYear;
   this->director = director;
   this->releaseMonth = releaseMonth;
   this->majorActor = majorActor;
}

/**
* @brief returns the char action that
* the customer can chose from
* @return char representing the actions
*/
char Action::getAction()
{
   return this->action;
}

/**
* @brief returns a char for the
* genre of each movie
* @return char movie genre
*/
char Action::getGenre()
{
   return this->genre;
}

/**
* @brief returns the customer ID
* @return int customer id
*/
int Action::getCustomerID() {
   return this->customerID;
}

/**
* @brief returns the type of media
* available
* @return char media type
*/
char Action::getTypeOfMedia() {
   return this->typeOfMedia;
}

/**
* @brief return a string of the movie title
* @return string movie title
*/
string Action::getTitle() {
   return this->title;
}

/**
* @brief returns the release year
* @return int release year
*/
int Action::getReleaseYear() {
   return this->releaseYear;
}

/**
* @brief returns the movie director
* @return string director
*/
string Action::getDirector() {
   return this->director;
}

/**
* @brief returns the release month
* of each movie
* @return int release month
*/
int Action::getReleaseMonth() {
   return this->releaseMonth;
}

/**
* @brief returns the mojor of the
* movie
* @return string major actor
*/
string Action::getMajorActor() {
   return this->majorActor;
}

