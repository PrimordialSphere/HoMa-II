#include "CMyMatrix.h"
using namespace std;

CMyMatrix::CMyMatrix(int zeile, int spalte) {
	const int v = zeile * spalte;
	zeilen = zeile;
	spalten = spalte;
	limit = v;
	matrix = new double[v];
}

CMyMatrix::~CMyMatrix()
{
}

void CMyMatrix::printOut(void)
{
	
	for (int i = 0; i < limit; i++)
	{
		cout << setfill(' ') << setw(5);
		cout << *(matrix + i);
		
		if (((i % spalten)==1) && (i != 0))
		{
			cout << endl;
		}
	}
	cout << endl;
}

void CMyMatrix::set(int zeile, int spalte, double value)
{
	int z = (zeile-1) * zeilen;
	int s = spalte - 1;
	*(matrix + z + s) = value;
}

double CMyMatrix::get(int zeile, int spalte)
{
	int z = (zeile-1) * zeilen;
	int s = spalte - 1;

	return *(matrix + z + s);
}

CMyMatrix CMyMatrix::inverse(void)
{
	if (zeilen != 2 || spalten != 2) {
		cout << "Berechnung des Inversen nicht moeglich!" << endl;
		getchar();
		exit(-1);
		
	}
	else if (((this->get(1, 1)*this->get(2, 2)) - (this->get(1, 2)*this->get(2, 1))) == 0)
	{
		cout << "Berechnung des Inversen nicht moeglich!" << endl;
		getchar();
		exit(-1);
	}
	else {
		CMyMatrix neueMatrix(2, 2);
		double invBruch = (1 / ((this->get(1, 1)*this->get(2, 2)) - (this->get(1, 2)*this->get(2, 1))));
		neueMatrix.set(1, 1, this->get(2, 2)*invBruch);
		neueMatrix.set(1, 2, -1*this->get(1, 2)*invBruch);
		neueMatrix.set(2, 1, -1*this->get(2, 1)*invBruch);
		neueMatrix.set(2, 2, this->get(1, 1)*invBruch);

		return neueMatrix;
	}
}

int CMyMatrix::getSpalten(void)
{
	return spalten;
}

int CMyMatrix::getLimit(void)
{
	return limit;
}

int CMyMatrix::getZeilen(void)
{
	return zeilen;
}

CMyVektor operator*(CMyMatrix A, CMyVektor x)
{
	if (A.getSpalten() != x.getDimension()) {
		cout << "Matrix-Vektor Multiplikation nicht moeglich!" << endl;
		exit(-1);
	}
	else
	{
		CMyVektor neuerVektor(x.getDimension());
		int l = A.getZeilen();
		int m = A.getSpalten();
		double value =0;
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < m; j++)
			{
				value = value + A.get(i + 1, j + 1)*x.get(j);

			}
			
			neuerVektor.set(i, value);
			value = 0;
		}
		return neuerVektor;
	}
	
}
