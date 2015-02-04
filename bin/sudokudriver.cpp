/******************************************************************************
Title : sudokudriver.cpp
Author : Andrew Baumann
Created on : Feb 23 2014
Description : The driver for a program that creates a perfect sudoku grid.
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
int main()
{
  Sudoku * sudoku = new Sudoku;
  sudoku->print(); 
 delete sudoku;

 return 0;
}
