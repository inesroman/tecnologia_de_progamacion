/*
* File: rational.h
* Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
* Fecha: 22/02/2023
* 
*/



#pragma once

#include <iostream>

// Solucion con atributos privados.

class Rational
{
	// Funciones auxiliares
	
	// Devuelve el máximo común divisor entre a y b
	static int mcd(int a, int b);
	// Devuelve el mínimo común múltiplo entre a y b
	static int mcm(int a, int b);
	// Reduce la fracción a su irreducible
	void reduce();

public:
	// Constructores
	Rational();
	Rational(int num, int den);

	// Miembros
	int num;
	int den;

	// Entrada - salida
	void write(std::ostream& os) const;
	void read(std::istream& is);

	// FUNCIONES Rational-Rational, Rational-integer 
	// Devuelve la suma de dos números racionales
	Rational add(const Rational& that) const;
	// Devuelve la suma de un número racional con un entero
	Rational add(int i) const;

	// Devuelve la resta de dos números racionales
	Rational sub(const Rational& that) const;
	// Devuelve la resta de un número racional con un entero
	Rational sub(int i) const;

	// Devuelve la multiplicación de dos números racionales
	Rational mul(const Rational& that) const;
	// Devuelve la multiplicación de un número racional con un entero
	Rational mul(int i) const;

	// Devuelve la división de dos números racionales
	Rational div(const Rational& that) const;
	// Devuelve la división de un número racional con un entero
	Rational div(int i) const;

	// OPERADORES ARITMETICOS Rational-Rational, Rational-integer 
	// Definición del operador de suma con dos números racionales
	Rational operator+(const Rational& that) const;
	// Definición del operador de suma con un número racional y un entero
	Rational operator+(int i) const;

	// Definición del operador de resta con dos números racionales
	Rational operator-(const Rational& that) const;
	// Definición del operador de resta con un número racional y un entero
	Rational operator-(int i) const;

	// Definición del operador de multiplicación con dos números racionales
	Rational operator*(const Rational& that) const;
	// Definición del operador de multiplicación con un número racional y un entero
	Rational operator*(int i) const;

	// Definición del operador de división con dos números racionales
	Rational operator/(const Rational& that) const;
	// Definición del operador de división con un número racional y un entero
	Rational operator/(int i) const;
};

// OPERADORES ARITMETICOS entrada-salida 
std::ostream& operator<<(std::ostream& os, const Rational& r);
std::istream& operator>>(std::istream& is, Rational& r);

// FUNCIONES integer-Rational
Rational add(int i, Rational r);
Rational sub(int i, Rational r);
Rational mul(int i, Rational r);
Rational div(int i, Rational r);

// OPERADORES ARITMETICOS Rational-Rational, Rational-integer 
Rational operator+(int i, Rational r);
Rational operator-(int i, Rational r);
Rational operator*(int i, Rational r);
Rational operator/(int i, Rational r);