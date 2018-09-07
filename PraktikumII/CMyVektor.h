#ifndef CMyVektor_h
#define CMyVektor_h
#include <math.h>
#include<iostream>
using namespace std;


class CMyVektor
{
private:
	int dimension;
	double * vektor;

public:
	CMyVektor(int key);
	~CMyVektor();
	void set(int komponente, double value);
	double get(int komponente);
	double getLength(void);
	int getDimension(void);
	CMyVektor& operator + (const CMyVektor & CMyVektorAdd);
	CMyVektor& operator + (const CMyVektor * CMyVektorAdd);
	CMyVektor& operator * (const double CMyVektorMult);
	CMyVektor& operator = (const CMyVektor & CMyVektorCopy);
	CMyVektor& operator = (const CMyVektor * CMyVektorCopy);



};

#endif // !CMyVektor_h

