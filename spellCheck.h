/***********************************************************************
 * Module:
 *    Assignment 12, Spell Check
 *    Brother Kirby, CS 235
 * Author:
 *    Daniel Perez, Jamie Hurd, Benjamin Dyas
 * Summary:
 *    This program will implement the spellCheck() function
 ************************************************************************/

#include<cctype>
#ifndef SPELL_CHECK_H
#define SPELL_CHECK_H

/****************************************
 * S HASH
 * A simple hash of integers
 ****************************************/
class SHash : public custom::Hash <std::string>
{
public:
   SHash(int numBuckets)    : Hash <std::string> (numBuckets) {}
   SHash(const SHash & rhs) : Hash <std::string> (rhs)        {}

   // hash function organizes the words by letter in the alphabet
   int hash(const std::string & word) const
   {
      // words should have been passed as lowercase
      // there is this precaution, however
      char search = tolower(word[0]); //precaution

      int index;
      
      // simply match the first letter of the word
      // to an index
      // a letter ref per bucket
      switch(search)
      {
         case 'a':
            index = 0;
            break;
         case 'b':
            index = 1;
            break;
         case 'c':
            index = 2;
            break;
         case 'd':
            index = 3;
            break;
         case 'e':
            index = 4;
            break;
         case 'f':
            index = 5;
            break;
         case 'g':
            index = 6;
            break;
         case 'h':
            index = 7;
            break;
         case 'i':
            index = 8;
            break;
         case 'j':
            index = 9;
            break;
         case 'k':
            index = 10;
            break;
         case 'l':
            index = 11;
            break;
         case 'm':
            index = 12;
            break;
         case 'n':
            index = 13;
            break;
         case 'o':
            index = 14;
            break;
         case 'p':
            index = 15;
            break;
         case 'q':
            index = 16;
            break;
         case 'r':
            index = 17;
            break;
         case 's':
            index = 18;
            break;
         case 't':
            index = 19;
            break;
         case 'u':
            index = 20;
            break;
         case 'v':
            index = 21;
            break;
         case 'w':
            index = 22;
            break;
         case 'x':
            index = 23;
            break;
         case 'y':
            index = 24;
            break;
         case 'z':
            index = 25;
            break;
      }
      return index;
   }
};

void spellCheck();

#endif // SPELL_CHECK_H
