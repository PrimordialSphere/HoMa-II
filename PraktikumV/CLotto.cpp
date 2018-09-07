#include "CLotto.h"

vector<int> CLotto::ziehung()
{
	vector<int>result;

	int gezogeneZahl;
	int uniqueDrawnNumbers=0;

	while (uniqueDrawnNumbers <6)
	for (int i = 0; i < 6; i++)
	{
		gezogeneZahl = zufallsZahlenGenerator.wert(1, 49);
		vector<int>::iterator it = find(result.begin(), result.end(), gezogeneZahl);

		if (uniqueDrawnNumbers < 6) {
			if (it == result.end()) {
				result.push_back(gezogeneZahl);
				uniqueDrawnNumbers++;
			}
		}
		
	}

	return result;
}

CLotto::CLotto(int n)
{
	if (n < 0) {
		zufallsZahlenGenerator.initialisiere(time(NULL));
	}
	else
	{
		zufallsZahlenGenerator.initialisiere(n);
	}
}

CLotto::~CLotto()
{
}

int CLotto::richtigeZahlenTippzettel()
{
	vector<int> result = ziehung();

	int richtigeTipps = 0;

	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < tippzettel.size(); j++)
		{
			if (result[i]==tippzettel[j])
			{
				richtigeTipps++;
			}
		}
	}

	return richtigeTipps;
}

int CLotto::richtigeZahlenZweimaligeZiehung()
{
	vector<int> result = ziehung();
	vector<int> result2 = ziehung();

	int richtigeTipps = 0;

	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result2.size(); j++)
		{
			if (result[i] == result2[j])
			{
				richtigeTipps++;
			}
		}
	}

	return richtigeTipps;
}

void CLotto::setTippzettel(vector<int> tipps)
{
	for (int i = 0; i < tipps.size(); i++)
	{
		tippzettel.push_back(tipps[i]);

	}
}

