#include "CMyMatrix.h"
using namespace std;


CMyVektor f(CMyVektor x) {
	double x1 = x.get(0);
	double x2 = x.get(1);
	double x3 = x.get(2);
	double x4 = x.get(3);

	CMyVektor neuerVektor(3);
	neuerVektor.set(0,x1*x2*exp(x3));
	neuerVektor.set(1,x2*x3*x4);
	neuerVektor.set(2, x4);

	return neuerVektor;
}

CMyVektor ff(CMyVektor x) {
	double x1 = x.get(0);
	double y = x.get(1);

	CMyVektor neuerVektor(2);
	neuerVektor.set(0, (pow(x1,3)*pow(y,3)-2*y));
	neuerVektor.set(1, x1-2);

	return neuerVektor;
}

CMyMatrix jacobi(CMyVektor x, CMyVektor(*funktion)(CMyVektor x)) {
	double h = pow(10, -4);
	// Dimensionen für die zu erzeugende Jacobi Matrix festlegen
	int dimVektor = x.getDimension();
	CMyVektor fResult = funktion(x);
	int dimResult = fResult.getDimension();

	//erzeugen der matrix für das Ergebnis
	CMyMatrix * jacobiResult = new CMyMatrix(dimResult,dimVektor);

	CMyVektor * copyOfX = new CMyVektor(x.getDimension());
	CMyVektor * copyOfXResult;
	double resultForMatrix;
	double fX, fStrichX;

	for (int i = 0; i < dimVektor; i++)
	{
		//	Eine Kopie des Startstellenvektors erstellen
		for (int k = 0; k < dimVektor; k++)
		{
			copyOfX->set(k, x.get(k));
		}
		copyOfX->set(i, x.get(i) + h);
		copyOfXResult = &(funktion(*copyOfX));

		//Resultat für alle Funktionen errechnen und in die Matrix einfügen
		for (int j = 0; j < dimResult; j++)
		{
			resultForMatrix = (copyOfXResult->get(j) - fResult.get(j))/h;
			jacobiResult->set(j+1, i+1, resultForMatrix);
		}


	}
	return *jacobiResult;
}

void newtonVerfahren(CMyVektor x, CMyVektor(*funktion)(CMyVektor x)) {
	int step = 0;
	CMyVektor * startStelleResult = &(funktion(x));
	CMyMatrix * startStelleJacobi;
	CMyMatrix * startStelleJacobiInverse;
	CMyVektor * dx;
	CMyVektor * startStelleResultInverted = new CMyVektor(startStelleResult->getDimension());
	CMyVektor * startStelle = new CMyVektor(x.getDimension());
	double epsilon = pow(10, -5);

	for (int m = 0; m < x.getDimension(); m++)
	{
		startStelle->set(m, x.get(m));
	}

	while (true )
	{
		cout << "Schritt " << step << ": " << endl;

		cout << "\t" << "          x = ( ";
		for (int i = 0; i < startStelle->getDimension(); i++)
		{
			cout << setfill(' ') << setw(14);
			cout  << startStelle->get(i);
		}
		cout  << " ) " << endl;

		cout << "\t" << "       f(x) = ( ";
		for (int i = 0; i < startStelleResult->getDimension(); i++)
		{
			cout << setfill(' ') << setw(14);
			cout << startStelleResult->get(i);
		}
		cout  << " ) " << endl;

		startStelleJacobi = &jacobi(*startStelle, ff);

		cout << "\t" << "      f'(x) = ( ";
		
		for (int i = 0; i < startStelleJacobi->getZeilen(); i++)
		{
			for (int j = 0; j < startStelleJacobi->getSpalten(); j++)
			{
				cout << setfill(' ') << setw(14);
				cout << startStelleJacobi->get(i+1,j+1);
			}
			cout << " | ";
		}
		cout  << " ) " << endl;
		
		startStelleJacobiInverse = &startStelleJacobi->inverse();

		cout << "\t" << "(f'(x)^(-1) = ( ";
		for (int i = 0; i < startStelleJacobiInverse->getZeilen(); i++)
		{
			for (int j = 0; j < startStelleJacobiInverse->getSpalten(); j++)
			{
				cout << setfill(' ') << setw(14);
				cout << startStelleJacobiInverse->get(i + 1, j + 1);
			}
			cout << " | ";
		}
		cout  << " ) " << endl;

		for (int i = 0; i < startStelleResult->getDimension(); i++)
		{
			startStelleResultInverted->set(i, startStelleResult->get(i)*-1);
		}

		dx = &( *startStelleJacobiInverse * *startStelleResultInverted);

		cout << "\t" << "         dx = ( ";
		for (int i = 0; i < dx->getDimension(); i++)
		{
				cout << setfill(' ') << setw(14);
				cout << dx->get(i);
		}
		cout  << " ) " << endl;


		for (int i = 0; i < startStelle->getDimension(); i++)
		{
			startStelle->set(i, startStelle->get(i) + dx->get(i));
		}


		cout << "\t"  << "   ||f(x)|| = ( ";
		cout << setfill(' ') << setw(14);
		cout  << startStelleResult->getLength();
		cout  << " ) " << endl;

		startStelleResult = &(funktion(*startStelle));

		step++;

		cout << endl;

		if (startStelleResult->getLength() < epsilon) {

			cout << "Ende wegen ||f(x)||<1e-5 bei " << endl;

			cout << "\t" << "          x = ( ";
			for (int i = 0; i < startStelle->getDimension(); i++)
			{
				cout << setfill(' ') << setw(14);
				cout  << startStelle->get(i);
			}
			cout << " ) " << endl;


			cout << "\t" << "       f(x) = ( ";
			for (int i = 0; i < startStelleResult->getDimension(); i++)
			{
				cout << setfill(' ') << setw(14);
				cout  << startStelleResult->get(i);
			}
			cout << "\t" << " ) " << endl;


			cout << "\t"  << "   ||f(x)|| = ( ";
			cout << setfill(' ') << setw(14);
			cout  << startStelleResult->getLength();
			cout << " ) " << endl;

			break;
			
		}

		if (step > 50)
		{
			cout << "Ende wegen Schritt = 50 bei " << endl;

			cout << "\t" << "          x = ( ";
			for (int i = 0; i < startStelle->getDimension(); i++)
			{
				cout << setfill(' ') << setw(14);
				cout << startStelle->get(i);
			}
			cout << " ) " << endl;

			cout << "\t" << "       f(x) = ( ";
			for (int i = 0; i < startStelleResult->getDimension(); i++)
			{
				cout << setfill(' ') << setw(14);
				cout  << startStelleResult->get(i);
			}
			cout  << " ) " << endl;


			cout << "\t" << "   ||f(x)|| = ( ";
			cout << setfill(' ') << setw(14);
			cout  << startStelleResult->getLength();
			cout  << " ) " << endl;

			break;
		}
	}
}

int main() {

	
	/*CMyMatrix * Karl = new CMyMatrix(2, 2);
	CMyMatrix * Lrak;
	CMyVektor * Peter = new CMyVektor(2);
	CMyVektor * PeterCalculated;
	CMyVektor *  inputTest = new CMyVektor(4);

	Karl->set(1, 1, 1);
	Karl->set(1, 2, 2);
	
	Karl->set(2, 1, 3);
	Karl->set(2, 2, 4);

	Peter->set(0, 0);
	Peter->set(1, 3);

	PeterCalculated = &(*Karl * *Peter);

	
	Lrak = &(Karl->inverse());

	Karl->printOut();
	Lrak->printOut();

	cout << setfill(' ') << setw(5);
	cout << PeterCalculated->get(0) << endl;
	cout << setfill(' ') << setw(5);
	cout << PeterCalculated->get(1);*/

	/*CMyVektor * startStelle = new CMyVektor(2);
	double startingValue = 1;
	startStelle->set(0, startingValue);
	startStelle->set(1, startingValue);
	CMyVektor * startStelleResult = &(ff(*startStelle));
	CMyMatrix * startStelleJacobi;

	cout << "\t" << "x = ( ";
	for (int i = 0; i < startStelle->getDimension(); i++)
	{
		cout << setfill(' ') << setw(7);
		cout << "\t"  << startStelle->get(i);
	}
	cout << "\t" << " ) " << endl;


	cout << "\t" << "f(x) = ( ";
	for (int i = 0; i < startStelleResult->getDimension(); i++)
	{
		cout << setfill(' ') << setw(7);
		cout << "\t"  << startStelleResult->get(i);
	}
	cout << "\t" << " ) "<<endl;

	startStelleJacobi = &jacobi(*startStelle, ff);
	startStelleJacobi->printOut();*/

	CMyVektor * startStelle = new CMyVektor(2);
	double startingValue = 1;
	startStelle->set(0, startingValue);
	startStelle->set(1, startingValue);

	newtonVerfahren(*startStelle, ff);
	

	cout << endl;

	system("PAUSE");

}