#ifndef CLotto_h
#define CLotto_h
#include"CZufall.h"
using namespace std;

class CLotto {
private:
	CZufall zufallsZahlenGenerator;
	vector<int> tippzettel;
	vector<int> ziehung();
public:
	CLotto(int n);
	~CLotto();
	int richtigeZahlenTippzettel();
	int richtigeZahlenZweimaligeZiehung();
	void setTippzettel(vector<int> tipps);

};

#endif // !CLotto_h