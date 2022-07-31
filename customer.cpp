#include <iostream>
#include <fstream>
#include <vector>
#include "customer.h"

using namespace std;
/**
* @brief This class holds information about the customrs
* @authors Rashid Ibrahim
*/

/**
* @brief Construct a new Customer:: Customer object
* @param id cutomer id
* @param fName customer first name
* @param lName customer last name
*/
Customer::Customer(int id, string fName, string lName)
{
   customerID = id;
   firstName = fName;
   lastName = lName;
}

/**
* @brief Get the Customer ID
* @return int customer id
*/
int Customer::getCustomerID()
{
   return this->customerID;
}

/**
* @brief Get the First Name
* @return string customer first name
*/
string Customer::getFirstName()
{
   return this->firstName;
}

/**
* @brief Get the Last Name object
* @return string customer last name
*/
string Customer::getLastName()
{
   return this->lastName;
}

/**
* @brief the custome can borrow movies
* @param m a Movie object
*/
void Customer::borrowMovie(Movie *m)
{
   if(m->borrow())
   {
      borrowedMovies.push_back(make_pair(m->getTitle(), "Borrowed"));
   }
}

/**
* @brief the customer can also return
* movies
* @param m a movie object
*/
void Customer::returnMovie(Movie *m)
{
   for (int i = 0; i < borrowedMovies.size(); i++)
   {
      if (borrowedMovies.at(i).first == m->getTitle())
      {
         if (borrowedMovies.at(i).second == "Borrowed")
         {
            m->returnMovie();
            borrowedMovies.at(i).second = "Returned";
            break;
         }
      }
   }
}

/**
* @brief another method to also
* display the custoer history transactions
*/
void Customer::showHistory()
{
   int listSize = borrowedMovies.size();
   if (listSize)
   {
      
      cout << "#\t" << setw(36) << left <<"Title" << "\tStatus\n";
      cout << "------------------------------------------------------------\n";
      
      for (int i = 0; i < listSize; i++)
      {
         cout << i+1 << "\t" << setw(36) << left << borrowedMovies.at(i).first << "\t" << borrowedMovies.at(i).second << endl;
      }
   }
   else
   {
      cout << "The customer has not borrowed any movies yet.\n";
   }
}


