
#include "CMyVektor.h"
#include<iostream>
#include<string.h>
using namespace std;

double f(CMyVektor * eingabe) {
	double x = eingabe->get(0);
	double y = eingabe->get(1);
	double solution = sin(x + pow(y, 2)) + pow(y, 3) - 6 * pow(y, 2) + 9 * y;
	return solution;
}

double g(CMyVektor * eingabe) {
	double x = eingabe->get(0);
	double y = eingabe->get(1);
	double z = eingabe->get(2);

	double solution = -(2 * pow(x, 2) - 2 * x*y + pow(y, 2) + pow(z, 2) - 2 * x - 4 * z);

	return solution;
}

CMyVektor * gradient(CMyVektor * x, double(*funktion)(CMyVektor * x))
{
	int dim = x->getDimension();
	double h = pow(10,-8);
	double fVonX = funktion(x);
	double valueSlightlyChanged;
	double fVonXSlightlyChanged;
	double result;
	double newValue;
	CMyVektor * neuX = new CMyVektor(dim);
	CMyVektor * temp = new CMyVektor(dim);



	for (int i = 0; i < dim; i++)
	{
		/* temp = x*/
		for (int i = 0; i < dim; i++)
		{
			newValue = x->get(i);
			temp->set(i, newValue);
		}

		valueSlightlyChanged = temp->get(i) + h;
		temp->set(i, valueSlightlyChanged);
		fVonXSlightlyChanged = funktion(temp);
		result = (fVonXSlightlyChanged - fVonX) / h;
		neuX->set(i, result);
	}

	

	return neuX;

}

void gradientenverfahren(CMyVektor * x, double(*funktion)(CMyVektor * x), double lambda = 1) {
	CMyVektor * temporary = new CMyVektor(x->getDimension());
	CMyVektor * temporary2 = new CMyVektor(x->getDimension());
	CMyVektor * test = new CMyVektor(x->getDimension());
	double fVonXOld;
	double kriterium = pow(10, -5);
	double fVonXNew;
	double schrittweite = lambda;
	double schrittweiteTest;
	double newValue;
	int cycle = 0; 
	while (true)
	{
		cout << "Schritt " << cycle << ":" << endl;
		cout << "\t" << "x = ( ";
		for (int i = 0; i < x->getDimension(); i++)
		{
			cout << x->get(i) << " ";
		}
		cout << ")" << endl;
		
		cout << "\t" << "lambda = " << schrittweite<<endl;

		fVonXOld = funktion(x);
		cout << "\t" << "f(x) = " << fVonXOld << endl;
		
		temporary = gradient(x, funktion);
		cout << "\t" << "grad f(x) = ( ";
		for (int i = 0; i < temporary->getDimension(); i++)
		{
			cout << temporary->get(i) << " ";
		}
		cout << ")" << endl;
		
		cout << "\t" << "||grad f(x)|| = " << temporary->getLength() << endl << endl;

		

		/*temporary2 = x;*/
		for (int i = 0; i < x->getDimension(); i++)
		{
			newValue = x->get(i);
			temporary2->set(i, newValue);
		}

		/*temporary2 = temporary2 + temporary*schrittweite;*/
		for (int i = 0; i < x->getDimension(); i++)
		{
			newValue = temporary2->get(i) + temporary->get(i) * schrittweite;
			temporary2->set(i, newValue);
		}
		

		cout << "\t" << "x_neu = ( ";
		for (int i = 0; i < x->getDimension(); i++)
		{
			cout << temporary2->get(i)<< " " ;
		}
		cout << ")" << endl;
		
		fVonXNew = funktion(temporary2);
		cout << "\t" << "f(x_neu) = " << fVonXNew << endl << endl;



		
		

		if(fVonXNew > fVonXOld){
			
			/*test = x;*/
			for (int i = 0; i < x->getDimension(); i++)
			{
				newValue = x->get(i);
				test->set(i, newValue);
			}

			schrittweiteTest = schrittweite * 2;
			/*test = test + temporary * schrittweiteTest;*/
			for (int i = 0; i < x->getDimension(); i++)
			{
				newValue = test->get(i) + temporary->get(i) * schrittweiteTest;
				test->set(i, newValue);
			}

			cout << "\t" << "Teste mit doppelter Schrittweite (lambda = " << schrittweiteTest << "):" << endl;
			cout << "\t" << "x_test = ( ";
			for (int i = 0; i < x->getDimension(); i++)
			{
				cout << test->get(i) << " ";
			}
			cout << ")" << endl;
			cout << "\t" << "f(x_test) = " << funktion(test) << endl;
			if (funktion(test) > fVonXNew) {
				/*x = test;*/
				for (int i = 0; i < x->getDimension(); i++)
				{
					newValue = test->get(i);
					x->set(i, newValue);
				}
				schrittweite = schrittweiteTest;
				cout << "\t" << "verdoppele Schrittweite" << endl <<endl;
			}
			else { 
				/*x = temporary2;*/
				for (int i = 0; i < x->getDimension(); i++)
				{
					newValue = temporary2->get(i);
					x->set(i, newValue);
				}
			cout << "\t" << "behalte alte Schrittweite!" << endl <<endl;
			}
		}
		else if (fVonXNew <= fVonXOld){
		
			while (true)
			{

		


				/*test = x;*/
				for (int i = 0; i < x->getDimension(); i++)
				{
					newValue = x->get(i);
					test->set(i, newValue);
				}
				schrittweite = schrittweite / 2;
				cout << "\t" << "halbiere Schrittweite (lambda = " << schrittweite << "):" << endl;
				

				/*test = x + temporary * schrittweite ;*/
				for (int i = 0; i < x->getDimension(); i++)
				{
					newValue = x->get(i) + temporary->get(i) * schrittweite;
					test->set(i, newValue);
				}
				

				cout << "\t" << "x_neu = ( ";
				for (int i = 0; i < x->getDimension(); i++)
				{
					cout << test->get(i) << " ";
				}
				cout << ")" << endl;

				cout << "\t" << "f(x_neu) = " << funktion(test) << endl << endl;

				if (funktion(test) > fVonXOld) {
					/*x = test;*/
					for (int i = 0; i < x->getDimension(); i++)
					{
						newValue = test->get(i);
						x->set(i, newValue);
					}
					break;
				}
			}
		}


		

		cycle++;
		
		if (cycle >= 50) {
			cout << "Ende wegen Schrittzahl = 50 bei" << endl;
			cout << "\t" << "x = ( ";
			for (int i = 0; i < x->getDimension(); i++)
			{
				cout << x->get(i) << " ";
			}
			cout << ")" << endl;

			cout << "\t" << "lambda = " << schrittweite << endl;

			fVonXOld = funktion(x);
			cout << "\t" << "f(x) = " << fVonXOld << endl;

			temporary = gradient(x, funktion);
			cout << "\t" << "grad f(x) = ( ";
			for (int i = 0; i < temporary->getDimension(); i++)
			{
				cout << temporary->get(i) << " ";
			}
			cout << ")" << endl;

			cout << "\t" << "||grad f(x)|| = " << temporary->getLength() << endl<<endl;
			break;
		}

		temporary = gradient(x, funktion);
		if (temporary->getLength() < kriterium) {
			cout << "Ende wegen ||grad f(x)|| <1e-5 bei" << endl;
			cout << "\t" << "x = ( ";
			for (int i = 0; i < x->getDimension(); i++)
			{
				cout << x->get(i) << " ";
			}
			cout << ")" << endl;

			cout << "\t" << "lambda = " << schrittweite << endl;

			fVonXOld = funktion(x);
			cout << "\t" << "f(x) = " << fVonXOld << endl;

			temporary = gradient(x, funktion);
			cout << "\t" << "grad f(x) = ( ";
			for (int i = 0; i < temporary->getDimension(); i++)
			{
				cout << temporary->get(i) << " ";
			}
			cout << ")" << endl;

			cout << "\t" << "||grad f(x)|| = " << temporary->getLength() << endl << endl;

			break;
		}
	}
}

int main() {



	CMyVektor *  meinVektor = new CMyVektor(2);
	meinVektor->set(0, 3);
	meinVektor->set(1, 2);
	

	gradientenverfahren(meinVektor, f);

	CMyVektor *  meinVektor2 = new CMyVektor(3);
	meinVektor2->set(0, 0);
	meinVektor2->set(1, 0);
	meinVektor2->set(2, 0);

	gradientenverfahren(meinVektor2, g, 0.1);

	system("PAUSE");


}

