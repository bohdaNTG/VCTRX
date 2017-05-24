#include <iostream>
#include "matrix.h"
#include "board.h"
#include "vector.h"
#include <windows.h>
#include "menu.h"

using namespace std;


int main(int argc, char** argv) {
	
	HWND console = GetConsoleWindow();
  	RECT ConsoleRect;
  	GetWindowRect(console, &ConsoleRect); 
   	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 910, 683, TRUE);


	Board mainBoard(0,0,83,39); 
	Board helpBoard(84,0,108,39);
	Board menuBoard(24,7,58,32);
	helpBoard.createBoard();
	mainBoard.createBoard();
	
	string line;
  	int count = 1;
	ifstream myfile("help.txt");
    while(getline(myfile,line) ) {
   		helpBoard.print(line, count);
		count++;
   	}
    myfile.close();
	
	int i, ch, exitkey = 1, dmenu[18] = { 0,0,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1 },curs=0;
	Menu pmenu[18];
	pmenu[0].pm = "\t\t\t\t     Main Menu";
	pmenu[1].pm = "\t\t\t   Matrix Operations:";
	pmenu[2].pm = "Matrix addition";
	pmenu[3].pm = "Matrix substraction";
	pmenu[4].pm = "Matrix multiplication";
	pmenu[5].pm = "\t\t\t   Matrix Analysis:";
	pmenu[6].pm = "Transpose matrix";
	pmenu[7].pm = "Determinant";
	pmenu[8].pm = "Inverse matrix";
	pmenu[9].pm = "\t\t\t   Vector Operations:";
	pmenu[10].pm = "Vector addition";
	pmenu[11].pm = "Vector substraction";
	pmenu[12].pm = "Scalar product";
	pmenu[13].pm = "Vectorial product";
	pmenu[14].pm = "Angle between vectors";
	pmenu[15].pm = "Projection";
	pmenu[16].pm = "      ABOUT";
	pmenu[17].pm = "      EXIT";
	
	pmenu[0].x = 1;
	pmenu[0].y = 9;
	
	pmenu[1].x = 1;
	pmenu[1].y = 11;
	
	pmenu[5].x = 1;
	pmenu[5].y = 16;
	
	pmenu[9].x = 1;
	pmenu[9].y = 21;
	
	for (i = 2; i < 5; i++) {
		pmenu[i].x = 33;
		pmenu[i].y = i+10;
	}
	for (i = 6; i < 9; i++) {
		pmenu[i].x = 33;
		pmenu[i].y = i+11;
	}
	for (i = 10; i < 16; i++) {
		pmenu[i].x = 33;
		pmenu[i].y = i+12;
	}
	for (i = 16; i < 18; i++) {
		pmenu[i].x = 33;
		pmenu[i].y = i+13;
	}	
	
	
	xeroksmenu(pmenu,dmenu,18,curs);
	menuBoard.createBoard();
	
	do
	{
		ch = _getch();
		if (ch == 224)
			curs=menu(pmenu, dmenu, 18, curs);
		if(ch == 13) {
			switch (curs) {
            	case 2:
               		addMatrix();
					break;
            	case 3:
                	subMatrix();
					break;
            	case 4:
                	multMatrix();
                	break;
            	case 6:
                	transpMatrix();
					break;

            	case 7:
            		determinant();
            		break;
            
				case 8:
                	inverseMatrix();
					break;
			
				case 10:
                	addVector();
					break;
				
				case 11:
                	subVector();
					break;
			
				case 12:
                	scalarProd();
					break;
				
				case 13:
                	vectProd();
					break;
			
				case 14:
                	angle();
					break;
				
				case 15:
                	projection();
					break;
				case 16:
                	about();
					break;
				case 17:
                	return 0;
        	}
		}
	xeroksmenu(pmenu,dmenu,18,curs);
	menuBoard.createBoard();	
	} while (exitkey);
	
	return 0;
}


