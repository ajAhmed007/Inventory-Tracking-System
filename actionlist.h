#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <map>
#include "customer.h"
#include  "action.h"
using namespace std;

#ifndef ACTION_LIST_H_
#define ACTION_LIST_H_

#define MAX_ACTIONS 1000

/**
* @brief
* @authors Ahmed Abdullahi
* This class holds information about the customer actions 
* maintains a list of actions
* It also has details about the actions a customer is
* able to do
*/

/**
* @brief This class hold the type of commands
* or actions available to the customer in a list
*/
class ActionList
{
   private:
   Action actions[MAX_ACTIONS];
   int actionCount;
   
   public:
   /**
   * @brief Construct a new Action List object
   */
   ActionList();
   
   /**
   * @brief this methods reads the file
   * and builds the available actions or command
   * from the file
   * @param infile a iftream object
   */
   void buildAction(ifstream &infile);
   
   /**
   * @brief Get the Action Count object
   * @return int the number of actions
   */
   int getActionCount();
   
   /**
   * @brief Get the Action object
   * returns the available command/actions
   * @param i to determine which action
   * @return Action
   */
   Action getAction(int i);
   
   /**
   * @brief method to display the available
   * actions or command the customer can take
   */
   void displayAction();
   
   /**
   * @brief helper method for the borrow and
   * return actions. The customer can borrow and return
   * @param line string of command
   * @param bOrR borrow and return char
   */
   void borrowReturnHelper(string line, char bOrR);
};
#endif