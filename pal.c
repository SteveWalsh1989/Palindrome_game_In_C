

#include <stdbool.h>
#include <curses.h>
#include <stdlib.h>
#include <sys/time.h>
#include "pal.h"

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
 *****************************/

//-------------------------------------
//       Declaring Methods
//-------------------------------------

/**
 * start_game
 *
 * starts the game
 *
 */
void start_game(int* initialNumber) {
    //-------------------------------------
    //    Declaring Variables
    //-------------------------------------

    int *listOfNumber;                                                              // declare array to hold passed in pointer of initialNumber

    int positionOfCursor = 0;                                                       // define position of cursor

    int numberOfGoes     = 0;                                                       // stores number of guesses the user takes

    boolean isWinner     = False;                                                   // stores if user has won game

    //-------------------------------------
    //    Calling Game Methods
    //-------------------------------------

    displayGameHeader();                                                                   // display game header

    int number_of_digits =  countArray(initialNumber);                                     // gets number of digits for array

    listOfNumber = initialiseArray(initialNumber,listOfNumber);                            // generate array

    randomizeCursorPosition(&positionOfCursor, number_of_digits );                         // randomizes cursor position at start

    while (!isWinner) {                                                                // keep playing until user wins

        displayState(listOfNumber, positionOfCursor, number_of_digits, numberOfGoes);  // display state of game

        char command = getCommand();                                                   // stores user command

        processCommand(&listOfNumber, number_of_digits, &positionOfCursor,
                       command, &numberOfGoes);                                        // processes user command

        isWinner = is_palindrome(listOfNumber, number_of_digits);                      // checks if user won
    }
    userWon(numberOfGoes);                                                                 // prints congratulations to user




}

/**
 * displayGameHeader
 *
 * displays header for game with name, goal and controls
 *
 */
void displayGameHeader(){
    printf("\n     ---------------------        ");
    printf("\n                                  ");
    printf("\n      THE PALINDROME GAME         ");
    printf("\n                                  ");
    printf("\n     ---------------------        ");
    printf("\n                                  ");
    printf("\n     Convert the List into        ");
    printf("\n      a palindrome to win         ");
    printf("\n                                  ");
    printf("\n     ---------------------        ");
    printf("\n                                  ");
    printf("\n    'a' = move cursor left        ");
    printf("\n    'd' = move cursor right       ");
    printf("\n    'w' = increase digit value    ");
    printf("\n    'd' = decrease digit value    ");
    printf("\n    enter key = submit command    ");
    printf("\n                                  ");
    printf("\n     ---------------------        ");
}



/**
 * displayState
 *
 * shows the state of the 'game'
 *
 * show the list of numbers in the array and the value of the cursor.
 *
 *@param  listOfNumbers[]  :  address of listOfNumbers
 *@param  positionOfCursor : location of cursor
 *@param max               : number of values
 *@param numberOfGoes     : number of goes the user takes
 */
void displayState (int* plistOfNumbers, int cursorValue, int max, int numberOfGoes){

    int i = 0;                                             // initialise counter index

    printf("\n\n\t\t Game State ");                        // print to console

    printf("\n -----------------------------\n\n");        // line break to split content

    printf("< ");                                          // open array for numbers

    while( i < max ){                                      // loop through array of number{

        printf("%d", plistOfNumbers[i]);                   // print the address stored in listOfNumbers

        i++;                                               // increment counter
    }
    printf(" >");                                          // close array for numbers

    printf("\t\t");                                        // separator of data

    printf("< Num Goes: %d >", numberOfGoes );       // print number of goes

    // printf("\t <Cursor at %d >", cursorValue );         // print cursor value

    printf("\n");                                          // new line

    for(int i=0; i < (cursorValue+2); i++ ) {              // loop until number of cursor + 1 fpr < in number list

        printf(" ");                                       // print space
    }
    printf("^");                                           // print cursor

    printf("\n -----------------------------\n");          // line break to split content

    printf(  "\n Enter your move: ");                      // ask  user to enter move

}
/**
 * moveCursorRight
 *
 * moves the cursor one value to the right
 *
 *@param  pPosOfCursor : location of cursor
 *@param  max          : max number of digits
 */
void moveCursorRight( int* pPosOfCursor, int max ) {

    if ( *pPosOfCursor < max -1 ) {                        // if position is 0- 5

        *pPosOfCursor += 1;                                // increase by 1 and save

    } else {                                               // if position is end of list

        *pPosOfCursor = 0;                                 // make it 0
    }
}
/**
 * moveCursorRight
 *
 * moves the cursor one value to the right
 *
 *@param  pPosOfCursor : location of cursor
 *@param  max          : max number of digits
 */
void moveCursorLeft( int* pPosOfCursor, int max ) {

    if ( *pPosOfCursor > 0 ) {                              // if position is 1-6

        *pPosOfCursor -= 1;                                 // move left

    } else {                                                // if position is 0

        *pPosOfCursor = max - 1;                            // set to end of list
    }
}
/**
 * incrementDigitInListAtPos
 *
 * increments value at cursor position
 *
 *@param  pListOfNumbers  : list of number addresses
 *@param  pPosOfCursor     : location of cursor
 */
void incrementDigitInListAtPos(int* pListOfNumbers,int* positionOfCursor ){


    if ( *(pListOfNumbers + *positionOfCursor) == 9 ) {    // Scenario 1: Value is 9

        *(pListOfNumbers + *positionOfCursor) = 0;         // resets value at position to 0

    } else {                                               // Scenario 2: value not 9

        *(pListOfNumbers + *positionOfCursor) += 1;        // increments value by one
    }
}

/**
 * decrementDigitInListAtPos
 *
 * decreases value at cursor position
 *
 *@param  pListOfNumbers  : list of number addresses
 *@param  pPosOfCursor     : location of cursor
 */
void decrementDigitInListAtPos(int* pListOfNumbers,int* positionOfCursor ){

    if ( *(pListOfNumbers + *positionOfCursor) == 0 ) { // Scenario 1: Value is 9

        *(pListOfNumbers + *positionOfCursor) = 9;      // resets value at position to 0

    } else {                                            // Scenario 2: value not 9

        *(pListOfNumbers + *positionOfCursor) -= 1;     // increments value by one
    }
}

/**
 * getCommand
 *
 * Stores command entered by user
 *
 *@returns command : integer value of the letter the user selected
 */
char getCommand() {

    int command = getchar();                                                     // stores character from user

    int dump = getchar();                                                        // clear enter

    if (command == 'w' || command == 'a' || command == 'd' || command == 'x' ) { // checks if valid input

    } else {
        printf("\n*------------------------------------------*\n");              // line break to split content
        printf(  "* Error: Enter a valid command ( a d w x ) *");                // prints error if invalid input
        printf("\n*------------------------------------------*\n\n");            // line break to split content
    }

    return command;                                                              // returns users character

}

/**
 * processCommand
 *
 *
 *
 *@param pListOfNumbers    : address of first element in list
 *@param size              : size of the list
 *@param pPositionOfCursor : position of the cursor
 *@param command           : command the user enters
 */
void processCommand(int* pList, int size, int* pPositionOfCursor, char command, int* numberOfGoes) {

    if(command =='w'){                                          // Scenario 1: User enters w

        incrementDigitInListAtPos(pList, pPositionOfCursor);    // increases number

        *numberOfGoes+=1;                                       // increase number of goes

    } else if(command =='x'){                                   // Scenario 2: User enters x

        decrementDigitInListAtPos(pList, pPositionOfCursor);    // decreases number

        *numberOfGoes+=1;                                       // increase number of goes

    } else if( command =='a'){                                  // Scenario 3: User enters x

        moveCursorLeft(pPositionOfCursor,size);                 // move cursor left

        *numberOfGoes+=1;                                       // increase number of goes

    } else if(command =='d') {                                  // Scenario 4: User enters d

        moveCursorRight(pPositionOfCursor, size);               // move cursor right

        *numberOfGoes+=1;                                       // increase number of goes

    }
}

/**
 * isPalindrome
 *
 * checks if the array is a palindrome
 *
 * Returns true if a palindrome
 * Returns false if not a palindrome
 *
 *@param pListOfNumbers : address of first element in list
 *@param size           : size of the list
 */
boolean is_palindrome(int* pListOfNumbers, int size) {

    boolean isValid = True;                                                  // initiate return value

    for ( int i = 0 ; i < size ; i++ ) {                                     // loop through array size

        if ( *(pListOfNumbers + i) != *((pListOfNumbers + size - 1) - i)) {  // copy first element of array with its last each time

            isValid =  False;                                                // if not the same then it is not a palindrome
        }
    }
    return isValid ;                                                         // Return if integer is palindrome
}


/**
 *
 * userWon
 *
 * Tells user they won and how many goes it look
 *
 * @param numberOfGoes  : number of goes it took user to win
 */
void userWon(int numberOfGoes){

    printf("\n");
    printf("\n*--------------------------------*");
    printf("\n*    Congratulations You Won!    *");
    printf("\n*--------------------------------*");
    printf("\n\n You took a total number of %d goes to create the palindrome!\n\n", numberOfGoes);



}

int countArray(int* integer){


    int copy = *integer;                 // create copy to get how many elements in array

    int count = 0;                       // counter to check how long array will need to be

    while (copy > 0) {                   // keeps looping while integer is bigger than 0

        count +=1;                       // increases count each time

        copy /= 10;                      // stores new integer value
    }
    return count;

}


/**
 * initialiseArray
 *
 * creates a list of numbers from integer
 *
 *
 *@param integer : address of the integer to be converted to array
 */
int* initialiseArray(int* integer, int* initialNumber) {


    int copy = *integer;                 // create copy to get how many elements in array

    int count = 0;                       // counter to check how long array will need to be

    while (copy > 0) {                   // keeps looping while integer is bigger than 0

        count +=1;                       // increases count each time

        copy /= 10;                      // stores new integer value
    }

    int* listNumbers = (int*) malloc(count * sizeof(int));     // creates array to be the size of number of digits in integer

    for ( int i = count-1; i >= 0 ; i --) {                    // loop through number of digits

        int digit = *integer % 10;                             // stores last digit of integer

        listNumbers[i] =digit;                                 // stores value of digit taken from integer in array

        *integer /= 10;                                        // stores new integer value

    }

    return listNumbers;

}


/**
 * randomizeCursorPosition
 *
 * randomizes the cursor position at the start of the game
 *
 *@param pPosOfCursor   : address of first cursor
 *@param size           : size of the list
 */
void randomizeCursorPosition(int* pPosOfCursor,int size) {

    srand ( time(NULL) );             // makes sure random number if different each time

    *pPosOfCursor = rand() % (size);  // gives position of cursor random value between 0 and the size of list


}


