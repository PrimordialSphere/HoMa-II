#pragma once
#ifndef C_DGLSolver_h
#include <iomanip>
#include <iostream>
#include <cmath>
#include "CMyVektor.h"

class C_DGLSolver
{
public:
	C_DGLSolver();
	C_DGLSolver(CMyVektor(*f_DGL_System)(CMyVektor y, double x));
	C_DGLSolver(double(*f_DGL_nterOrdnung)(CMyVektor y, double x));
	~C_DGLSolver();
	CMyVektor euler(CMyVektor y, double xStart, double XEnd, double h);
	CMyVektor heun(CMyVektor y, double xStart, double XEnd, double h);


private:
	CMyVektor(*fDglSystemZeiger)(CMyVektor y, double x);
	double(*fDglNterOrdnungZeiger)(CMyVektor y, double x);
	bool isDGLSystem;
	CMyVektor ableitungen(CMyVektor y, double x);
};

#endif // !C_DGLSolver_h
