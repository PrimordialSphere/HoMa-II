#ifndef CZufall_h
#define CZufall_h
#include <stdlib.h>
#include <vector>
#include <time.h>
#include<iostream>
using namespace std;

class CZufall {
private:
public:
	CZufall();
	~CZufall();

	int wert(int a, int b);
	void initialisiere(int n);
	vector<int> test(int a, int b, int N);
	vector<int> test_falsch(int a, int b, int N);
};

#endif // !CZufall_h