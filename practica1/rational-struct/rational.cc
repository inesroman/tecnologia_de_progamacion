/*
* File: rational.cc
* Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
* Fecha: 22/02/2023
* 
*/


#include "rational.h"

// Helper functions -----------------------
int mcd(int a, int b) {
   return ( b == 0 ? a : mcd(b,a%b));
}

int mcm(int a, int b){
	return (a*b)/mcd(a, b);
}

void reduce(Rational& r) {
	int n = mcd(r.num, r.den);
	if(n != 1){
		r.num = r.num/n;
		r.den = r.den/n;
	}
	if(r.den < 0){
		r.den = -(r.den);
		r.num = -(r.num);  
	}
}

// Constructor -----------------------
void init(Rational& r) {
   r.den = 1;
   r.num = 0;
}
void init(Rational& r,int num, int den) {
   r.den = den;
   r.num = num;
}

// Input/output ---------------------------------
void write(const Rational& r, std::ostream& os) {
 	os << "= " << r.num;
	if(r.den != 1){
		os << "/" << r.den;
	}
	os << "\n";
}

void read(Rational& r, std::istream& is) {
	char c;
	is >> r.num;
	is >> c;
	if(c == '/'){
		is >> r.den;
		if(r.den == 0){ //ERROR
			exit(1);
		}
	}else{
		exit(1);
	}
	reduce(r);
}

// Add -----------------------
Rational add(const Rational& r1, const Rational& r2) {
	Rational res;
	int n = mcm(r1.den, r2.den);
	res.den = n;
	res.num = r1.num*(n/r1.den) + r2.num*(n/r2.den);
	reduce(res);
	return res;
}

Rational add(const Rational& r, int i) {
	Rational res;
	res.num = r.num + i*r.den;
	res.den = r.den;
	reduce(res);
	return res;
}

Rational add(int i, const Rational& r) {
	Rational res;
	res.num = r.num + i*r.den;
	res.den = r.den;
	reduce(res);
	return res;
}

// Subtract -----------------------
Rational sub(const Rational& r1, const Rational& r2) {
	Rational res;
	res.den = r1.den*r2.den;
	res.num = r1.num*r2.den - r1.den*r2.num;
	reduce(res);
	return res;
}

Rational sub(const Rational& r, int i) {
	Rational res;
	res.num = r.num - i*r.den;
	res.den = r.den;
	reduce(res);
	return res;
}

Rational sub(int i, const Rational& r) {
	Rational res;
	res.num = i*r.den - r.num;
	res.den = r.den;
	reduce(res);
	return res;
}

// Multiply -------------------------
Rational mul(const Rational& r1, const Rational& r2) {
	Rational res;
	res.num = r1.num*r2.num;
	res.den = r1.den*r2.den;
	reduce(res);
	return res;
}

Rational mul(const Rational& r, int i) {
	Rational res;
	res.num = r.num*i;
	res.den = r.den;
	reduce(res);
	return res;	
}

Rational mul(int i, const Rational& r) {
	Rational res;
	res.num = r.num*i;
	res.den = r.den;
	reduce(res);
	return res;	
}

// Divide ------------------------------
Rational div(const Rational& r1, const Rational& r2) {
	Rational res;
	if(r2.num == 0){
		std::cerr << "ERROR:NO SE PUEDE DIVIDIR ENTRE 0"<< std::endl; exit(1);
	}
	res.num = r1.num*r2.den;
	res.den = r1.den*r2.num;
	reduce(res);
	return res;
}

Rational div(const Rational& r, int i) {
	Rational res;
	if(i == 0){
		std::cerr << "ERROR:NO SE PUEDE DIVIDIR ENTRE 0"<< std::endl; exit(1);
	}
	res.num = r.num;
	res.den = r.den*i;
	reduce(res);
	return res;	
}

Rational div(int i, const Rational& r) {
	Rational res;
	if(r.num == 0){
		std::cerr << "ERROR:NO SE PUEDE DIVIDIR ENTRE 0"<< std::endl; exit(1);
	}
	res.num = i*r.den;
	res.den = r.num;
	reduce(res);
	return res;	
}
