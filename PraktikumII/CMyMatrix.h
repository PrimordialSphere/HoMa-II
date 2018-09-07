#pragma once
#ifndef CMyMatrix_h
#define CMyMatrix_h
#include <iomanip>
#include <iostream>
#include <cmath>
#include "CMyVektor.h"


class CMyMatrix
{
public:
	CMyMatrix(int zeile, int spalte);
	~CMyMatrix();
	void printOut(void);
	void set(int zeile, int spalte, double value);
	double get(int zeile, int spalte);
	CMyMatrix inverse(void);
	int getZeilen(void);
	int getSpalten(void);
	int getLimit(void);
	

private:
	int zeilen;
	int spalten;
	int limit;
	double * matrix;
};

CMyVektor operator*(CMyMatrix A, CMyVektor x);


#endif // !CMyMatrix_h
