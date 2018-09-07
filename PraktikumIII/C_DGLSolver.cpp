#include "C_DGLSolver.h"
using namespace std;

C_DGLSolver::C_DGLSolver()
{
}

C_DGLSolver::C_DGLSolver(CMyVektor(*f_DGL_System)(CMyVektor y, double x))
{
	isDGLSystem = true;
	fDglSystemZeiger = f_DGL_System;
}

C_DGLSolver::C_DGLSolver(double(*f_DGL_nterOrdnung)(CMyVektor y, double x))
{
	isDGLSystem = false;
	fDglNterOrdnungZeiger = f_DGL_nterOrdnung;
}

C_DGLSolver::~C_DGLSolver()
{
}

CMyVektor C_DGLSolver::euler(CMyVektor y, double xStart, double XEnd, double h)
{
	double schrittweite = (XEnd - xStart) / h;
	double endOfLoop = h;
	cout << "h = " << schrittweite << endl;
	double x = xStart;
	CMyVektor yCopy(y.getDimension());
	yCopy = y;
	int s = 0;



	CMyVektor yAbleitungWerte(y.getDimension());

	for (int mainLoop = 1; mainLoop <= endOfLoop; mainLoop++)
	{



		yAbleitungWerte = ableitungen(yCopy, x);

		cout << "Schritt " << s << ": " << endl;
		cout << "\t" << "x = " << x << endl;
		cout << "\t" << "y = ( ";
		for (int j = 1; j <= yCopy.getDimension(); j++)
		{
			cout << yCopy.get(j) << "; ";
		}
		cout << " )" << endl;

		cout << "\t" << "y' = ( ";
		for (int j = 1; j <= yAbleitungWerte.getDimension(); j++)
		{
			cout << yAbleitungWerte.get(j) << "; ";
		}
		cout << " )" << endl;

		cout << endl;




		for (int i = 1; i <= yCopy.getDimension(); i++)
		{
			yCopy.set(i, yCopy.get(i) + schrittweite * yAbleitungWerte.get(i));
		}


		x = x + schrittweite;
		s++;
		
			
		
	}

	cout << "Ende bei " << endl;
	cout << "\t" << "x = " << x << endl;
	cout << "\t" << "y = ( ";
	for (int j = 1; j <= yCopy.getDimension(); j++)
	{
		cout << yCopy.get(j) << "; ";
	}
	cout << " )" << endl;
	return yCopy;

	
		
	

	

}

CMyVektor C_DGLSolver::heun(CMyVektor y, double xStart, double XEnd, double h)
{
	h = (XEnd - xStart)/h;
	cout << "h = " << h << endl;
	double x = xStart;
	CMyVektor  yCopy(y.getDimension());
	CMyVektor yCopyTest(y.getDimension());
	yCopy = y;
	int s = 0;


	if (true)
	{
		CMyVektor yAbleitungWerte(y.getDimension());
		CMyVektor yAbleitungWerteTest(y.getDimension());
		CMyVektor fVonXmittlereSteigung(y.getDimension());

		while (true)
		{
			yAbleitungWerte = ableitungen(yCopy, x);

			cout << "Schritt " << s << ": " << endl;
			cout << "\t" << "x = " << x << endl;
			cout << "\t" << "y = ( ";
			for (int j = 1; j <= yCopy.getDimension(); j++)
			{
				cout << yCopy.get(j) << "; ";
			}
			cout << " )" << endl;

			cout << "\t" << "y'_orig = ( ";
			for (int j = 1; j <= yAbleitungWerte.getDimension(); j++)
			{
				cout << yAbleitungWerte.get(j) << "; ";
			}
			cout << " )" << endl;

			cout << endl;


			for (int i = 1; i <= yCopy.getDimension(); i++)
			{
				yCopyTest.set(i, yCopy.get(i) + h * yAbleitungWerte.get(i));
			}
			yAbleitungWerteTest = ableitungen(yCopyTest, x+h);

			for (int i = 1; i <= fVonXmittlereSteigung.getDimension(); i++)
			{
				fVonXmittlereSteigung.set(i, 0.5*(yAbleitungWerte.get(i)+yAbleitungWerteTest.get(i)));
			}

			cout << "\t" << "y_Test = ( ";
			for (int j = 1; j <= yCopyTest.getDimension(); j++)
			{
				cout << yCopyTest.get(j) << "; ";
			}
			cout << " )" << endl;

			cout << "\t" << "y'_Test = ( ";
			for (int j = 1; j <= yAbleitungWerteTest.getDimension(); j++)
			{
				cout << yAbleitungWerteTest.get(j) << "; ";
			}
			cout << " )" << endl;

			cout << endl;

			cout << "\t" << "y'_Mittel = ( ";
			for (int j = 1; j <= fVonXmittlereSteigung.getDimension(); j++)
			{
				cout << fVonXmittlereSteigung.get(j) << "; ";
			}
			cout << " )" << endl;

			cout << endl;

			for (int i = 1; i <= yCopy.getDimension(); i++)
			{
				yCopy.set(i, yCopy.get(i)+h*fVonXmittlereSteigung.get(i));
			}

			x = x + h;
			s++;
			if (x >= XEnd) {

				cout << "Ende bei " << endl;
				cout << "\t" << "x = " << x << endl;
				cout << "\t" << "y = ( ";
				for (int j = 1; j <= yCopy.getDimension(); j++)
				{
					cout << yCopy.get(j) << "; ";
				}
				cout << " )" << endl;
				return yCopy;
				break;
			}

		}
	}
	
	return yCopy;
}

CMyVektor C_DGLSolver::ableitungen(CMyVektor y, double x)
{
	CMyVektor result(y.getDimension());

	if (isDGLSystem)
	{
		result = fDglSystemZeiger(y, x);
	}
	else
	{
		result.set(y.getDimension(), fDglNterOrdnungZeiger(y, x));
		for (int i = 1; i < y.getDimension(); i++)
		{
			result.set(i, y.get(i+1));
		}
		
	}
	return result;
}
