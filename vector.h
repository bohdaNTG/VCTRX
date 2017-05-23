#ifndef __VECTOR_H_INCLUDED__
#define __VECTOR_H_INCLUDED__

#include <iostream>
#include "board.h"
#include <cmath>
#include "menu.h"
#define PI 3.14159265

class Vector {
	int dim;
	double *vect;
public:
	Vector(int);
	~Vector();
	double getValue(int);
	void setValue(int,double);
	void inpVector(int,int);
	void outpVector(int,int);
	
	Vector* operator+(Vector &vect2);
    Vector* operator-(Vector &vect2);
    double operator*(Vector &vect2);
    
};

void addVector();
void subVector();
void scalarProd();
void angle();
void projection();
void vectProd(); 

#endif
