#include "C_DGLSolver.h"
using namespace std;

CMyVektor DGLSystem(CMyVektor y, double x) {
	CMyVektor result(2);
	result.set(1, 2 * y.get(2) - x * y.get(1));
	result.set(2, y.get(1)*y.get(2)-2*pow(x,3));
	return result;
}

double DGL_dritter_Ordnung(CMyVektor y, double x) { 
	double result;
	result = 2 * x*y.get(2)*y.get(3) + 2 * pow(y.get(1), 2)*y.get(2);
	return result;
}

int main() {
	

	/*CMyVektor * startwerte = new CMyVektor(2);
	startwerte->set(1, 0);
	startwerte->set(2, 1);
	double xStart = 0;
	double xEnd = 2;
	C_DGLSolver * dglSystemTest = new C_DGLSolver(DGLSystem);
	dglSystemTest->euler(*startwerte, xStart, xEnd, 100);*/







	/*CMyVektor * startwerte = new CMyVektor(2);
	startwerte->set(1, 0);
	startwerte->set(2, 1);
	double xStart = 0;
	double xEnd = 2;
	C_DGLSolver * dglSystemTest = new C_DGLSolver(DGLSystem);
	dglSystemTest->heun(*startwerte, xStart, xEnd, 100);*/






	/*CMyVektor * startwerte = new CMyVektor(3);
	CMyVektor * eulerResult = new CMyVektor(3);
	CMyVektor * heunResult = new CMyVektor(3);
	CMyVektor * allResults = new CMyVektor(8);
	C_DGLSolver * dglSystemTest = new C_DGLSolver(DGL_dritter_Ordnung);

	double schrittweite;
	double xStart;
	double xEnd;
	int j = 1;
	for (int i = 1; i <= 4; i++)
	{
		schrittweite = pow(10, i);
		xStart = 1;
		xEnd = 2;

		startwerte->set(1, 1);
		startwerte->set(2, -1);
		startwerte->set(3, 2);
		eulerResult = &(dglSystemTest->euler(*startwerte, xStart, xEnd, schrittweite));
		allResults->set(j, eulerResult->get(1) - 0.5);

		startwerte->set(1, 1);
		startwerte->set(2, -1);
		startwerte->set(3, 2);
		heunResult = &(dglSystemTest->heun(*startwerte, xStart, xEnd, schrittweite));
		allResults->set(j+1, heunResult->get(1) - 0.5);
		j = j + 2;
	
	}
	cout << endl;
	int k = 1 ;
	for (int j = 1; j <= 4; j++)
	{
		double schrittweite = pow(10, j);
		cout << "Abweichung bei Euler bei " << schrittweite << " Schritten: " << allResults->get(k) << endl;
		cout << "Abweichung bei Heun bei " << schrittweite << " Schritten: " << allResults->get(k+1) << endl;
		k = k + 2;
		
	}*/
	

	/*
	*/CMyVektor startwerte(3);
	CMyVektor eulerResult(3);
	CMyVektor heunResult(3);
	CMyVektor allResults(8);
	C_DGLSolver dglSystemTest(DGL_dritter_Ordnung);



	double xStart = 1.0;
	double xEnd = 2.0;

	startwerte.set(1, 1);
	startwerte.set(2, -1);
	startwerte.set(3, 2);
	eulerResult = (dglSystemTest.euler(startwerte, xStart, xEnd,1000));
	allResults.set(1, eulerResult.get(1) - 0.5);

		/*startwerte.set(1, 1);
		startwerte.set(2, -1);
		startwerte.set(3, 2);
	
		heunResult = (dglSystemTest.heun(startwerte, xStart, xEnd, 1000));
		allResults.set(2, heunResult.get(1) - 0.5);*/


		cout << "Abweichung bei Euler bei " << "1000"<< " Schritten: " << allResults.get(1) << endl;
		/*cout << "Abweichung bei Heun bei " << "1000" << " Schritten: " << allResults.get(2) << endl;


		eulerResult.set(1, 8);
		eulerResult.set(2, 9);
		eulerResult.set(3, 10);
		cout << eulerResult.get(1) << " ## " << eulerResult.get(2) << " ## " << eulerResult.get(3) << endl;
		startwerte = eulerResult + startwerte;

		cout << startwerte.get(1) << " ## " << startwerte.get(2) << " ## " << startwerte.get(3) << endl;*/

	cout << endl << endl;
	system("PAUSE");
}