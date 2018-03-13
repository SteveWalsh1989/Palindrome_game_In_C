
#include "pal.h"

/****************************
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
 *
 *        Trying to implement the feature to work with the initialNumber
 *        to create the array of numbers for user to play with
 *        1 : Doesnt increase / decrease digits using w / x
 *
 *****************************/


int main() {

    int initialNumber  = 193643;      // stores integer to be converted into list

    start_game(&initialNumber);        // launches game

    return 0;
}
