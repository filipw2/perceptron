// perctreptron1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class perceptron{
private:
	double w1, w2, eta;
public:
	perceptron(){ w1 = 0; w2 = 0; eta = 0; }
	perceptron(double w11, double w22, double eta1){ 
		w1 = w11; 
		w2 = w22; 
		eta = eta1; 
	}

	double suma(double x1, double x2){ 
		return x1*w1 + x2*w2 + eta; 
	}

	double akt_bipolarna(double x1, double x2){
		if (suma(x1,x2) > 0) return 1.0;
		else return -1.0;
	}

	bool teach(double **tab){
		double blad = 0.0;
		double t;
		for (int i = 0; i < 7; i++){
			t = akt_bipolarna(tab[i][0], tab[i][1]);
			if ( t != tab[i][2])
			{
				w1 = w1 + tab[i][2] * tab[i][0];
				w2 = w2 + tab[i][2] * tab[i][1];
				eta = eta + tab[i][2];
				double tmp = t - tab[i][2];
				blad += tmp*tmp;
			}
		}
		cout << "w1=" << w1 << "\nw2=" << w2 <<  "\neta=" << eta << "\nblad=" << blad << endl << endl;
		if(blad!=0)return true;
		else return false;
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	double w1 = 0, w2 = 0, dx = 0;
	int  n = 7;
	double *x1,*x2;
	double **dane;

	x1 = new double[n];
	x2 = new double[n];
	dane = new double*[n];

	for (int i = 0; i < n; i++) dane[i] = new double[3];
	
	x1[0] = 2; x1[1] = 2; x1[2] = 0; x1[3] = -2; 
	x1[4] = -2; x1[5] = 0; x1[6] = 4;
	x2[0] = 1; x2[1] = 2; x2[2] = 6; x2[3] = 8; 
	x2[4] = 0; x2[5] = 0; x2[6] = -20;
	
	for (int i = 0; i < n; i++)					
		{
		dane[i][0] = x1[i];		//x1
		dane[i][1] = x2[i];		//x2
		if(i<3) dane[i][2] = 1;	//d(x) wartosc wzorcowa
		else dane[i][2] = -1;
		}

	perceptron p;
	while(p.teach(dane));
	
	for (int i = 0; i<n; i++)
		delete dane[i];
	
	
	delete[]x1;
	delete[]x2;
	delete[]dane;
	
	system("PAUSE");
	return 0;
}

