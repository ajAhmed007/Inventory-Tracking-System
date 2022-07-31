#include "movietable.h"
/**
 * @brief this file performs operations on
 * movie hash table
 * @author Rashid Ibrahim
 */

/**
* @brief creates movieTable object
*/
MovieTable::MovieTable()
{
   this->table_size = 0;
}

/**
* @brief sets the table size
*
* @return void
*/
void MovieTable::setTableSize(int table_size)
{
   this->table_size = table_size;
   table = new vector<Movie*>[table_size];
}

/**
* @brief the hashFunction to get the index for the movie
* @param m movie to be hashed
* @return int
*/
int MovieTable::hashStringFunction(Movie *m)
{
   int index = m->hash() % table_size;
   return index;
}


/**
* @brief creates movieTable obj with the given size
*/
MovieTable::MovieTable(int ts)
{
   this->table_size = ts;
   table = new vector<Movie*>[table_size];
}

/**
* @brief inserts key into the hash table
* @param m movie obj being inserted
* @return void
*/
void MovieTable::insertElement(Movie *m)
{
   int index = hashStringFunction(m);
   table[index].push_back(m);
}

/**
* @brief deletes the key from the hash table
* @param m movie obj being deleted
* @return void
*/
void MovieTable::deleteElement(Movie *m)
{
   int index = hashStringFunction(m);
   
   // finding the key at the computed index
   vector <Movie*> :: iterator i;
   for (i = table[index].begin(); i != table[index].end(); i++)
   {
      if (*i == m)
         break;
   }
   
   // removing the key from hash table if found
   if (i != table[index].end())
      table[index].erase(i);
}

/**
* @brief finds an element from the hashtable using a movie obj
* @param m movie obj being searched for
* @return movie
*/
Movie* MovieTable::findElement(Movie *m)
{
   int index = hashStringFunction(m);
   
   // finding the key at the computed index
   vector <Movie*> :: iterator i;
   for (i = table[index].begin(); i != table[index].end(); i++)
   {
      if (((*i)->getGenre() == 'C') && (*i)->getMajorActor() == m->getMajorActor())
      {
         return *i;
      }
      else if ((*i)->getTitle() == m->getTitle())
      {
         return *i;
      }
   }
   return nullptr;
}


/**
* @brief displays the hashTable
* @return void
*/
void MovieTable::displayHashTable()
{
   for (int i = 0; i < table_size; i++)
   {
      if(!table[i].empty())
      {
         cout << i;
         // traversing at the recent/ current index
         for (auto j : table[i])
         {
            cout<< " ==> " << j->getTitle();
         }
         cout<<endl;
      }
   }
}

/**
* @brief returns all movies in the hash
* @return vector
*/
vector<Movie*> MovieTable::getAllMovies()
{
   vector<Movie*> mlist;
   
   for (int i = 0; i < table_size; i++)
   {
      if(!table[i].empty())
      {
         // traversing at the recent/ current index
         for (auto j : table[i])
         {
            mlist.push_back(j);
         }
      }
   }
   
   return mlist;
}

