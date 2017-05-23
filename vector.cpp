#include <iostream>
#include "board.h"
#include <cmath>
#include "vector.h"
#include "menu.h"
#define PI 3.14159265

Vector::Vector(int _dim) {
	dim=_dim;
    vect = new double[_dim];
}

Vector::~Vector() {
        delete [] vect;
}

double Vector::getValue(int x) {
    return vect[x];
}

void Vector::setValue(int x, double value) {
    vect[x] = value;
}

void Vector::outpVector(int x,int y) {
	set(x,y);
	cout<<"(";
	for( int i_c=x+1,i=0;i<dim;i_c+=9,i++) {
		set(i_c,y);
		cout<<setw(8);
		cout<<getValue(i);
		if(i!=dim-1) cout<<",";
	}
	set(x+9*dim,y);
	cout<<")"<<endl;
}

void Vector::inpVector(int x,int y) {
	double val;
	set(x,y);
	cout<<"(";
	for( int i_c=x+1,i=0;i<dim;i_c+=9,i++) {
			setValue(i,input(i_c,y));
	}
	set(x+9*dim,y);
	cout<<")"<<endl;
}

Vector *Vector::operator+(Vector &vect2) {
    Vector *newVector = new Vector(dim);    
    for(int i=0;i<dim;i++) {
    	double value = vect[i] + vect2.getValue(i);
    	newVector->setValue(i, value);
	}    
	return newVector;
}

Vector *Vector::operator-(Vector &vect2) {
    Vector *newVector = new Vector(dim);    
    for(int i=0;i<dim;i++) {
    	double value = vect[i] - vect2.getValue(i);
    	newVector->setValue(i, value);
	}    
	return newVector;
}

double Vector::operator*(Vector &vect2) {
	Vector *newVector = new Vector(dim);
	double value = 0;
	for(int i=0;i<dim;i++) {
		value += vect[i]*vect2.getValue(i);
	}
	return value;
}

void addVector() {
	int _dim,ask,fl;
	double val;
	Board mainBoard(0,0,83,38);
	
	do {
		mainBoard.clearBoard();
		mainBoard.print("Enter dimension: ",1);
		_dim=strictinput(18,1);
		Vector vctr1(_dim);
		Vector vctr2(_dim);
		mainBoard.print("Enter vector A: ",3);
		vctr1.inpVector(1,4);
		vctr1.outpVector(1,4);
		mainBoard.print("Enter vector B: ",6);
		vctr2.inpVector(1,7);
		vctr2.outpVector(1,7);
		Vector *vctr3 = vctr1+vctr2;
		mainBoard.print("A + B: ",9);
		vctr3->outpVector(1,10);
		int i, ch, exitkey = 1, dmenu[2] = { 1,1 },curs=0;
		tipmenu pmenu[2];
		pmenu[0].pm = "Try again.";
		pmenu[1].pm = "Back to main menu";
		
		pmenu[0].x = 1;
		pmenu[0].y = 12;
		pmenu[1].x = 1;
		pmenu[1].y = 13;
		
		xeroksmenu(pmenu,dmenu,2,curs);
		do {
			ch = _getch();
			if (ch == 224)
				curs=menu(pmenu, dmenu, 2, curs);
			if(ch == 13) {
				switch (curs) {
            		case 0:
						exitkey=0;
						break;
            		case 1:
                		fl=0;
						exitkey=0;
						mainBoard.clearBoard();
						break;
				}
			}
		} while (exitkey);
	}while(fl);	
}

void subVector() {
	int _dim,ask,fl;
	double val;
	Board mainBoard(0,0,83,38);
	
	do {
		mainBoard.clearBoard();
		mainBoard.print("Enter dimension: ",1);
		_dim=strictinput(18,1);
		Vector vctr1(_dim);
		Vector vctr2(_dim);
		mainBoard.print("Enter vector A: ",3);
		vctr1.inpVector(1,4);
		vctr1.outpVector(1,4);
		mainBoard.print("Enter vector B: ",6);
		vctr2.inpVector(1,7);
		vctr2.outpVector(1,7);
		Vector *vctr3 = vctr1-vctr2;
		mainBoard.print("A - B: ",9);
		vctr3->outpVector(1,10);
		int i, ch, exitkey = 1, dmenu[2] = { 1,1 },curs=0;
		tipmenu pmenu[2];
		pmenu[0].pm = "Try again.";
		pmenu[1].pm = "Back to main menu";
		
		pmenu[0].x = 1;
		pmenu[0].y = 11;
		pmenu[1].x = 1;
		pmenu[1].y = 12;
		
		xeroksmenu(pmenu,dmenu,2,curs);
		do {
			ch = _getch();
			if (ch == 224)
				curs=menu(pmenu, dmenu, 2, curs);
			if(ch == 13) {
				switch (curs) {
            		case 0:
						exitkey=0;
						break;
            		case 1:
                		fl=0;
						exitkey=0;
						mainBoard.clearBoard();
						break;
				}
			}
		} while (exitkey);
	}while(fl);	
}

void scalarProd() {
	int _dim,ask,fl;
	double val;
	Board mainBoard(0,0,83,38);
	
	do {
		mainBoard.clearBoard();
		mainBoard.print("Enter dimension: ",1);
		_dim=strictinput(18,1);
		Vector vctr1(_dim);
		Vector vctr2(_dim);
		mainBoard.print("Enter vector A: ",3);
		vctr1.inpVector(1,4);
		vctr1.outpVector(1,4);
		mainBoard.print("Enter vector B: ",6);
		vctr2.inpVector(1,7);
		vctr2.outpVector(1,7);
		mainBoard.print("Result: ",9);
		set(9,9);
		cout<<vctr1*vctr2;
		int i, ch, exitkey = 1, dmenu[2] = { 1,1 },curs=0;
		tipmenu pmenu[2];
		pmenu[0].pm = "Try again.";
		pmenu[1].pm = "Back to main menu";
		
		pmenu[0].x = 1;
		pmenu[0].y = 11;
		pmenu[1].x = 1;
		pmenu[1].y = 12;
		
		xeroksmenu(pmenu,dmenu,2,curs);
		do {
			ch = _getch();
			if (ch == 224)
				curs=menu(pmenu, dmenu, 2, curs);
			if(ch == 13) {
				switch (curs) {
            		case 0:
						exitkey=0;
						break;
            		case 1:
                		fl=0;
						exitkey=0;
						mainBoard.clearBoard();
						break;
				}
			}
		} while (exitkey);
	}while(fl);	
}

void angle() {
	int _dim,ask,fl=1;
	double dot,lenSq1,lenSq2,angle;
	Board mainBoard(0,0,83,38);
	
	do {
		mainBoard.clearBoard();
		mainBoard.print("Enter dimension: ",1);
		_dim=strictinput(18,1);
		while(_dim != 2 && _dim !=3) {
			for(int i=0;i<55;i++) {
				set(18+i,1);
				cout<<" ";
			}
			_dim=strictinput(18,1);
		}
		Vector vctr1(_dim);
		Vector vctr2(_dim);
		mainBoard.print("Enter vector A: ",3);
		vctr1.inpVector(1,4);
		vctr1.outpVector(1,4);
		mainBoard.print("Enter vector B: ",6);
		vctr2.inpVector(1,7);
		vctr2.outpVector(1,7);
		
		
		
		if(_dim==2) {
			dot = vctr1*vctr2;
			lenSq1 = vctr1.getValue(0)*vctr1.getValue(0) + vctr1.getValue(1)*vctr1.getValue(1);
			lenSq2 = vctr2.getValue(0)*vctr2.getValue(0) + vctr2.getValue(1)*vctr2.getValue(1);
			angle = acos(dot/sqrt(lenSq1 * lenSq2));
			mainBoard.print("Angle between vectors: ",9);
			set(24,9);
			cout<<angle * 180.0/PI;
		} 
		else if(_dim==3) {
			dot = vctr1*vctr2;
			lenSq1 = vctr1.getValue(0)*vctr1.getValue(0) + vctr1.getValue(1)*vctr1.getValue(1) + vctr1.getValue(2)*vctr1.getValue(2);
			lenSq2 = vctr2.getValue(0)*vctr2.getValue(0) + vctr2.getValue(1)*vctr2.getValue(1) + vctr2.getValue(2)*vctr2.getValue(2);
			angle = acos(dot/sqrt(lenSq1 * lenSq2));
			mainBoard.print("Angle between vectors: ",9);
			set(24,9);
			cout<<angle * 180.0/PI;
		}
		else {
			mainBoard.print("Wrong dimension! ",9);
		} 
		
		int i, ch, exitkey = 1, dmenu[2] = { 1,1 },curs=0;
		tipmenu pmenu[2];
		pmenu[0].pm = "Try again.";
		pmenu[1].pm = "Back to main menu";
		
		pmenu[0].x = 1;
		pmenu[0].y = 11;
		pmenu[1].x = 1;
		pmenu[1].y = 12;
		
		xeroksmenu(pmenu,dmenu,2,curs);
		do {
			ch = _getch();
			if (ch == 224)
				curs=menu(pmenu, dmenu, 2, curs);
			if(ch == 13) {
				switch (curs) {
            		case 0:
						exitkey=0;
						break;
            		case 1:
                		fl=0;
						exitkey=0;
						mainBoard.clearBoard();
						break;
				}
			}
		} while (exitkey);
	}while(fl);	
}

void projection() {
	int _dim,ask,fl=1;
	double top,bott,result,lenSq1,lenSq2;
	Board mainBoard(0,0,83,38);
	
	do {
		mainBoard.clearBoard();
		mainBoard.print("Enter dimension: ",1);
		_dim=strictinput(18,1);
		while(_dim != 2 && _dim !=3) {
			for(int i=0;i<55;i++) {
				set(18+i,1);
				cout<<" ";
			}
			_dim=strictinput(18,1);
		}
		Vector vctr1(_dim);
		Vector vctr2(_dim);
		mainBoard.print("Enter vector A: ",3);
		vctr1.inpVector(1,4);
		vctr1.outpVector(1,4);
		mainBoard.print("Enter vector B: ",6);
		vctr2.inpVector(1,7);
		vctr2.outpVector(1,7);
		
		top = vctr1*vctr2;
		
		for(int i=0;i<_dim;i++) {
			lenSq2 +=vctr2.getValue(i)*vctr2.getValue(i);
		}
		
		result = (vctr1*vctr2)/sqrt(lenSq2);
		mainBoard.print("Projection: ",9);
		set(24,9);
		cout<<result;
		
		int i, ch, exitkey = 1, dmenu[2] = { 1,1 },curs=0;
		tipmenu pmenu[2];
		pmenu[0].pm = "Try again.";
		pmenu[1].pm = "Back to main menu";
		
		pmenu[0].x = 1;
		pmenu[0].y = 11;
		pmenu[1].x = 1;
		pmenu[1].y = 12;
		
		xeroksmenu(pmenu,dmenu,2,curs);
		do {
			ch = _getch();
			if (ch == 224)
				curs=menu(pmenu, dmenu, 2, curs);
			if(ch == 13) {
				switch (curs) {
            		case 0:
						exitkey=0;
						break;
            		case 1:
                		fl=0;
						exitkey=0;
						mainBoard.clearBoard();
						break;
				}
			}
		} while (exitkey);
	}while(fl);	
}

void vectProd() {
	int ask,fl=1;
	Board mainBoard(0,0,83,38);
	
	do {
		mainBoard.clearBoard();
		Vector vctr1(3);
		Vector vctr2(3);
		Vector vctr3(3);
		mainBoard.print("Enter vector A: ",1);
		vctr1.inpVector(1,2);
		vctr1.outpVector(1,2);
		mainBoard.print("Enter vector B: ",3);
		vctr2.inpVector(1,4);
		vctr2.outpVector(1,4);
		
		vctr3.setValue(0,vctr1.getValue(1)*vctr2.getValue(2) - vctr1.getValue(2)*vctr2.getValue(1));
		vctr3.setValue(1,vctr1.getValue(2)*vctr2.getValue(0) - vctr1.getValue(0)*vctr2.getValue(2));
		vctr3.setValue(2,vctr1.getValue(0)*vctr2.getValue(1) - vctr1.getValue(1)*vctr2.getValue(0));
		//aybz - azby; azbx - axbz; axby - aybx
		
		mainBoard.print("Vectorial product: ",6);
		vctr3.outpVector(1,7);
		
		int i, ch, exitkey = 1, dmenu[2] = { 1,1 },curs=0;
		tipmenu pmenu[2];
		pmenu[0].pm = "Try again.";
		pmenu[1].pm = "Back to main menu";
		
		pmenu[0].x = 1;
		pmenu[0].y = 9;
		pmenu[1].x = 1;
		pmenu[1].y = 10;
		
		xeroksmenu(pmenu,dmenu,2,curs);
		do {
			ch = _getch();
			if (ch == 224)
				curs=menu(pmenu, dmenu, 2, curs);
			if(ch == 13) {
				switch (curs) {
            		case 0:
						exitkey=0;
						break;
            		case 1:
                		fl=0;
						exitkey=0;
						mainBoard.clearBoard();
						break;
				}
			}
		} while (exitkey);
	}while(fl);	
}
