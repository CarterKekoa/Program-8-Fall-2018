//file: queens.cpp
//authors:  Carter Mooring
//username: cmooring
//date: November 15th, 2018

// ADT Queens (motivated by the famous Eight Queens Problem)
//      data object: a number of queens on a chess board
//      operations: create, create a certain size, destroy
//                  place a queen on the board, remove a queen from the board
//                  check if a spot is valid (previous queens cannot attack)
//                  print the queens on the board
// Gonzaga University, CPSC 122, Dr. Yerion

#include "queens.h"
#include <iostream>

using namespace std;

   //creates an empty chessboard of default size 8
   //post empty chessboard is assigned with no queens yet on it
   //usage Queens queensOnBoard;
   Queens::Queens()
   {
	   for (int row = 0; row < 8; row++)
	   {
		   for (int column = 0; column < 8; column++)
		   {
			   board[row][column] = false;
		   }
	   }
	   queensCount = 0;
	   boardSize = 8;
   }

   //creates an empty chessboard of a certain size
   //post empty chessboard is assigned with no queens yet on it
   //usage Queens queensOnBoard(4);
   Queens::Queens(int boardsize)
   {
	   for (int row = 0; row < boardsize; row++)
	   {
		   for (int column = 0; column < boardsize; column++)
		   {
			   board[row][column] = false;
		   }
	   }
	   queensCount = 0;
	   boardSize = boardsize;
   }

   //destroys the board
   //pre Queens object exsits
   //post Queens object does not exist
   //usage automatically called at the end of scope
   Queens::~Queens()
   {
   }

   //places a queen on the chessboard
   //pre board exists with queens in rows 0 to queensCount - 1
   //post a queen has been placed on the board in row queensCount and column
   //usage queensOnBoard.placeQueen(2);
   void Queens::placeQueen(int column)
   {
	   board[queensCount][column] = true;
	   queensCount++;
   }

   //removes a queen from the chessboard
   //pre queens exist on the board in rows 0 to queensCount - 1
   //post removes the queen in row queensCount - 1 and column
   //usage queensOnBoard.removeQueen(3);
   void Queens::removeQueen(int column)
   {
	   queensCount--;
	   board[queensCount][column] = false;
   }

   //checks to see of a square on the chessboard is safe for a queen
   //pre queens are on the board in rows 0 to queensCount - 1
   //post if the square at row queensCount and column is safe for a queen
   //        returns true else returns false
   //
   bool Queens::isValidSpot(int column) const
   {
     bool isClearVertically = true;
     int row = queensCount - 1;
     while(row >= 0 and isClearVertically)
     {
       isClearVertically = not board[row][column];
       row--;
     }

     bool isClearNorthEast = true;
     row = queensCount - 1;
     int columnReplica = column + 1;
     while(row >= 0 and columnReplica <= boardSize and isClearNorthEast)
     {
       isClearNorthEast = not board[row][columnReplica];
       row--;
       columnReplica++;
     }

     bool isClearNorthWest = true;
     row = queensCount - 1;
     int columnReplica2 = column - 1;
     while(row >= 0 and columnReplica2 >= 0 and isClearNorthWest)
     {
       isClearNorthWest = not board[row][columnReplica2];
       row--;
       columnReplica2--;
     }

    return isClearVertically && isClearNorthEast && isClearNorthWest;
   }

   //prints the chessboard and queens on it
   //pre there may or may not be queens on the board
   //post prints the board to look like a chessboard with squares and shows the queens
   //
   void Queens::printBoard() const
   {
     cout << endl << endl;

     int num = 1;
     cout << "   ";
     while(num < boardSize + 1)
     {
       cout << num << " ";
       num++;
     }
     cout << endl << "  ";
     num = 1;
     while(num < boardSize + 1)
     {
       cout << "▁▁";
       num++;
     }
     cout << "▁" << endl;
     num = 1;


     for(int i = 0; i < boardSize; i++)
     {
       cout << num << " ";
       for(int j = 0; j < boardSize; j++)
       {
         cout << "┃";
         if(board[i][j])
         {
           cout << "♛";
         }
         else
         {
           cout << "▁";
         }
       }
       cout << "┃" << endl;
       num++;
     }

     cout << "  " << "▔";
     num = 1;
     while(num < boardSize + 1)
     {
       cout << "▔▔";
       num++;
     }
   }

   //checks to see if the queens problem is solved
   //pre there may or may not be queens on the board
   //post if the number of queens on the board is the same as board size
   //      then it returns true else returns false
   //usage if(board.IsSolved())
   bool Queens::isSolved() const
   {
	   return(queensCount == boardSize);
   }
