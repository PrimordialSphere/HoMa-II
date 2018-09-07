#include "CZufall.h"


CZufall::CZufall()
{
}

CZufall::~CZufall()
{
}

int CZufall::wert(int a, int b)
{
	int zufallsNummer = rand() % (b- a +1)+a;
	return zufallsNummer;
}

void CZufall::initialisiere(int n)
{
	srand(n);
}

vector<int> CZufall::test(int a, int b, int N)
{
	vector<int> result(b - a + 1);
	int zufallsNummer;

	for (int i = 0; i < N; i++)
	{
		zufallsNummer = wert(a, b);
		result[zufallsNummer-a]++;
	}

	return result;
}

vector<int> CZufall::test_falsch(int a, int b, int N)
{
	

	vector<int> result(b - a + 1);
	int zufallsNummer;

	for (int i = 0; i < N; i++)
	{
		initialisiere(time(NULL));
		zufallsNummer = wert(a, b);
		result[zufallsNummer-a]++;
	}

	return result;
}
