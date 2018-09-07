#include "CMyVektor.h"


CMyVektor::CMyVektor(int key)
{
	dimension = key;
	vektor = new double[dimension];
}

CMyVektor::~CMyVektor()
{
}

double CMyVektor::get(int komponente)
{
	return vektor[komponente-1];
}

void CMyVektor::set(int komponente, double value)
{
	vektor[komponente - 1] = value;
}

double CMyVektor::getLength(void)
{
	double result = 0;
	
	for (int i=0; i < dimension; i++) {
		result = result + (vektor[i] * vektor[i]);
	}
	result = sqrt(result);
	return result;
}

int CMyVektor::getDimension(void)
{
	return dimension;
}

CMyVektor & operator+(CMyVektor &a, CMyVektor &b)
{
	CMyVektor result(a.getDimension());
	if (a.getDimension() != b.getDimension()) { cout << "Die Dimensionen sind ungleich. Addition nicht möglich!" << endl;  return a; }
	for (int i = 1; i <= result.getDimension(); i++)
	{
		result.set(i, a.get(i) + b.get(i));
	}
	return result;
}

CMyVektor & operator*(double &lambda, CMyVektor &a)
{
	CMyVektor result(a.getDimension());
	
	for (int i = 1; i <= a.getDimension(); i++)
	{
		result.set(i, a.get(i) * lambda);
	}
	return result;
}

CMyVektor & CMyVektor::operator=( CMyVektor b) {
	for (int i = 1; i <= this->getDimension(); i++)
	{
		this->set(i, b.get(i));
	}
	return *this;
}