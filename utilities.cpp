#include "utilities.h"

/**
 * @brief This is a utility file that cotains 
 * some helper fuction to split the 
 * string lines by comma or space
 * @author Rashid Ibrahim
 */

/**
* @brief splits the string by the comma
* @param str str being split by the commas
* @return vector holding all the strings
*/
vector<string> splitByComma(string str) {
   vector<string> vectorOfCharacters;
   string w = "";
   for (int i = 0; i < str.length(); i++)  {
      char x = str.at(i);
      if (x == ',')
      {
         vectorOfCharacters.push_back(w);
         w = "";
      }
      else {
         
         if (x != ' ')
         {
            w = w + x;
         }
         else
         {
            if (!w.empty())
               w = w + x;
         }
      }
   }
   vectorOfCharacters.push_back(w);
   return vectorOfCharacters;
}

/**
* @brief splits the string by the space
* @param str str being split by the spaces
* @return vector holding all the strings
*/
vector<string> splitBySpace(string str) {
   vector<string> vectorOfCharacters;
   string w = "";
   for (int i = 0; i < str.length(); i++)  {
      char x = str.at(i);
      if (x == ' ')
      {
         vectorOfCharacters.push_back(w);
         w = "";
      }
      else {
         w = w + x;
      }
   }
   vectorOfCharacters.push_back(w);
   return vectorOfCharacters;
}
