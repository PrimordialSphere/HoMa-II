#include "CLotto.h"
#include <iostream>
using namespace std;




int main (){
	/*Monte-Carlo-Simulation mit 1.000.000 Ziehungen und Wahrscheinlichkeit, dass drei Zahlen übereinstimmen mit vorher festgelegtem Tippzettel*/
	CLotto ihreLottoAnnahmestelle1(-1);
	vector<int> meinTippzettel;
	meinTippzettel.push_back(1);
	meinTippzettel.push_back(2);
	meinTippzettel.push_back(3);
	meinTippzettel.push_back(4);
	meinTippzettel.push_back(5);
	meinTippzettel.push_back(6);
	ihreLottoAnnahmestelle1.setTippzettel(meinTippzettel);

	int nk = 0;

	int trefferInZiehung=0;
	for (int i = 0; i < 1000000; i++)
	{
		trefferInZiehung = ihreLottoAnnahmestelle1.richtigeZahlenTippzettel();
		if (trefferInZiehung == 3) {
			nk++;
		}
	}
	double nkDurchN = (double)nk / 1000000;
	cout << "Wahrscheinlichkeit bei 1.000.000 Ziehungen drei richtige zu tippen (mit Tippzettel): " << nkDurchN << endl;


	/*Monte-Carlo-Simulation mit 1.000.000 Ziehungen und Wahrscheinlichkeit, dass drei Zahlen bei zwei verschiedenen Ziehungen übereinstimmen*/
	CLotto ihreLottoAnnahmestelle2(-1);

	int nk2 = 0;

	int trefferInZiehung2=0;
	for (int i = 0; i < 1000000; i++)
	{
		trefferInZiehung2 = ihreLottoAnnahmestelle2.richtigeZahlenZweimaligeZiehung();
		if (trefferInZiehung2 == 3) {
			nk2++;
		}
	}
	double nkDurchN2 = nk2 / 1000000;
	cout << "Wahrscheinlichkeit bei 1.000.000 Ziehungen drei mal die selben bei zwei verschiedenen Ziehungen zu ziehen: " << nkDurchN << endl;

	/*meinZufall.initialisiere(5);
	vector<int> ersteTestReihe = meinZufall.test(3, 7, 10000);
	for (int i = 0; i < ersteTestReihe.size(); i++)
	{
		cout << "Die Zahl " << i + 3 << " wurde " << ersteTestReihe[i] << "-mal gezogen. " << endl;
	}
	cout << endl;

	meinZufall.initialisiere(5);
	ersteTestReihe = meinZufall.test(3, 7, 10000);
	for (int i = 0; i < ersteTestReihe.size(); i++)
	{
		cout << "Die Zahl " << i + 3 << " wurde " << ersteTestReihe[i] << "-mal gezogen. " << endl;
	}
	cout << endl;

	meinZufall.initialisiere(5);
	ersteTestReihe = meinZufall.test(3, 7, 10000);
	for (int i = 0; i < ersteTestReihe.size(); i++)
	{
		cout << "Die Zahl " << i + 3 << " wurde " << ersteTestReihe[i] << "-mal gezogen. " << endl;
	}
	cout << endl;

	meinZufall.initialisiere(4);
	ersteTestReihe = meinZufall.test(3, 7, 10000);
	for (int i = 0; i < ersteTestReihe.size(); i++)
	{
		cout << "Die Zahl " << i + 3 << " wurde " << ersteTestReihe[i] << "-mal gezogen. " << endl;
	}
	cout << endl;

	meinZufall.initialisiere(3);
	ersteTestReihe = meinZufall.test(3, 7, 10000);
	for (int i = 0; i < ersteTestReihe.size(); i++)
	{
		cout << "Die Zahl " << i + 3 << " wurde " << ersteTestReihe[i] << "-mal gezogen. " << endl;
	}
	cout << endl;

	meinZufall.initialisiere(2);
	ersteTestReihe = meinZufall.test(3, 7, 10000);
	for (int i = 0; i < ersteTestReihe.size(); i++)
	{
		cout << "Die Zahl " << i + 3 << " wurde " << ersteTestReihe[i] << "-mal gezogen. " << endl;
	}
	cout << endl;


	meinZufall.initialisiere(time(NULL));
	ersteTestReihe = meinZufall.test(3, 7, 10000);
	for (int i = 0; i < ersteTestReihe.size(); i++)
	{
		cout << "Die Zahl " << i + 3 << " wurde " << ersteTestReihe[i] << "-mal gezogen. " << endl;
	}
	cout << endl;

	meinZufall.initialisiere(time(NULL));
	ersteTestReihe = meinZufall.test(3, 7, 10000);
	for (int i = 0; i < ersteTestReihe.size(); i++)
	{
		cout << "Die Zahl " << i + 3 << " wurde " << ersteTestReihe[i] << "-mal gezogen. " << endl;
	}
	cout << endl;

	meinZufall.initialisiere(time(NULL));
	ersteTestReihe = meinZufall.test(3, 7, 10000);
	for (int i = 0; i < ersteTestReihe.size(); i++)
	{
		cout << "Die Zahl " << i+3 << " wurde " << ersteTestReihe[i] << "-mal gezogen. " << endl;
	}
	cout << endl;

	
	ersteTestReihe = meinZufall.test_falsch(3, 7, 10000);
	for (int i = 0; i < ersteTestReihe.size(); i++)
	{
		cout << "Die Zahl " << i + 3 << " wurde " << ersteTestReihe[i] << "-mal gezogen. " << endl;
	}
	cout << endl;*/


	system("PAUSE");
}