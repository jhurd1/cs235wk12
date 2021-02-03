/***********************************************************************
 * Module:
 *    Assignment 12, Spell Check
 *    Brother Kirby, CS 235
 * Author:
 *    Daniel Perez, Jamie Hurd, Benjamin Dyas
 * Summary:
 *    This program will implement the spellCheck() function
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "hash.h"
#include "spellCheck.h"
using namespace std;

/********************************************
 * FUNCTION:     READFILE
 * DESCRIPTION:  Reads file and checks spelling
 *               while reading
 * PARAMETER:    SHash, string
 ********************************************/
void readFile (SHash & d, const string &fileName)
{
   //create and open stream object
   ifstream file;
   file.open (fileName.c_str());

   //if reading fails
   if (file.fail())
   {
      std::cout << "Unable to read file named "<< fileName << "\n";
      return;
   }

   string word;
   bool firstRun = true;
   bool NoErrors = true;
   
   //while there is something to read and we are not at the end
   //   of the file
   while (file >> word && !file.eof())
   {
      bool misspelled = false;

      //this variable just preserves the word before making it
      //   lowercase
      string capitalized = word;

      //transform the word to lowercase for ease of storage
      std::transform(word.begin(), word.end(), word.begin(), ::tolower);

      //if not found in the dictionary, it is misspelled
      misspelled = !(d.find(word));

      //prevents the "no error" from appearing if there is at least one
      //   error
      if(misspelled)
      {
         NoErrors = false;
      }

      //if the word is mispelled
      if(misspelled)
      {
         //this outputs "Misspelled: " only the first time
         if(firstRun)
         {
            std::cout << "Misspelled: ";
            firstRun = false;
            std::cout << capitalized; 
         }
         else
         {
            //this prevents the comma from being added at the end
            std::cout << ", " << capitalized; 
         }         
      }
   }

   //close file
   file.close();

   //works in pair with the if statement before
   if(NoErrors)sftp:
   {
      std::cout << "File contains no spelling errors\n";
   }
   else
   {
      //this is part of the "error" run
      cout << "\n";
   }
    
}

/********************************************
 * FUNCTION:     READ DICTIONARY
 * DESCRIPTION:  Reads the dictionary
 *               into a SHash
 * PARAMETER:    SHash, string
 ********************************************/
void readDictionary (SHash & d)
{
   //hardcoded because the dictionary path is not prompted for
   string fileName{"/home/cs235/week12/dictionary.txt"};
   //string fileName{"/mnt/c/00cs235/dictionary.txt"}; //local testing
   
   ifstream file;
   file.open (fileName.c_str());

   // checks if there was an error reading the file
   if (file.fail())
   {
      std::cout << "Unable to read file\n";
      return;
   }

   string word;
   //read file into the SHash (String Hash)
   while (file >> word && !file.eof())
   {
      //lowercase for ease of storage and handling
      transform(word.begin(), word.end(), word.begin(), ::tolower);
      
      
      d.insert(word);
   }
   file.close();
}

/********************************************
 * FUNCTION:     SPELLCHECK
 * DESCRIPTION:  Prompt the user for a file
 *               to spell-check
 * PARAMETER:    N/A
 ********************************************/
void spellCheck()
{
   // prompts for file name
   std::string fileName;
   std::cout << "What file do you want to check? ";
   std::cin >> fileName;

   // makes a string hash based on the 26
   // letters in the alphabet
   SHash d(26);

    // read from the dictionary to make the comparison
   readDictionary(d);
   readFile(d, fileName);

}
