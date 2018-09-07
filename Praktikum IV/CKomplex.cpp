#include "CKomplex.h"

CKomplex::CKomplex()
{
	real = 0;
	imag = 0;
}

CKomplex::CKomplex(double a, double b)
{
	real = a;
	imag = b;
}

CKomplex::CKomplex(double phi)
{
	real = cos(phi);
	imag = sin(phi);
}

CKomplex::CKomplex(const CKomplex & komplex)
{
	real = komplex.real;
	imag = komplex.imag;
}

double CKomplex::re()
{
	return real;
}

double CKomplex::im()
{
	return imag;
}

double CKomplex::abs()
{
	double betrag =(real*real)+(imag*imag);
	double result = sqrt(betrag);
	return result;
}

CKomplex & CKomplex::operator=(const CKomplex & komplex)
{
	real = komplex.real;
	imag = komplex.imag;
	return (*this);
}

CKomplex & CKomplex::operator+=(const CKomplex & komplex)
{
	real += komplex.real;
	imag += komplex.imag;
	return (*this);
}



CKomplex & CKomplex::operator*=(const CKomplex & komplex)
{
	double a = real;
	double b = imag;
	double c = komplex.real;
	double d = komplex.imag;

	real = (a * c) + (b * d * -1.0);
	imag = (b * c) + (a * d);
	return (*this);
}

CKomplex & CKomplex::operator*=(double a)
{
	real *= a;
	imag *= a;
	return (*this);
}

CKomplex CKomplex::operator+(const CKomplex & add)
{
	CKomplex result(*this);

	return result += add;

	
}

CKomplex CKomplex::operator*(const CKomplex & mult)
{
	CKomplex result(*this);

	return result *= mult;
}

CKomplex CKomplex::operator*(double multNonKomplex)
{
	CKomplex result(*this);

	return result *= multNonKomplex;
}

CKomplex::~CKomplex()
{
}

