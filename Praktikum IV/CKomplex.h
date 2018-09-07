#ifndef CKomplex_h
#define CKomplex_h
#define _USE_MATH_DEFINES
#include <math.h>

class CKomplex
{
public:
	CKomplex();
	CKomplex(double a, double b);
	CKomplex(double phi);
	CKomplex(const CKomplex & komplex);
	~CKomplex();

	double re();
	double im();
	double abs();

	CKomplex & operator=(const CKomplex & komplex);
	CKomplex & operator += (const CKomplex & komplex);
	CKomplex & operator *= (const CKomplex & komplex);
	CKomplex & operator *= (double a);

	CKomplex operator + (const CKomplex & add);
	CKomplex operator * (const CKomplex & mult);
	CKomplex operator* (double multNonKomplex);

private:
	double real;
	double imag;
};



#endif // !CKomplex_h

