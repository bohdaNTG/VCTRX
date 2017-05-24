#include <iostream>
#include "board.h"
#include <windows.h>
#include <string>
#include <fstream>

using namespace std;

Board::Board( int x_1, int y_1, int x_2, int y_2) {
			x1=x_1;
			x2=x_2;
			y1=y_1;
			y2=y_2;
	}

void Board::createBoard() {
	//creating angles
	set(x1,y1);
	cout<<(char)201;
	set(x2,y1);
	cout<<(char)187;
	set(x2,y2);
	cout<<(char)188;
	set(x1,y2);
	cout<<(char)200;
	//left line
	set(x1,y1+1);
	for( int i=0;i<y2-y1;i++) {
		cout<<(char)186;
		set(x1,y1+1+i);
	}
	//right line
	set(x2,y1+1);
	for( int i=0;i<y2-y1;i++) {
		cout<<(char)186;
		set(x2,y1+1+i);
	}
	//top line
	set(x1+1,y1);
	for(int i=0;i<x2-x1-1;i++) {
		cout<<(char)205;
	}
	//bot line
	set(x1+1,y2);
	for(int i=0;i<x2-x1-1;i++) {
		cout<<(char)205;
	}			
}

void Board::clearBoard() {
	set(x1+1,y1+1);
	for( int i=0;i<y2-y1;i++) {
		for( int j=0;j<x2-x1-1;j++) {
			cout<<" ";
		}
		set(x1+1,y1+i+1);
	}
}

//print at chosen line of the board
void Board::print(string text,int lvl) {
	set(x1+1,y1+lvl);
	cout<<text;
}

void set( int x,  int y) {
	HANDLE hConsole;
	COORD cursorLoc;
	std::cout.flush();
	cursorLoc.X = x;
	cursorLoc.Y = y;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, cursorLoc);
}

double input(int x,int y) {
	string strVal;
	double val;
	string::size_type sz;
	int fl = 1,state = 0,count=0;  
	
	char* cVal = new char [strVal.length()+1];
	
	while(fl) {
		strVal.clear();
		set(x,y);
		getline(cin,strVal);
		strcpy(cVal, strVal.c_str());
		
		for(int i = 0;i<strlen(cVal)+1;i++) {	
			if(cVal[i] != '-' && cVal[i] != '.' && cVal[i] != '0' && cVal[i] != '\0' && cVal[i] != '1' && cVal[i] != '2' && cVal[i] != '3' && 
		   		cVal[i] != '4' && cVal[i] != '5' && cVal[i] != '6' && cVal[i] != '7' && cVal[i] != '8' && cVal[i] != '9') {
				state = 1;
				break;
			}
			if(cVal[i] == '.') count++;
			if(count>1) {
				state = 1;
				break;
			}
		}
		
		for(int i = 1;i<strlen(cVal)+1;i++) {	
			if(cVal[i] == '-') {
				state = 1;
				break;
			}
		}
		if(strVal.length()>7) state = 1;
		if(cVal[strlen(cVal)-1] == '.') state = 1;	
		
		if(state == 1) {
	   		for(int i=0;i+x<78;i++) {
				set(x+i,y);
				cout<<" ";	
			}
			state = 0;
			count = 0;
  		}
		else fl = 0;
	}
	
	if (!strVal.empty()) {
        val = stod(strVal, &sz);
	}
	else {
		set(x,y);
		cout<<"0";
		val = 0;
	}
 	return val;
}

int strictinput(int x,int y) {
	string strVal;
	int val;
	string::size_type sz;
	int fl = 1,state = 0;  
	
	char* cVal = new char [strVal.length()+1];
	
	while(fl) {
		strVal.clear();
		set(x,y);
		getline(cin,strVal);
		strcpy(cVal, strVal.c_str());
		
		for(int i = 0;i<strlen(cVal);i++) {	
			if(cVal[i] != '\0'&& cVal[i] != '1' && cVal[i] != '2' && cVal[i] != '3' && 
		   		cVal[i] != '4' && cVal[i] != '5' && cVal[i] != '6' && cVal[i] != '7' && cVal[i] != '8' && cVal[i] != '9') {
				state = 1;
			}
		}
		if(strVal.length()>1) state = 1;
		if (strVal.empty()) state = 1;
		if(state) {
	   		for(int i=0;i+x<78;i++) {
				set(x+i,y);
				cout<<" ";	
			}
			state = 0;
  		}
		else fl = 0;
	}
	
    val = stod(strVal, &sz);
 	
	return val;
}

void about() {
	Board mainBoard(0,0,83,39);
	mainBoard.clearBoard();
	Board aboutBoard(17,11,66,27);
	aboutBoard.createBoard();
	string line;
  	
	int i = 1;
	ifstream myfile("about.txt");
  	if (myfile.is_open()) {
    	while(getline(myfile,line) ) {
      		aboutBoard.print(line+"\n", i);
			i++;
    	}
    	myfile.close();
  	}
  	cin.get();
	mainBoard.clearBoard();
}
	


