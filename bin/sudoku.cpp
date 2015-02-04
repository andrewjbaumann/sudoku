/******************************************************************************
Title : sudoku.cpp
Author : Andrew Baumann
Created on : Feb 23 2014
Description : Class that creates a perfect sudoku grid.
Build with : g++ sudokumain.cpp sudoku.cpp
Special Thanks : Zablan, Alvin. Tung, Justin. Wu, Danny. Vora, Aarsh.
Zheng, Tony. Shterenberg, Tereza. Brizan, David-Guy (in no order).
Used mahiya's code @ http://www.cplusplus.com/forum/beginner/76616/ 
for advice on the 3x3 grid checker. 
******************************************************************************/
#include <iostream>
#include <stdlib.h>     
#include <time.h>   
#include "sudoku.hpp"

using namespace std;

Sudoku::Sudoku() //constructor
{
  srand (time(NULL)); //seeds rand
  const int zero = 0; //used for sudokuize
  num = storeNum = 0; //used in sudokuize
  size = 9; //fills int columns and int rows with size
  grid = new int * [size]; //creates a new pointer array
  for (int a = 0; a < size; a++)
    grid[a] = new int[size]; //creates the second dimension

  for (int b  = 0; b < size; b++)
    for (int c = 0; c < size; c++)
      grid[b][c] = zero; //defaults the grid to 0s

  sudokuize(zero,zero); //SUDOKU!'s the grid
}

Sudoku::~Sudoku() //destructor
{
  for (int d = 0; d < size; d++)
    {
      delete [] grid[d];
    }
  delete [] grid;
}
//ALL CHECKS CALLED BY SUDOKUIZE
bool Sudoku::checkVert(int row, int column) //checks up and down for repeats
{
  for (int e=0; e<size; e++) //vertical
    {
      if(e==row)
	{}
      else if(grid[e][column]==grid[row][column])
	return false;
	
    }
  return true;
}
bool Sudoku::checkHorz(int row, int column) //checks left to right for repeats
{
  for (int f=0; f<size; f++) //horz
    {
      if(f==column)
	{}
      else if(grid[row][f]==grid[row][column])
	return false;
	
    }
  return true;
}
bool Sudoku::checkSq(int row, int column) //checks 3x3 square for repeats
{
  int storeRow = row/3;
  int storeCol = column/3;
  
  for (int g = storeRow * 3; g < (storeRow*3 + 3); g++)
    {
    for (int h = storeCol * 3; h < (storeCol*3 + 3); h++)
      {
	if (!(g == row && h == column))
	  {
	    if (grid[row][column] == grid[g][h])
	      {
	      return false;
	      }	
	  }
      }	
    }
  return true;
}
bool Sudoku::checkAll(int row, int column) //calls all of the checks together
{
  return (checkVert(row,column) && checkHorz(row,column) && checkSq(row,column));
}

bool Sudoku::sudokuize(int x, int y)
{
  //base
  if (y>=size)
    {
      x++;
      y=0;
    }
  //base
  if (x>=size)
    return true;

  /*h helps keep the random int in scope. So if rand gives num=3, it will
    iterate from 3 to 9, reset back to 0, and then only try up to number
    2 before kickback.  */
  num = rand() % 9+1; //seeds random num
  storeNum=num; //stores original num so it doesn't check itself twice
  for(int h=0;h<8;h++) 
    {
      num++;
      if (num>9)
	num=1;
      if((grid[x][y]=num) && checkAll(x,y) && sudokuize(x,y+1)) //recusion here
	{
	  return true; 
	}
      grid[x][y]=0;	  
    }
  return false;
}


void Sudoku::print() //prints sudoku
{
  for (int i=0; i<size;i++)
    {
      cout << "-------------------------------------" << endl;
      cout << "| ";
      for (int z=0; z<size;z++)
	{
	  cout << grid[i][z] << " | ";
	}
      cout << endl;
    }
  cout << "-------------------------------------" << endl;
}

     
     
     








