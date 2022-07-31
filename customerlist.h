#ifndef CUSTOMERLIST_H_
#define CUSTOMERLIST_H_
#include <iostream>
#include <vector>
#include "customer.h"
using namespace std;

/**
* @brief This class hold a list
* of pointers to a customer and performs
* other operations on that list
*/
class CustomerList{
   vector<Customer*> cList;
   
   public:
   /**
   * @brief method for adding customer to the list
   * @param c a customer object
   */
   void addCustomer(Customer *c);
   
   /**
   * @brief Get the Customer given ID
   * @param ID customer id
   * @return Customer* a pointer
   */
   Customer* getCustomer(int ID);
   
   /**
   * @brief method the build the cusotomer lsit
   * from the input file
   * @param infile1 a ifstrem object
   */
   void buildCustomerList(ifstream &infile1);
   
   /**
   * @brief displays all the customers in
   * the list
   */
   void showCustomrList();
   
   /**
   * @brief shows the customer history
   * for a particular customer with that id
   * @param id customer id
   */
   void showCustomrHistory(int id);
};

#endif