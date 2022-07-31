#ifndef CUSTOMER_H_
#define CUSTOMER_H_
using namespace std;

#include <iostream>
#include <fstream>
#include <vector>
#include "movietable.h"

/**
* @brief This class determines information
* about the customer and the kind of
* tractions a customer is able to do perform
* It will also print the history regardin
* the customer
* @author Rashid Ibrahim
*/
class Customer {
   
   private:
   int customerID;
   string firstName;
   string lastName;
   vector<pair<string,string > > borrowedMovies;
   
   public:
   /**
   * @brief Construct a new Customer:: Customer object
   * @param id cutomer id
   * @param fName customer first name
   * @param lName customer last name
   */
   Customer(int id, string fName, string lName);
   
   /**
   * @brief Get the Customer ID
   * @return int customer id
   */
   int getCustomerID();
   
   /**
   * @brief Get the First Name
   * @return string customer first name
   */
   string getFirstName();
   
   /**
   * @brief Get the Last Name object
   * @return string customer last name
   */
   string getLastName();
   
   /**
   * @brief method to display the custoer
   *  history transactions
   */
   void showHistory();
   
   /**
   * @brief the custome can borrow movies
   * @param m a Movie object
   */
   void borrowMovie(Movie *m);
   
   /**
   * @brief the customer can also return
   * movies
   * @param m a movie object
   */
   void returnMovie(Movie *m);
   
};
#endif