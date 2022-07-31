#include <iostream>
#include <fstream>
#include "customerlist.h"
#include "inventory.h"
#include "action.h"
#include "actionlist.h"
using namespace std;

/**
* @brief This is the driver file, that runs the implemented solution for the movie
* store inventory. It displays the store movie inforomation in a easy to ready, including
* the customer history and inventory. It will also display the customer for the movie store
* @authors AHMED ABDULLAHI, RASHID IBRAHIM, DANIEL WANG
*/

int main() {
   ifstream infile1("data4customers.txt");
   if (!infile1) {
      cout << "File could not be opened." << endl;
      return 1;
   }
   
   ifstream infile2("data4movies.txt");
   if (!infile2) {
      cout << "File could not be opened." << endl;
      return 1;
   }
   
   ifstream infile3("data4commands.txt");
   if (!infile3) {
      cout << "File could not be opened." << endl;
      return 1;
   }
   
   //Initialize the movie in the inventory(store)
   CustomerList C;
   C.buildCustomerList(infile1);
   C.showCustomrList();
   
   Inventory I;
   I.buildInventory(infile2);
   
   ActionList AL;
   AL.buildAction(infile3);
   
   Action action;
   int i;
   Movie* m;
   Customer *c;
   
   int actionCount = AL.getActionCount();
   
   for (i = 0; i < actionCount; i++)
   {
      action = AL.getAction(i);
      
      switch(action.getAction())
      {
         case 'I':
         I.show();
         break;
         
         case 'H':
         C.showCustomrHistory(action.getCustomerID());
         break;
         
         case 'B':
         if (action.getGenre() == 'F')
         {
            m = I.findMovie(action.getTitle(), action.getReleaseYear());
         }
         else if (action.getGenre() == 'D')
         {
            m = I.findMovie(action.getDirector(), action.getTitle());
         }
         else if (action.getGenre() == 'C')
         {
            m = I.findMovie(action.getReleaseMonth(), action.getReleaseYear(), action.getMajorActor());
         }
         
         if (m)
         {
            c = C.getCustomer(action.getCustomerID());
            if (c)
            {
               c->borrowMovie(m);
            }
         }
         break;
         
         case 'R':
         
         if (action.getGenre() == 'F')
         {
            m = I.findMovie(action.getTitle(), action.getReleaseYear());
         }
         
         else if (action.getGenre() == 'D')
         {
            m = I.findMovie(action.getDirector(), action.getTitle());
         }
         
         else if (action.getGenre() == 'C')
         {
            m = I.findMovie(action.getReleaseMonth(), action.getReleaseYear(), action.getMajorActor());
         }
         
         if (m)
         {
            c = C.getCustomer(action.getCustomerID());
            
            if (c)
            {
               c->returnMovie(m);
            }
         }
         break;
      }
   }
   
}