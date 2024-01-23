/*
* File: instruccion.cc
* Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
* Fecha: 03/03/2023
*/
#include "instruccion.h"

// Constructor
Instruccion::Instruccion() {}
// Metodos
string Instruccion::listarse() {
    return nombre;
}

Add::Add() {
    nombre = "add";
}
int Add::ejecutarse(stack<int>& pila){
    int a, b;
    if(pila.size() > 1){
        a = pila.top();
        pila.pop();
        b = pila.top();
        pila.pop();
        pila.push(a + b);
    }
    return -1;
}

Dup::Dup() {
    nombre = "dup";
}
int Dup::ejecutarse(stack<int>& pila){
    int a;
    if(!pila.empty()){
        a = pila.top();
        pila.push(a);
    }
    return -1;
}

Jumpif::Jumpif(int p) : par(p){
    nombre = "jumpif";
}
int Jumpif::ejecutarse(stack<int>& pila){
    int n;
    if(!pila.empty()){
        n = pila.top();
        pila.pop();
        if(n < 0){
            return -1;
        }else{
            return par;
        }
    }
    return -1;
}

Mul::Mul() {
    nombre = "mul";
}
int Mul::ejecutarse(stack<int>& pila){
    int a, b;
    if(pila.size() > 1){
        a = pila.top();
        pila.pop();
        b = pila.top();
        pila.pop();
        pila.push(a * b);
    }
    return -1;
}

Over::Over() {
    nombre = "over";
}
int Over::ejecutarse(stack<int>& pila){
    int a, b;
    if(pila.size() > 1){
        a = pila.top();
        pila.pop();
        b = pila.top();
        pila.pop();
        pila.push(b);
        pila.push(a);
        pila.push(b);
    }
    return -1;
}

Push::Push(int p) : par(p) {
    nombre = "push";
}
int Push::ejecutarse(stack<int>& pila){
    pila.push(par);
    return -1;
}

Read::Read(): Instruccion() {
    nombre = "read";
}
int Read::ejecutarse(stack<int>& pila){
    int a;
    cout << "? ";
    cin >> a;
    pila.push(a);
    return -1;
}

Swap::Swap() {
    nombre = "swap";
}
int Swap::ejecutarse(stack<int>& pila){
    int a, b;
    if(pila.size() > 1){
        a = pila.top();
        pila.pop();
        b = pila.top();
        pila.pop();
        pila.push(a);
        pila.push(b);
    }
    return -1;
}

Write::Write() {
    nombre = "write";
}
int Write::ejecutarse(stack<int>& pila){
    int a;
    if(!pila.empty()){
        a = pila.top();
        pila.pop();
        cout << a << endl;
    }
    return -1;
}
