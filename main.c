
#include <stdlib.h>
#include <sys/time.h>
#include "pal.h"

/******************************************************************************
 *
 * C Programming Assignment 1 v2
 *
 * Steve Walsh
 *
 * R00151053
 *
 * 13/11/2018
 *
 * Palindrome game
 *
 * Presents list of numbers to user and goal is to make it a palindrome
 * User can use keyboard to move between numbers using a and d keys
 * user can increment or decrement values in list using w and x keys
 * Program will count number of goes it takes user to complete game
 *
 *
 * Three scenarios to choose from
 *      1: uses intitialNumber defined in main.c
 *      2: uses listOfNumber[] defined in pal.c
 *      3: uses random number for intitialNumber
 *
 *
 *******************************************************************************/


int main() {

    //-------------------------------------
    //       Scenario Selection
    //-------------------------------------

    // Change value of testNumber to run program in the different scenarios

    int testNumber = 3;

    //-------------------------------------
    //       Scenarios
    //-------------------------------------

    if(testNumber == 1) {                        // Scenario 1: use initialNumber defined in main.c

        int initialNumber  = 987986;             // stores integer to be converted into list

        start_game(&initialNumber);              // launches game


    }else if(testNumber == 2) {                  // Scenario 2:   use initialised array in pal.c

        start_game2();

    }else if(testNumber == 3) {                  // Scenario 3: create a random number to store in intialNumber to use



        srand ( time(NULL) );                    // makes sure random number if different each time

        int initialNumber = rand() % (2147483);  // creates random number to use as initialNumber up to max int size

        start_game(&initialNumber);              // launches game


    }


    return 0;
}
