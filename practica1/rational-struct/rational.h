/*
* File: rational.h
* Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
* Fecha: 22/02/2023
* 
*/



#pragma once

#include <iostream>

// Solucion con atributos publicos.

struct Rational
{
   friend void init(Rational& r);
   friend void init(Rational& r,int num, int den);
   friend void write(const Rational& r, std::ostream& os);
   friend void read(Rational& r, std::istream& is);
   friend Rational add(const Rational& r1, const Rational& r2);
   friend Rational add(const Rational& r, int i);
   friend Rational add(int i, const Rational& r);
   friend Rational sub(const Rational& r1, const Rational& r2);
   friend Rational sub(const Rational& r, int i);
   friend Rational sub(int i, const Rational& r);
   friend Rational mul(const Rational& r1, const Rational& r2);
   friend Rational mul(const Rational& r, int i);
   friend Rational mul(int i, const Rational& r);
   friend Rational div(const Rational& r1, const Rational& r2);
   friend Rational div(const Rational& r, int i);
   friend Rational div(int i, const Rational& r);
   
   private:
      // componentes
      int num;
      int den;
      //operaciones privadas
      friend int mcd(int a, int b);
      friend int mcm(int a, int b);
      friend void reduce(Rational& r);
};

// Devuelve el máximo común divisor entre a y b
int mcd(int a, int b);
// Devuelve el mínimo común múltiplo entre a y b
int mcm(int a, int b);
// Reduce la fracción a su irreducible
void reduce(Rational& r);

// Da valor inicial 0/1 a la fracción
void init(Rational& r);
// Da valor inicial num/den a la fracción
void init(Rational& r,int num, int den);

// Entrada - salida
void write(const Rational& r, std::ostream& os);
void read(Rational& r, std::istream& is);

// Operaciones aritmeticas

// Devuelve la suma de dos números racionales
Rational add(const Rational& r1, const Rational& r2);
// Devuelve la suma de un número racional con un entero
Rational add(const Rational& r, int i);
// Devuelve la suma de un entero con un número racional
Rational add(int i, const Rational& r);

// Devuelve la resta de dos números racionales
Rational sub(const Rational& r1, const Rational& r2);
// Devuelve la resta de un número racional con un entero
Rational sub(const Rational& r, int i);
// Devuelve la resta de un entero con un número racional
Rational sub(int i, const Rational& r);

// Devuelve la multiplicación de dos números racionales
Rational mul(const Rational& r1, const Rational& r2);
// Devuelve la multiplicación de un número racional con un entero
Rational mul(const Rational& r, int i);
// Devuelve la multiplicación de un entero con un número racional
Rational mul(int i, const Rational& r);

// Devuelve la división de dos números racionales
Rational div(const Rational& r1, const Rational& r2);
// Devuelve la división de un número racional con un entero
Rational div(const Rational& r, int i);
// Devuelve la división de un entero con un número racional
Rational div(int i, const Rational& r); 
