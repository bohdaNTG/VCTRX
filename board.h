#ifndef __BOARD_H_INCLUDED__
#define __BOARD_H_INCLUDED__

#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

double input(int,int);
int strictinput(int,int);
void set(int,int);
void about();

class Board {
	int x1,y1,x2,y2;
public:	
	Board( int, int, int, int);
	void createBoard();
	void clearBoard();
	void print(string,int);
};
#endif
