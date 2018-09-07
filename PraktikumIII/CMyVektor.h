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
	CMyVektor  & operator= (CMyVektor b);



};


CMyVektor & operator+ (CMyVektor & a, CMyVektor &b);
CMyVektor  & operator* (double &lambda, CMyVektor &a);

#endif // !CMyVektor_h

