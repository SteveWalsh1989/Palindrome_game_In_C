#ifndef PAL_H_INCLUDED
#define PAL_H_INCLUDED
#include <stdio.h>
#include "Useful.h"

/****************************
 *
 * C Programming Assignment 1
 *
 * Steve Walsh
 *
 * R00151053
 *
 * 23/2/2018
 *
 * Declare created methods and their parameters in this class
 *
 *****************************/


//-------------------------------------
//       Start Game
//-------------------------------------


void displayGameHeader();                   // displays header for game

void start_game(int*);                     // launches game

void randomizeCursorPosition(int* ,int );  // randomize the cursor starting position

int* initialiseArray(int*,int*);           // initializes array from integer

//-------------------------------------
//        Display State
//-------------------------------------
void displayState (int*, int, int, int );  // displayState to display the game state

//-------------------------------------
//        Move Cursor
//-------------------------------------
void moveCursorRight( int*,int );          // moveCursorRight to move cursor one step to the right

void moveCursorLeft( int*,int );           // moveCursorleft to move cursor one step to the left

//-------------------------------------
//        Change number value
//-------------------------------------
void incrementDigitInListAtPos(int* ,int* );// increases value of element currently at position

void decrementDigitInListAtPos(int* ,int* );// decreases value of element currently at position


//-------------------------------------
//       commands
//-------------------------------------
char getCommand();                         // store users command

void processCommand(int*, int, int*, char, int*);// processes users command


//-------------------------------------
//       checking if palindrome
//-------------------------------------
boolean is_palindrome(int* , int ) ;       // checking if the integer passed in is a palindrome

//-------------------------------------
//      user won
//-------------------------------------
void userWon(int);                         // prints congratulations message to user





#endif // PAL_H_INCLUDED
