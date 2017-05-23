#ifndef __MATRIX_H_INCLUDED__
#define __MATRIX_H_INCLUDED__

#include <iostream>
#include "board.h"
#include <cmath>
#include "menu.h"
#include <string>

using namespace std;

class Matrix {   
	int rows, cols;
    double **matr;
    double sum(Matrix * matr1, Matrix * matr2, int i, int j);
public:
    Matrix(int, int);
    ~Matrix();
    int getRows();
    int getCols();
    double** getArray();
	double getValue(int,int);
	void setValue(int,int,double);
    void inpMatrix(int,int);
    void outpMatrix(int,int);

    double operator()(int,int);

    void operator()(int,int,double);

    Matrix* operator+(Matrix &matr2);
    Matrix* operator-(Matrix &matr2);
    Matrix* operator*(Matrix &matr2);
    Matrix* transpMatrix();
    Matrix* invrsMatrix();
    Matrix* subMatr(int,int,int);
    
};

void addMatrix();
void multMatrix();
void subMatrix();
void transpMatrix();
void inverseMatrix();
void determinant();
double det(Matrix*,int);

#endif
