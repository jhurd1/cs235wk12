/***********************************************************************
 * Component:
 *    Assignment 12, Hash Table
 *    Brother Kirby, CS 235
 * Author:
 *    Daniel Perez, Jamie Hurd, Benjamin Dyas
 * Summary:
 *    Create a hash table ADT
 ************************************************************************/

#ifndef HASH
#define HASH

#include "list.h"  

namespace custom
{
   /************************************************
    * CLASS: HASH
    * Container class element that contains info
    * for a hash list
    ***********************************************/
   template<class T>
   class Hash
   {
   public:
      // constructors and destructor
      Hash (int numBuckets);
      Hash (const Hash<T> & rhs);
      ~Hash () { clear(); }

      //overloaded operators
      Hash & operator = (const Hash & rsh);

      list<T> & operator [] (int index) const
      {
         return table[index];
      }
      
      // standard Hash interfaces
      int  size () const { return numElements; }
      bool empty () const { return (numElements == 0); }
      int  capacity () const { return numBuckets; }
      
      void clear () 
      {
         for(int i = 0; i < numBuckets; i++)
         {
            table[i].clear();
         }
         delete [] table;
      }

      bool find (T element);
      void insert (T element);

      // virtual functions
      virtual int hash (const T & t) const = 0; //pure virtual function
   
   private:
      //private members
      int numElements;
      int numBuckets;
      list<T> * table;
         
   };

   /********************************************
    * CONSTRUCTOR: HASH
    * PARAMETER:   numBuckets
    ********************************************/
   template <class T>
   custom :: Hash<T> :: Hash (int numBuckets)
   {
      //try to allocate a new array of "buckets"
      try
      {
         this->table = new list<T>[numBuckets];
         this->numBuckets = numBuckets;
      }
      catch (std::bad_alloc)
      {
         throw "";
      }
      //numElements is zero when only capacity
      //   is specified
      this->numElements = 0;
   }

   /********************************************
    * COPYCONSTRUCTOR: HASH
    * PARAMETER:       A const Hash to copy
    ********************************************/
   template <class T>
   Hash<T> :: Hash(const Hash<T> & rhs)
   {
      //standard copy of members
      numElements = rhs.numElements;
      numBuckets = rhs.numBuckets;
      
      //try to allocate a new arra of "buckets"
      try
      {
         this->table = new list<T>[numBuckets];
      }
      catch (std::bad_alloc)
      {
         throw "";
      }
      // traverse and copy left to right
      for(int i = 0; i < numBuckets; i++)
      {
         table[i] = rhs[i];
      }
   }
   
   /********************************************
    * ASSIGNOVERLOAD: ASSIGNMENT OPERATOR
    * PARAMETER:      A const Hash to copy
    ********************************************/
   template <class T>
   Hash<T> & Hash<T> :: operator = (const Hash<T> & rhs)
   {
      //standard copy of members
      numElements = rhs.numElements;
      numBuckets = rhs.numBuckets;
      
      //try to allocate a new arra of "buckets"
      try
      {
         this->table = new list<T>[numBuckets];
      }
      catch (std::bad_alloc)
      {
         throw "";
      }

      //element by element copy
      for(int i = 0; i < numBuckets; i++)
      {
         //this makes use of the operator=
         //   of the list, copying the whole
         //   list returned by operator[]
         this->table[i] = rhs[i];
      }
      // return "this"
      return *this;
   }

   /********************************************
    * FUNCTION:     FIND
    * DESCRIPTION:  returns a bool value if
    *               found
    * PARAMETER:    a data element to find
    ********************************************/
   template<class T>
   bool Hash<T> :: find(T element)
   {
      // gets hash index
      int index = hash(element);
      
      // pointers for comparison
      typename custom::list<T>::iterator itNull;
      typename custom::list<T>::iterator itFound;
      
      // searches for the desired element
      itFound = table[index].find(element);
      return itNull != itFound;
   }

   /********************************************
    * FUNCTION:     INSERT
    * DESCRIPTION:  inserts a element
    * PARAMETER:    a data element to insert
    ********************************************/
   template<class T>
   void Hash<T> :: insert(T element)
   {
      // gets hash index
      int index = hash(element);
      // adds element to end of the chosen bucket      
      table[index].push_back(element);
      // increment numElements to keep count
      numElements++;
   }
}
#endif // HASH_H