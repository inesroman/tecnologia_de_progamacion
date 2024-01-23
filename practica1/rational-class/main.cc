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
		// PRUEBAS CON FUNCIONES
		/*a.read(cin);
		//cin >> a;
		if (cin.fail())
			break;

		cin >> op;
		if (cin.fail())
			break;

		b.read(cin);
		//cin >> b;
		if (cin.fail())
			break;

		//Rational op Rational, Rational op integer
		switch(op) {
			case '+': r = a.add(b); break;
			case '-': r = a.sub(b); break;
			case '*': r = a.mul(b); break;
			case '/': r = a.div(b);
		}
		//integer op Rational
		switch(op) {
			case '+': r = add(a, b); break;
			case '-': r = sub(a, b); break;
			case '*': r = r = mul(a, b); break;
			case '/': r = r = div(a, b);
		}

		r.write(cout);*/

		// PRUEBAS CON OPERADORES
		cin >> a;
		if (cin.fail())
			break;

		cin >> op;
		if (cin.fail())
			break;

		cin >> b;
		if (cin.fail())
			break;
		
		switch(op) {
			case '+': r = a+b; break;
			case '-': r = a-b; break;
			case '*': r = a*b; break;
			case '/': r = a/b;
		} 
		cout << r;	
	}
	return 0;
}
