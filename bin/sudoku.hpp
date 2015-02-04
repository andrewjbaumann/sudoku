/******************************************************************************
Title : sudoku.hpp
Author : Andrew Baumann
Created on : Feb 23 2014
Description : The header for a program that fills out a sudoku grid
Build with : g++ sudokumain.cpp sudoku.cpp
Special Thanks : Zablan, Alvin. Tung, Justin. Wu, Danny. Vora, Aarsh.
Zheng, Tony. Shterenberg, Tereza. Brizan, David-Guy (in no order).
Used mahiya's code @ http://www.cplusplus.com/forum/beginner/76616/ 
for advice on the 3x3 grid checker. 
******************************************************************************/
#ifndef SUDOKU_H
#define SUDOKU_H
#include <iostream>
#include <string> 
#include <stdlib.h>     
#include <time.h>   

using namespace std;
class Sudoku
{
private:
  int size;
  int ** grid;
  int num;
  int storeNum;

  bool checkVert(int row, int column);
  bool checkHorz(int row, int column);
  bool checkSq(int row, int column);
  bool checkAll(int row, int column);
  bool sudokuize(int x,int y);

public:
  Sudoku();

  ~Sudoku();

  void print();


};

#endif
