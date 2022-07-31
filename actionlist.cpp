#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

#include"action.h"
#include "actionlist.h"
#include "utilities.h"
#include "movietable.h"
#include "customer.h"
#include "inventory.h"
/**
* @brief
* @authors Ahmed Abdullahi
* This class holds information about the customer
* It also has details about the actions a customer is
* able to do
*/

using namespace std;
/**
* @brief Construct a new Action List:: Action List object
*/
ActionList::ActionList()
{
   actionCount = 0;
}

/**
* @brief returns the count of actions
* that the customer can take
* @return int number of actions
*/
int ActionList::getActionCount()
{
   return actionCount;
}

/**
* @brief method to get the actions
* depending on movie information
* @param i used for decision making
* @return Action object
*/
Action ActionList::getAction(int i)
{
   Action a;
   
   if (i < actionCount)
   {
      a.setAction(actions[i].getAction(),
      actions[i].getCustomerID(),
      actions[i].getTypeOfMedia(),
      actions[i].getGenre(),
      actions[i].getTitle(),
      actions[i].getReleaseYear(),
      actions[i].getDirector(),
      actions[i].getReleaseMonth(),
      actions[i].getMajorActor());
   }
   return a; // the action to perform
}

/**
* @brief method looks in the file and determins
* the type of action to be performed. Based on
* the files input.
* @param infile ifstream object
*/
void ActionList::buildAction(ifstream &infile)
{
   
   int customerID;
   string line;
   
   while (true)
   {
      getline(infile, line);
      vector<string> vStrings = splitBySpace(line);
      
      if (line.empty() || line.length() == 0) break;
      
      if (vStrings[0].at(0) == 'I')
      {
         //add this action
         this->actions[actionCount].setAction('I', 0, '\0', '\0', "", 0, "", 0, "");
         actionCount++;
      }
      
      else if (vStrings[0].at(0) == 'H')
      {
         customerID = stoi(vStrings[1]);
         this->actions[actionCount].setAction('H', customerID , '\0', '\0', "", 0, "", 0, "");
         actionCount++;
         // print history for customer.
      }
      
      else if (vStrings[0].at(0) == 'B')
      {
         borrowReturnHelper(line,  'B');
      }
      
      else if (vStrings[0].at(0) == 'R')
      {
         borrowReturnHelper(line,  'R');
      }
      
      else
      {}
      
      if (infile.eof()) {
         break;
      }
   }
}


/**
* @brief helper method for return and borrow
* determination. The customer can borrow and return
* @param line string of command
* @param action the action to be taken
*/
void ActionList::borrowReturnHelper(string line,  char action) {
   
   int customerID;
   char typeOfMedia;
   string title;
   int releaseYear;
   string director;
   int releaseMonth;
   string majorActor;
   
   //spliting by space
   vector<string> vStrings = splitBySpace(line);
   customerID = stoi(vStrings[1]);
   typeOfMedia = vStrings[2].at(0);
   
   //checking for comedy movies
   if (vStrings[3].at(0) == 'F')
   {
      int locationF = line.find('F');
      int locationComma = line.find(',');
      title = line.substr(locationF + 2, locationComma - locationF - 2);
      releaseYear = stoi(vStrings[vStrings.size()-1]);
      
      this->actions[actionCount].setAction(action, customerID, typeOfMedia, vStrings[3].at(0), title, releaseYear, "", 0, "");
      actionCount++;
   }
   
   //checking for drama movies
   else if (vStrings[3].at(0) == 'D')
   {
      int indexFirst_D = line.find("D");
      int indexSecond_D = line.find("D", indexFirst_D + 1, 1);
      string restOfLine = line.substr(indexSecond_D + 1);
      vector<string> directorAndTitle = splitByComma(restOfLine);
      director = directorAndTitle[0];
      title = directorAndTitle[1];
      
      this->actions[actionCount].setAction(action, customerID, typeOfMedia, vStrings[3].at(0), title, 0, director, 0, "");
      actionCount++;
   }
   
   //checking for classic movies
   else if (vStrings[3].at(0) == 'C')
   {
      releaseMonth = stoi(vStrings[4]);
      releaseYear = stoi(vStrings[5]);
      int index = line.find(vStrings[5]);
      majorActor = line.substr(index + vStrings[5].length() + 1);
      
      this->actions[actionCount].setAction(action, customerID, typeOfMedia,vStrings[3].at(0),  title, releaseYear, "", releaseMonth, majorActor);
      actionCount++;
   }
}