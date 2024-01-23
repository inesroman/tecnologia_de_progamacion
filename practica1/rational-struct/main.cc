/*
* File: main.cc
* Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
* Fecha: 22/02/2023
* Coms: make para compilar, después ./main
*/


#include "rational.h"
#include <iostream>

using namespace std;

int main()
{	
	//Rational op Rational
	Rational a,b,r;
	char op;

	//Rational op integer
	/*Rational a, r;
	int b;
	char op;*/

	//integer op Rational
	/*Rational b,r;
	int a;
	char op;*/

	while (true)
	{	
		cout << "? " << flush;
		read(a,cin);
		//cin >> a;
		if (cin.fail())
			break;

		cin >> op;
		if (cin.fail())
			break;

		read(b,cin);
		//cin >> b;
		if (cin.fail())
			break;	

		switch(op) {
			case '+': r = add(a,b); break;
			case '-': r = sub(a,b); break;
			case '*': r = mul(a,b); break;
			case '/': r = div(a,b);
		}

		write(r,cout);		
	}
	return 0;
}