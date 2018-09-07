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
	return vektor[komponente];
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



CMyVektor & CMyVektor::operator+(const CMyVektor & CMyVektorAdd)
{
	if (dimension != CMyVektorAdd.dimension) { cout << "Die Dimensionen sind ungleich. Addition nicht möglich!" << endl;  return *this; }
	for (int i = 0; i < dimension; i++)
	{
		vektor[i] = vektor[i]+ CMyVektorAdd.vektor[i];
	}
	return *this;
}

CMyVektor & CMyVektor::operator+(const CMyVektor * CMyVektorAdd)
{
	if (dimension != CMyVektorAdd->dimension) { cout << "Die Dimensionen sind ungleich. Addition nicht möglich!" << endl;  return *this; }
	for (int i = 0; i < dimension; i++)
	{
		vektor[i] = vektor[i] + CMyVektorAdd->vektor[i];
	}
	return *this;
}

CMyVektor & CMyVektor::operator*(const double CMyVektorMult)
{
	
	for (int i = 0; i < dimension; i++)
	{
		vektor[i] = vektor[i] * CMyVektorMult;
	}
	return *this;

}

CMyVektor & CMyVektor::operator=(const CMyVektor & CMyVektorCopy)
{
	for (int i = 0; i < dimension; i++)
	{
		vektor[i] = CMyVektorCopy.vektor[i];
	}

	return *this;
}

CMyVektor & CMyVektor::operator=(const CMyVektor * CMyVektorCopy)
{
	for (int i = 0; i < dimension; i++)
	{
		vektor[i] = CMyVektorCopy->vektor[i];
	}
	return *this;
}





void CMyVektor::set(int komponente, double value)
{
	vektor[komponente] = value;
}
