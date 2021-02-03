###############################################################
# Program:
#     Assignment 12, Hash
#     Brother Kirby, CS235
# Author:
#     Daniel Perez, Jamie Hurd, Benjamin Dyas
# Summary:
#     This program contains the implementation of a Hash Table.
#     The hash table will be used for a spell check program.
# Time:
#     Pair programming: 06 hours
#     Daniel:           03 hours
#     Benjamin:         03 hours
#		Jamie:            03 hours
# The most difficult part:
#     Daniel:   The most difficult part was the logic of a
#               Hash table; we decided to use an array of 
#               Lists to handle the collisions. After the logic
#					 was thoroughly discussed, the rest of the
#               assignment was simpler.
#					 Case sensitivity was buggy to say the least
#               when comparing for the Hash.
#	   Benjamin: The most difficult part was working though the
#               structure of what is a hash table. We were
#               discussing if we whould establish the table
#               as an array with a list data type. We decided
#               to go with this method of implementation.
#               Once the planning of how to set up the table
#               was over we were able to flow through the
#               rest of the program.
#	   Jamie:    The most difficult part was coordinating the
#				    case sensitivity for chars when c-out'ing the
#				    comparison between the file and the dictionary.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment12.o spellCheck.o
	g++ -o a.out assignment12.o spellCheck.o -g 
	tar -cf assignment12.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment12.o     : the driver program
#      spellCheck.o       : the spell-check program and driver
##############################################################
assignment12.o: hash.h assignment12.cpp list.h
	g++ -c assignment12.cpp -g

spellCheck.o: hash.h spellCheck.h spellCheck.cpp
	g++ -c spellCheck.cpp -g

