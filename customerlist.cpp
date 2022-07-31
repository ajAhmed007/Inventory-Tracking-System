#include <iostream>
#include <fstream>
#include <vector>
#include"customerlist.h"

using namespace std;

/**
* @brief This class hold a list
* of pointers to a customer and performs
* other operations on that list
* @author Rashid Ibrahim
*/

/**
* @brief method the build the cusotomer lsit
* from the input file
* @param infile1 a ifstrem object
*/
void CustomerList::buildCustomerList(ifstream &infile1)
{
   int id;
   string fName;
   string lName;
   
   while (true) {
      infile1 >> id;
      infile1 >> fName;
      infile1 >> lName;
      if (infile1.eof()) {
         break;
      }
      Customer *temp = new Customer(id, fName, lName);
      addCustomer(temp);
   }
}

/**
* @brief method for adding customer to the list
* @param c a customer object
*/
void CustomerList::addCustomer(Customer *c)
{
   cList.push_back(c);
}

/**
* @brief Get the Customer given ID
* @param ID customer id
* @return Customer* a pointer
*/
Customer* CustomerList::getCustomer(int ID)
{
   Customer *c = nullptr;
   for (int i = 0; i < cList.size(); i++)
   {
      if (cList.at(i)->getCustomerID() == ID)
      {
         c = cList.at(i);
         break;
      }
   }
   return c;
}

/**
* @brief displays all the customers in
* the list
*/
void CustomerList::showCustomrList()
{
   
   cout << "============================================================\n";
   cout << "Customer List\n";
   cout << "------------------------------------------------------------\n";
   cout << "#\t" << setw(36) << left <<"Name" << "\tID\n";
   cout << "------------------------------------------------------------\n";
   
   
   for (int i = 0; i < cList.size(); i++)
   {
      string name = cList.at(i)->getFirstName() + " " + cList.at(i)->getLastName();
      cout << i+1 << "\t" << setw(36) << left << name << "\t" << cList.at(i)->getCustomerID() << endl;
   }
   
   cout << "------------------------------------------------------------\n\n";
}

/**
* @brief shows the customer history
* for a particular customer with that id
* @param id customer id
*/
void CustomerList::showCustomrHistory(int id)
{
   Customer *c = getCustomer(id);
   cout << "============================================================\n" << "Customer History for ";
      cout << c->getFirstName() << " " << c->getLastName() << " ID: " << c->getCustomerID();
   cout << "\n" << "------------------------------------------------------------\n";
   
   c->showHistory();
   
   cout << "------------------------------------------------------------\n\n";
}
