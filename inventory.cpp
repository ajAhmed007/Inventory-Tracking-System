#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include"inventory.h"
#include"classic.h"
#include"utilities.h"
using namespace std;

/**
* @brief This class holds information about the movie inventory
* @authors Daniel Wang
*/

/**
* @brief inventory constructor, constructs an inventory obj
*/
Inventory::Inventory()
{
   this->hash_table_size = 1000;
   
   listSize = 0;
   
   mList.setTableSize(hash_table_size);
   
}

/**
* @brief add a movie obj to the inventory l ist
* @param _movie movie obj being added to inventory
* @return void
*/
void Inventory::add(Movie* _movie)
{
   listSize++;
   
   mList.insertElement(_movie);
}

/**
* @brief takes in an input file and reads it in order to build the list
* of movies that will be stored in the inventory
* @param infile inputFile being read to convert into movies stored in
* the inventory
* @return void
*/
void Inventory::buildInventory(ifstream &infile)
{
   string line;
   while (true)
   {
      getline(infile, line);
      vector<string> vStrings = splitByComma(line);
      if (line.empty() || line.length() == 0) break;
      
      if (vStrings[0].at(0) == 'C')
      {
         initializeClassicConstructor(vStrings);
      }
      else if (vStrings[0].at(0) == 'F')
      {
         initializeCommedyConstructor(vStrings);
         
      }
      else if (vStrings[0].at(0) == 'D')
      {
         initializeDramaConstructor(vStrings);
      } else {
         
      }
      
      if (infile.eof()) {
         break;
      }
   }
}
/**
* @brief if genre is found to be drama, will break apart the string
* to put into the constructor of the drama class
* @param String, string value of what was read from the inputFile
* @return void
*/
void Inventory::initializeDramaConstructor(vector<string> vStrings)
{
   int  stockCount = stoi(vStrings[1]);
   string director = vStrings[2];
   string title  = vStrings[3];
   int  releaseYear  = stoi(vStrings[4]);
   Movie* m = new Drama(vStrings[0].at(0), stockCount, director, title, releaseYear);
   add(m);
   
}

/**
* @brief if genre is found to be comedy, will break apart the string
* to put into the constructor of the comedy class
* @param String, string value of what was read from the inputFile
* @return void
*/
void Inventory::initializeCommedyConstructor(vector<string> vStrings)
{
   int  stockCount = stoi(vStrings[1]);
   string director = vStrings[2];
   string title  = vStrings[3];
   int  releaseYear  = stoi(vStrings[4]);
   Movie* m =  new Comedy(vStrings[0].at(0), stockCount, director, title, releaseYear);
   add(m);
}

/**
* @brief if genre is found to be classic, will break apart the string
* to put into the constructor of the classic class
* @param String, string value of what was read from the inputFile
* @return void
*/
void Inventory::initializeClassicConstructor(vector<string> vStrings)
{
   int  stockCount = stoi(vStrings[1]);
   string director = vStrings[2];
   string title  = vStrings[3];
   string restOfTheLine = vStrings[4];
   vector<string> restOfTheLineSplitted = splitBySpace(restOfTheLine);
   string majorActor = restOfTheLineSplitted[0] + " " + restOfTheLineSplitted[1];
   int yearIndex = restOfTheLineSplitted.size();
   int releaseMonth = stoi(restOfTheLineSplitted[yearIndex-2]);
   int releaseYear = stoi(restOfTheLineSplitted[yearIndex-1]);
   Movie* m = new Classic(vStrings[0].at(0), stockCount, director, title, releaseMonth, majorActor, releaseYear);
   add(m);
}

/**
* @brief will display the hashtable of the inventory
*
* @return void
*/
void Inventory::display()
{
   mList.displayHashTable();
   
}

/**
* @brief find the index of the movie
*
* @param v vector holding the movies
* @param m movie obj
*
* @return int representing index of movie
*/
int find_movie(vector<pair<string,int> > v, Movie *m)
{
   int i;
   for (i = 0; i < v.size(); i++)
   {
      if (m->getTitle() == v.at(i).first)
      {
         break;
      }
   }
   
   if (i == v.size())
   {
      return -1;
   }
   else
   {
      return i;
   }
   
}

/**
* @brief prints to system current movies in inventory
*
* @return void
*/
void Inventory::show()
{
   vector<Movie*> l = mList.getAllMovies();
   vector<pair<string,int> > movieList;
   movieList.push_back(make_pair("Hello", 10));
   
   Movie *movie;
   
   int i;
   int movieCount = l.size();
   for (i = 0; i < movieCount; i++)
   {
      movie = l.at(i);
      int indexFound = find_movie(movieList, movie);
      if(indexFound >= 0)
      {
         movieList.at(indexFound).second = movieList.at(indexFound).second + movie->getStockCount();
         
      }
      else
      {
         movieList.push_back(make_pair(movie->getTitle(), movie->getStockCount()));
      }
   }
   
   cout << "============================================================\n";
   cout << "Inventory\n";
   cout << "------------------------------------------------------------\n";
   cout << "#\t" << setw(36) << left <<"Title" << "\tStock\n";
   cout << "------------------------------------------------------------\n";
   
   
   for (i = 0; i < movieList.size(); i++)
   {
      cout << i+1 << "\t" << setw(36) << left << movieList.at(i).first << "\t" << movieList.at(i).second << endl;
   }
   
   cout << "------------------------------------------------------------\n";
   
}

/**
* @brief finds movie using title and year released
* @param title title of the movie
* @param year year movie was released
* @return movie obj being looked for
*/
Movie* Inventory::findMovie(string title, int year)
{
   Movie *movie, *tmp;
   tmp = new Comedy('F', 0, "", title, year);
   movie = mList.findElement(tmp);
   delete tmp;
   return movie;
}

/**
* @brief finds movie using director and title
* @param director director of the movie
* @param title title of the movie
* @return movie obj being looked for
*/
Movie* Inventory::findMovie(string director, string title)
{
   Movie *movie, *tmp;
   tmp = new Drama('D', 0, director, title, 0);
   movie = mList.findElement(tmp);
   delete tmp;
   return movie;
}

/**
* @brief finds movie using month and year movie was released,
* and major actor
* @param month month movie was released
* @param year year movie was released
* @param majorActor major actor assosiated with film
* @return movie obj being looked for
*/
Movie* Inventory::findMovie(int month, int year, string majorActor)
{
   Movie *movie, *tmp;
   tmp = new Classic('C', 0, "", "", month, majorActor, year);
   movie = mList.findElement(tmp);
   delete tmp;
   return movie;
}

