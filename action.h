#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <map>
using namespace std;
#ifndef ACTION_H_
#define ACTION_H_
#define MAX_ACTIONS 1000
/**
* @brief This class holds information about the customer
* It also has details about the actions a customer is
* able to do
* @authors Ahmed Abdullahi
*/

class Action {
   
   private:
   char action;
   int customerID;
   char typeOfMedia;
   char genre;
   string title;
   int releaseYear;
   string director;
   int releaseMonth;
   string majorActor;
   
   public:
   
   /**
   * @brief default Construct a new Action object
   *
   */
   Action();
   
   /**
   * @brief Set the Action object
   *
   * @param action
   * @param customerID
   * @param typeOfMedia
   * @param genre
   * @param title
   * @param releaseYear
   * @param director
   * @param releaseMonth
   * @param majorActor
   */
   void setAction(char action, int customerID, char typeOfMedia,
   char genre, string title, int releaseYear,
   string director, int releaseMonth, string majorActor);
   
   /**
   * @brief Get the Action object
   * @return char
   */
   char getAction();
   
   /**
   * @brief Get the Customer I D object
   * @return int
   */
   int getCustomerID();
   
   /**
   * @brief Get the Type Of Media
   * type of the movie
   * @return char
   */
   char getTypeOfMedia();
   
   /**
   * @brief Get the Title of the
   * movie
   * @return string
   */
   string getTitle();
   
   /**
   * @brief Get the Genre of
   * the movie
   * @return char
   */
   char getGenre();
   
   /**
   * @brief Get the Release Year
   * of the movie
   * @return int
   */
   int getReleaseYear();
   
   /**
   * @brief Get the Director of the
   * movie
   * @return string
   */
   string getDirector();
   
   /**
   * @brief Get the Release Month
   * of the movie
   * @return int
   */
   int getReleaseMonth();
   
   /**
   * @brief gets the major actor
   * of the movie
   */
   string getMajorActor();
};
#endif