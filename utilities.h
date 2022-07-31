#ifndef UTILITIES_H
#define UTILITIES_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;

/**
 * @brief This is a utility file that cotains 
 * some helper fuction to split the 
 * string lines by comma or space
 * @author Rashid Ibrahim
 */

/**
* @brief splits the string by the comma
* @return vector holding all the strings
*/
vector<string> splitByComma(string str);

/**
* @brief splits the string by the space
* @return vector holding all the strings
*/
vector<string> splitBySpace(string str);
#endif