#include <iostream>
#include "board.h"
#include "matrix.h"
#include <cmath>
#include "menu.h"
#include <string>

using namespace std;

Matrix::Matrix(int _rows, int _cols) {
    rows = _rows;
    cols = _cols;

    matr = new double *[_rows];
    for (int i = 0; i < _rows; i++) {
        matr[i] = new double [_cols];
    }

}

Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete [] matr[i];
    }
    delete [] matr;
}

int Matrix::getRows() {
    return rows;
}

int Matrix::getCols() {
    return cols;
}

double Matrix::getValue(int x, int y) {
    return matr[x][y];
}

void Matrix::setValue(int x, int y, double value) {
    matr[x][y] = value;
}

double** Matrix::getArray() {
    return matr;
}

void Matrix::inpMatrix(int x,int y) {
	double val=0;
	
	//creating angles
	set(x,y);
	cout<<(char)218;
	set(x,rows+y+1);
	cout<<(char)192;
	//left line
	set(x,y+1);
	for( int i=0;i<rows+1;i++) {
		cout<<(char)179;
		set(x,y+1+i);
	}
	
	for( int i_c=y+1,i=0;i<rows;i_c++,i++)
		for( int j_c=x+1,j=0;j<cols;j_c+=9,j++) {
			double val = input(j_c,i_c);
			setValue(i,j,val);
		}
		
	set(9*cols+x,y);
	cout<<(char)191;
	set(9*cols+x,rows+y+1);
	cout<<(char)217;
	//right line
	set(9*cols+x,y+1);
	for( int i=0;i<rows+1;i++) {
		cout<<(char)179;
		set(9*cols+x,y+1+i);
	}
	cout<<endl;
	
} 

void Matrix::outpMatrix(int x,int y) {
	
	string strVal = "";
	string::size_type sz;
	char* cVal = new char [strVal.length()+1];
	
	//creating angles
	set(x,y);
	cout<<(char)218;
	set(x,rows+y+1);
	cout<<(char)192;
	//left line
	set(x,y+1);
	for( int i=0;i<rows+1;i++) {
		cout<<(char)179;
		set(x,y+1+i);
	}
	
	for( int i_c=y+1,i=0;i<rows;i_c++,i++)
		for( int j_c=x+1,j=0;j<cols;j_c+=9,j++) {
			set(j_c,i_c);
			cout<<getValue(i,j);
		}
		
	set(9*cols+x,y); //8*cols+5+x
	cout<<(char)191;
	set(9*cols+x,rows+y+1);
	cout<<(char)217;
	//right line
	set(9*cols+x,y+1);
	for( int i=0;i<rows+1;i++) {
		cout<<(char)179;
		set(9*cols+x,y+1+i);
	}
	cout<<endl;
}

Matrix *Matrix::operator+(Matrix &matr2) {
	Matrix *newMatr = new Matrix(rows, cols);
    	for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) {
                double value = matr[i][j] + matr2.getValue(i, j);
                newMatr-> setValue(i, j, value);
            }
    return newMatr;
}

Matrix *Matrix::operator-(Matrix &matr2) {
    Matrix *newMatr = new Matrix(rows, cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            double value = matr[i][j] - matr2.getValue(i, j);
            newMatr-> setValue(i, j, value);
        }
    return newMatr;
}


Matrix* Matrix::operator*(Matrix &matr2) {
    Matrix *newMatr = new Matrix(rows, matr2.getCols());
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < matr2.getCols(); j++) {
            newMatr->setValue(i, j, sum(this, &matr2, i, j));
    }    
    return newMatr;
}

double Matrix::operator()(int x, int y) {
        return matr[x][y];
	}
	
void Matrix::operator()(int x, int y, double val) {
        matr[x][y] = val;
    }

Matrix* Matrix::transpMatrix() {
	Matrix *newMatr = new Matrix(cols, rows);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			newMatr->setValue(j,i, matr[i][j]);
		}	
	return newMatr;
}

Matrix* Matrix::invrsMatrix() {
	Matrix *newMatr = new Matrix(cols, rows);
	double det = matr[0][0]*matr[1][1] - matr[0][1]*matr[1][0];
	if(det) {
	double invDet = 1/det;
	newMatr->setValue(0,0,invDet*matr[1][1]);
	newMatr->setValue(0,1,-invDet*matr[0][1]);
	newMatr->setValue(1,0,-invDet*matr[1][0]);
	newMatr->setValue(1,1,invDet*matr[0][0]);
	return newMatr;
	}
	else {
		set(1,8);
		cout<<"Determinant of this one is 0, so there is no inverse matrix for it.";
		return this;
	}
}

double Matrix::sum(Matrix * matr1, Matrix * matr2, int i, int j) {
    int cols = matr1->getCols();
    double Sum = 0;

    for (int n = 0; n < cols; n++) {
        Sum += matr1->getValue(i, n) * matr2->getValue(n, j);
    }

    return Sum;
}

void addMatrix() {
	
	int _rows1,_cols1,_rows2,_cols2,ask,fl;
	double val;
	Board mainBoard(0,0,83,39);
	
	do {
		mainBoard.clearBoard();
		mainBoard.print("Input number of rows of first matrix: ",1);
		_rows1=strictinput(39,1);
    	mainBoard.print("Input number of columns of first matrix: ",2);
		_cols1 = strictinput(42,2);
		mainBoard.print("Input number of rows of second matrix: ",3);
		_rows2 = strictinput(40,3);
		mainBoard.print("Input number of columns of second matrix: ",4);
		_cols2 = strictinput(43,4);
		if(_rows1==_rows2 && _cols1==_cols2) {
			Matrix mtrx1(_rows1,_cols1);
			mtrx1.inpMatrix(1,5);
			Matrix mtrx2(_rows2,_cols2);
			mtrx2.inpMatrix(1,7+_rows1);
			mainBoard.clearBoard();
			Matrix *mtrx3 = mtrx1+mtrx2;
			mtrx1.outpMatrix(1,1);
			mtrx2.outpMatrix(1,_rows1+3);
			mainBoard.print(" Result: ", 5+_rows1+_rows2);
			mtrx3->outpMatrix(1,6+_rows1+_rows2);
		}
		else mainBoard.print("Matricies have different sizes and can't be added",6);
		
		int i, ch, exitkey = 1, dmenu[2] = { 1,1 },curs=0;
		Menu pmenu[2];
		pmenu[0].pm = "Repeat operation";
		pmenu[1].pm = "Back to main menu";
		
		pmenu[0].x = 33;
		pmenu[0].y = 9+_rows1+_rows2+_rows1;
		pmenu[1].x = 33;
		pmenu[1].y = 10+_rows1+_rows2+_rows1;
		
		Board askBoard(31,8+_rows1+_rows2+_rows1,51,11+_rows1+_rows2+_rows1);
		askBoard.createBoard();	
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

void subMatrix() {
	
	int _rows1,_cols1,_rows2,_cols2,ask,fl;
	double val;
	Board mainBoard(0,0,83,39);
	
	do {
		mainBoard.clearBoard();
		mainBoard.print("Input number of rows of first matrix: ",1);
		_rows1=strictinput(39,1);
    	mainBoard.print("Input number of columns of first matrix: ",2);
		_cols1=strictinput(42,2);
		mainBoard.print("Input number of rows of second matrix: ",3);
		_rows2=strictinput(40,3);
		mainBoard.print("Input number of columns of second matrix: ",4);
		_cols2=strictinput(43,4);
		if(_rows1==_rows2 && _cols1==_cols2) {
			Matrix mtrx1(_rows1,_cols1);
			mtrx1.inpMatrix(1,5);
			Matrix mtrx2(_rows2,_cols2);
			mtrx2.inpMatrix(1,7+_rows1);
			mainBoard.clearBoard();
			Matrix *mtrx3 = mtrx1-mtrx2;
			mtrx1.outpMatrix(1,1);
			mtrx2.outpMatrix(1,_rows1+3);
			mainBoard.print(" Result: ", 5+_rows1+_rows2);
			mtrx3->outpMatrix(1,6+_rows1+_rows2);
		}
		else mainBoard.print("Matricies have different sizes and can't be added",6);
	
		int i, ch, exitkey = 1, dmenu[2] = { 1,1 },curs=0;
		Menu pmenu[2];
		pmenu[0].pm = "Repeat operation";
		pmenu[1].pm = "Back to main menu";
		
		pmenu[0].x = 33;
		pmenu[0].y = 9+_rows1+_rows2+_rows1;
		pmenu[1].x = 33;
		pmenu[1].y = 10+_rows1+_rows2+_rows1;
		
		Board askBoard(31,8+_rows1+_rows2+_rows1,51,11+_rows1+_rows2+_rows1);
		askBoard.createBoard();	
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

void multMatrix() {
	int _rows1,_cols1,_rows2,_cols2,ask,fl;
	double val;
	Board mainBoard(0,0,83,39);
	do {
		mainBoard.clearBoard();
		mainBoard.print("Input number of rows of first matrix: ",1);
		_rows1=strictinput(39,1);
    	mainBoard.print("Input number of columns of first matrix: ",2);
		_cols1=strictinput(42,2);
		mainBoard.print("Input number of rows of second matrix: ",3);
		_rows2=strictinput(40,3);
		mainBoard.print("Input number of columns of second matrix: ",4);
		_cols2=strictinput(43,4);
		if(_cols1==_rows2) {
			Matrix mtrx1(_rows1,_cols1);
			mtrx1.inpMatrix(1,5);
			Matrix mtrx2(_rows2,_cols2);
			mtrx2.inpMatrix(1,7+_rows1);
			mainBoard.clearBoard();
			Matrix *mtrx3 = mtrx1*mtrx2;
			mtrx1.outpMatrix(1,1);
			mtrx2.outpMatrix(1,_rows1+3);
			mainBoard.print(" Result: ", 5+_rows1+_rows2);
			mtrx3->outpMatrix(1,6+_rows1+_rows2);
		}
		else mainBoard.print("Number of columns of 1st matrix should be equal to number of rows of 2nd one!",6);
		
		int i, ch, exitkey = 1, dmenu[2] = { 1,1 },curs=0;
		Menu pmenu[2];
		pmenu[0].pm = "Repeat operation";
		pmenu[1].pm = "Back to main menu";
		
		pmenu[0].x = 33;
		pmenu[0].y = 9+_rows1+_rows2+_rows1;
		pmenu[1].x = 33;
		pmenu[1].y = 10+_rows1+_rows2+_rows1;
		
		Board askBoard(31,8+_rows1+_rows2+_rows1,51,11+_rows1+_rows2+_rows1);
		askBoard.createBoard();	
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
	
void transpMatrix() {
	
	int _rows,_cols,ask,fl;
	double val;
	Board mainBoard(0,0,83,39);
	
	
	do {
		mainBoard.clearBoard();
		mainBoard.print("Input number of rows: ",1);
		_rows=strictinput(23,1);
    	mainBoard.print("Input number of columns: ",2);
		_cols=strictinput(26,2);
		Matrix mtrx(_rows,_cols);
		mtrx.inpMatrix(1,3);
		Matrix *transpMtrx = mtrx.transpMatrix();
		mainBoard.print(" Transposed matrix: ", 5+_rows);
		transpMtrx->outpMatrix(1,6+_rows);
	
		int i, ch, exitkey = 1, dmenu[2] = { 1,1 },curs=0;
		Menu pmenu[2];
		pmenu[0].pm = "Repeat operation";
		pmenu[1].pm = "Back to main menu";
		
		pmenu[0].x = 33;
		pmenu[0].y = 9+_rows+_cols;
		pmenu[1].x = 33;
		pmenu[1].y = 10+_rows+_cols;
		
		Board askBoard(31,8+_rows+_cols,51,11+_rows+_cols);
		askBoard.createBoard();	
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

void inverseMatrix() {
	
	int _rows,_cols,ask,fl;
	double val;
	Board mainBoard(0,0,83,39);
	
	
	do {
		mainBoard.clearBoard();
		mainBoard.print("Enter your matrix: ",1);
		mainBoard.print("Notice, it is yet available just for 2x2 matrices.",2);
		Matrix mtrx(2,2);
		mtrx.inpMatrix(1,3);
		Matrix *inversedMtrx = mtrx.invrsMatrix();
		mainBoard.print("Inverse matrix: ", 7);
		inversedMtrx->outpMatrix(1,9);
		int i, ch, exitkey = 1, dmenu[2] = { 1,1 },curs=0;
		Menu pmenu[2];
		pmenu[0].pm = "Repeat operation";
		pmenu[1].pm = "Back to main menu";
		
		pmenu[0].x = 33;
		pmenu[0].y = 14;
		pmenu[1].x = 33;
		pmenu[1].y = 15;
		
		Board askBoard(31,13,51,16);
		askBoard.createBoard();	
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


Matrix* Matrix::subMatr(int order,int i,int j) {
	Matrix* subm = new Matrix(order-1,order-1);
	int p, q;				// Indexes for matrix
	int a = 0, b;		// Indexes for subm

	for(p = 0; p < order; p++) {
		if(p==i) continue;				//Skip ith row
			b = 0;

		for(q = 0; q< order; q++) {
				if(q==j) continue;		//Skip jth column
			subm->setValue(a,b++, matr[p][q]);
		}
		a++; //Increment row index
	}
	return subm;
}

double det(Matrix *mtrx,int order) {
	if(order == 1)
	return mtrx->getValue(0,0); //Return the element if the matrix is of order one

	double _det = 0;
	for(int i = 0; i < order; i++)
		_det += static_cast<double>(pow(-1.0,(int)i)) * mtrx->getValue(i,0) * det(mtrx->subMatr(order, i, 0), order - 1);
	return _det;
}

void determinant() {
	
	int order,ask,fl=1;
	double val;
	Board mainBoard(0,0,83,39);
	
	
	do {
		mainBoard.clearBoard();
		mainBoard.print("Enter order of matrix: ",1);
		order = strictinput(25,1);
		Matrix mtrx(order,order);
		mtrx.inpMatrix(1,2);
		double res = det(&mtrx,order);
		mainBoard.print("Determinant: ", order+5);
		cout<<res;
		int i, ch, exitkey = 1, dmenu[2] = { 1,1 },curs=0;
		Menu pmenu[2];
		pmenu[0].pm = "Repeat operation";
		pmenu[1].pm = "Back to main menu";
		
		pmenu[0].x = 33;
		pmenu[0].y = order + 7;
		pmenu[1].x = 33;
		pmenu[1].y = order + 8;
		
		Board askBoard(31,order + 6,51,order + 9);
		askBoard.createBoard();	
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


