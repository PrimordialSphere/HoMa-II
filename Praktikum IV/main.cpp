#include "CKomplex.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>   
#include <vector>
#include <algorithm>
using namespace std;


vector<CKomplex>  werte_einlesen(const char *dateiname)
{
	int i, N, idx;
	double re, im;
	vector<CKomplex> werte;
	// File oeffnen
	ifstream fp;
	fp.open(dateiname);
	// Dimension einlesen
	fp >> N;
	// Werte-Vektor anlegen
	werte.resize(N);
	CKomplex null(0, 0);
	for (i = 0; i<N; i++)
		werte[i] = null;
	// Eintraege einlesen und im Werte-Vektor ablegen
	while (!fp.eof())
	{
		fp >> idx >> re >> im;
		CKomplex a(re, im);
		werte[idx] = a;
	}
	// File schliessen
	fp.close();

	return werte;
}

void werte_ausgeben(const char *dateiname, vector<CKomplex> werte, double epsilon = -1.0)
{
	int i;
	int N = werte.size();
	// File oeffnen
	ofstream fp;
	fp.open(dateiname);
	// Dimension in das File schreiben
	fp << N << endl;
	// Eintraege in das File schreiben
	fp.precision(10);
	for (i = 0; i < N; i++)
		if (werte[i].abs() > epsilon)
			fp << i << "\t" << werte[i].re() << "\t" << werte[i].im() << endl;
	// File schliessen
	fp.close();
}

vector<CKomplex> fourierTransformationHin(vector<CKomplex> inputValues) {
	
	vector<CKomplex> result;
	result.resize(inputValues.size());

	int grossN = inputValues.size();

	for (int n = 0; n < grossN; n++) {

		CKomplex v; 

		for (int k = 0; k < grossN; k++) {

		
			v += ( CKomplex(((-2.0*M_PI*k*n)/ (double)grossN))*inputValues[k]);

		}
		v *= (1 / sqrt(grossN));
		result[n] = v;

	}

	return result;
}

vector<CKomplex> fourierTransformationRueck(vector<CKomplex> inputValues) {

	vector<CKomplex> result;
	result.resize(inputValues.size());

	int grossN = inputValues.size();

	for (int k = 0; k < grossN; k++) {

		CKomplex v;

		for (int n = 0; n < grossN; n++) {

			
			v += (CKomplex(((2.0*M_PI*k*n) / (double)grossN))*inputValues[k] );

		}
		v *= (1 / sqrt(grossN));
		result[k] = v;

	}

	return result; 
}




double abweichung(vector<CKomplex> hin, vector<CKomplex> rueck) {
	double result = 0;
	double zwischenspeicher;

	

	for (int i = 0; i < hin.size(); i++) {
		zwischenspeicher = abs(hin[i].abs() - rueck[i].abs());
		if (zwischenspeicher > result) {
			result = zwischenspeicher;
		}
	}

	return result; 
}

int main() {
	vector<CKomplex> Eingabe(werte_einlesen("Daten_original.txt"));
	vector<CKomplex> Ausgabe;
	Ausgabe.resize(Eingabe.size());
	Ausgabe = fourierTransformationHin(Eingabe);

	werte_ausgeben("datei1.txt", Ausgabe);
	werte_ausgeben("datei2.txt", Ausgabe, 0.1);
	werte_ausgeben("datei3.txt", Ausgabe, 1.0);

	vector<CKomplex> E1;
	E1.resize(Eingabe.size());
	E1 = (werte_einlesen("datei1.txt"));
	vector<CKomplex> E1rueck;
	E1rueck.resize(E1.size());
	E1rueck = fourierTransformationRueck(E1);
	double ergebnis1 = abweichung(E1, E1rueck);
	cout << ergebnis1 << endl;

	vector<CKomplex> E2 = werte_einlesen("datei2.txt");
	vector<CKomplex> E2rueck = fourierTransformationRueck(E2);
	double ergebnis2 = abweichung(E2, E2rueck);
	cout << ergebnis2 << endl;


	vector<CKomplex> E3 = werte_einlesen("datei3.txt");
	vector<CKomplex> E3rueck = fourierTransformationRueck(E3);
	double ergebnis3 = abweichung(E3, E3rueck);
	cout << ergebnis3 << endl;

	system("PAUSE");
}