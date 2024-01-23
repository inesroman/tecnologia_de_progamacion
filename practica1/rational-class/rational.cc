/*
* File: rational.cc
* Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
* Fecha: 22/02/2023
* 
*/


#include "rational.h"

// Helper methods -----------------------
int Rational::mcd(int a, int b) {
   return ( b == 0 ? a : mcd(b,a%b));
}

int Rational::mcm(int a, int b) {
	return (a*b)/mcd(a, b);
}

void Rational::reduce() {
int n = mcd(num, den);
	if(n != 1){
		num = num/n;
		den = den/n;
	}
	if(den < 0){
		den = -(den);
		num = -(num);  
	}}

// Constructor -----------------------
Rational::Rational() 
	:num(0), den(1) 
{}

Rational::Rational(int num, int den) 
	:num(num), den(den)
{}

// Input/output ---------------------------------
void Rational::write(std::ostream& os) const {
 	os << "= " << num;
	if(den != 1){
		os << "/" << den;
	}
	os << "\n";
}

void Rational::read(std::istream& is) {
	char c;
	is >> num;
	is >> c;
	if(c == '/'){
		is >> den;
		if(den == 0){ //ERROR
			exit(1);
		}
	}else{
		exit(1);
	}
	reduce();
}

// Add -----------------------
Rational Rational::add(const Rational& that) const {
	Rational res;
	int n = mcm(den, that.den);
	res.den = n;
	res.num = num*(n/den) + that.num*(n/that.den);
	res.reduce();
	return res;
}

Rational Rational::add(int i) const {
	Rational res;
	res.num = num + i*den;
	res.den = den;
	res.reduce();
	return res;
}

// Subtract -----------------------
Rational Rational::sub(const Rational& that) const {
	Rational res;
	int n = mcm(den, that.den);
	res.den = n;
	res.num = num*(n/den) - that.num*(n/that.den);
	res.reduce();
	return res;
}

Rational Rational::sub(int i) const {
	Rational res;
	res.num = num - i*den;
	res.den = den;
	res.reduce();
	return res;
}

// Multiply -------------------------
Rational Rational::mul(const Rational& that) const {
	Rational res;
	res.num = num*that.num;
	res.den = den*that.den;
	res.reduce();
	return res;
}

Rational Rational::mul(int i) const {
	Rational res;
	res.num = num*i;
	res.den = den;
	res.reduce();
	return res;
}

// Divide ------------------------------
Rational Rational::div(const Rational& that) const {
	Rational res;
	if(that.num == 0){
		std::cerr << "ERROR:NO SE PUEDE DIVIDIR ENTRE 0"<< std::endl; exit(1);
	}
	res.num = num*that.den;
	res.den = den*that.num;
	res.reduce();
	return res;
}

Rational Rational::div(int i) const {
	Rational res;
	if(i == 0){
		std::cerr << "ERROR:NO SE PUEDE DIVIDIR ENTRE 0"<< std::endl; exit(1);
	}
	res.num = num;
	res.den = den*i;
	res.reduce();
	return res;
}

// Operator + -----------------------
Rational Rational::operator+(const Rational& that) const {
	Rational res;
	int n = mcm(den, that.den);
	res.den = n;
	res.num = num*(n/den) + that.num*(n/that.den);
	res.reduce();
	return res;
}

Rational Rational::operator+(int i) const {
	Rational res;
	res.num = num + i*den;
	res.den = den;
	res.reduce();
	return res;
}

// Operator - -----------------------
Rational Rational::operator-(const Rational& that) const {
	Rational res;
	int n = mcm(den, that.den);
	res.den = n;
	res.num = num*(n/den) - that.num*(n/that.den);
	res.reduce();
	return res;
}

Rational Rational::operator-(int i) const {
	Rational res;
	res.num = num - i*den;
	res.den = den;
	res.reduce();
	return res;
}

// Operator * -------------------------
Rational Rational::operator*(const Rational& that) const {
	Rational res;
	res.num = num*that.num;
	res.den = den*that.den;
	res.reduce();
	return res;
}

Rational Rational::operator*(int i) const {
	Rational res;
	res.num = num*i;
	res.den = den;
	res.reduce();
	return res;
}

// Operator / ------------------------------
Rational Rational::operator/(const Rational& that) const {
	Rational res;
	if(that.num == 0){
		std::cerr << "ERROR:NO SE PUEDE DIVIDIR ENTRE 0"<< std::endl; exit(1);
	}
	res.num = num*that.den;
	res.den = den*that.num;
	res.reduce();
	return res;
}

Rational Rational::operator/(int i) const {
	Rational res;
	if(i == 0){
		std::cerr << "ERROR:NO SE PUEDE DIVIDIR ENTRE 0"<< std::endl; exit(1);
	}
	res.num = num;
	res.den = den*i;
	res.reduce();
	return res;
}

std::ostream& operator<<(std::ostream& os, const Rational& r){
 	os << "= " << r.num;
	if(r.den != 1){
		os << "/" << r.den;
	}
	os << "\n";
	return os;
}

std::istream& operator>>(std::istream& is, Rational& r) {
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
	return is;
}

Rational add(int i, Rational r){
	Rational r2(i, 1);
	return r2.add(r);
}

Rational sub(int i, Rational r){
	Rational r2(i, 1);
	return r2.sub(r);
}

Rational mul(int i, Rational r){
	Rational r2(i, 1);
	return r2.mul(r);
}

Rational div(int i, Rational r){
	Rational r2(i, 1);
	return r2.div(r);
}

Rational operator+(int i, Rational r){
	Rational r2(i, 1);
	return r2+r;
}

Rational operator-(int i, Rational r){
	Rational r2(i, 1);
	return r2-r;
}

Rational operator*(int i, Rational r){
	Rational r2(i, 1);
	return r2*r;
}

Rational operator/(int i, Rational r){
	Rational r2(i, 1);
	return r2/r;
}
