#include <iostream>
#include "matrix.h"
#include "board.h"
#include "vector.h"
#include <windows.h>

using namespace std;


int main(int argc, char** argv) {
	system("color F0");
	Board mainBoard(0,0,80,25);
	mainBoard.createBoard();
	
	int selection;

    do
    {
        mainBoard.clearBoard();
		mainBoard.print("\t\tMain menu",1);
        mainBoard.print("\tMatrix Operations: ",3);
        mainBoard.print("1.Matrix addition",4);
        mainBoard.print("2.Matrix substraction",5);
        mainBoard.print("3.Matrix multiplication",6);
        mainBoard.print("\tMatrix Analysis",8);
        mainBoard.print("4.Transpose matrix",9);
        mainBoard.print("5.Find determinant",10);
        mainBoard.print("6.Reversed matrix(2x2 only)",11);
       	mainBoard.print("\tVector operations:",13);
        mainBoard.print("7.Vector addition",14);
		mainBoard.print("8.Vector substraction",15);
		mainBoard.print("9.Scalar product",16);
		mainBoard.print("10.Vectorial product",17);
		mainBoard.print("11.Angle between",18);
		mainBoard.print("12.Projection",19);
		mainBoard.print("13.Exit",21);
		
       	mainBoard.print("Your selection: ",23);
        cin >> selection;
        
		switch (selection)
        {
            case 1:
               	addMatrix();
				break;
            case 2:
                subMatrix();
				break;
            case 3:
                multMatrix();
                break;

            case 4:
                transpMatrix();
				break;

            case 5:
            	determinant();
            	break;
            
			case 6:
                inverseMatrix();
				break;
			
			case 7:
                addVector();
				break;
				
			case 8:
                subVector();
				break;
			
			case 9:
                scalarProd();
				break;
				
			case 10:
                vectProd();
				break;
			
			case 11:
                angle();
				break;
				
			case 12:
                projection();
				break;
			
            default: cout <<selection << "is not a valid menu item.\n";

                cout << endl;
        }

    }while (selection != 13 );

	
	
	set(0,25);
	return 0;
}


