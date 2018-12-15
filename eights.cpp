//file: eights.cpp
//authors:  Carter Mooring
//username: cmooring
//date: November 15th, 2018
// This program solves the classic queens problem. This problem is that for a board
// of size 8, it is difficult to arrange 8 queens so that they cannot "check" each other.
// This program automates that process for any board size that a user wishes.
// Gonzaga University, CPSC 122, Dr. Yerion

#include "queens.h"
#include <iostream>
using namespace std;

//Solves the Queens Problem
//pre: board contains partial solution
//post: solved board is printed
//usage: solveQueensProblem (myboard);
void solveQueensProblem (Queens& board);

//Accept from user the number of queens for the problem
//post: returns number of queens input by user and gets past user's entered newline
//usage: numQueens = howManyQueens();
int howManyQueens ();

//prints a number of new lines
//pre: num has a value > 0
//post: num newlines have been output to the screen
//usage: printNewlines(3);
void printNewlines(int num);

//Asks the user whether or not to continue
//(gives the user time to consider reflectively what is on the screen)
//post: if yes hits <enter> program continues
//usage: toContinue();
void toContinue();

int main()
{
  Queens myboard(howManyQueens());
  solveQueensProblem(myboard);

  return 0;
}

// Solves the Queens Problem
// pre: board contains partial solution
// post: solved board is printed
// usage: solveQueensProblem(myboard);
void solveQueensProblem (Queens& boardStuff)
{
   if (boardStuff.isSolved())
   {
     boardStuff.printBoard();
     printNewlines(2);
     toContinue();
   }
   else
   {
     for (int column = 0; column < boardStuff.boardSize; column++)
     {
       if(boardStuff.isValidSpot(column))
       {
         boardStuff.placeQueen(column);
         solveQueensProblem(boardStuff);
         boardStuff.removeQueen(column);
       }
     }
   }
}

//Accept from user the number of queens for the problem
//post: returns number of queens input by user and gets past user's entered newline
//usage: numQueens = howManyQueens();
int howManyQueens ()
{
   int numberOfQueens;
   char enter;

   printNewlines(3);
   cout << "enter the number of queens > ";
   cin >> numberOfQueens;
   cin.get(enter);

   return numberOfQueens;
}

// prints a number of new lines
// pre: num has a value > 0
// post: num newlines have been output to the screen
// usage: printNewlines(3);
void printNewlines(int num)
{
   for (int k = 0; k < num; k++)
      cout << endl;
}

// Asks the user whether or not to continue
// (gives the user time to consider reflectively what is on the screen)
// post: if yes hits <enter> program continues
// usage: toContinue();
void toContinue()
{
  char enter;

  printNewlines(2);
  cout << "To continue, hit <enter> ";
  cin.get(enter);
  cout << endl;
}
