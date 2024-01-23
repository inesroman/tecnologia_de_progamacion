/*
* File: instruccion.h
* Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
* Fecha: 03/03/2023
*/
#pragma once
#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Instruccion {
protected:
    // Atributos
    string nombre;
public:
    // Constructor
    Instruccion();
    // Metodos
    virtual string listarse();
    virtual int ejecutarse(stack<int>& pila) = 0;
};

class Add: public Instruccion {
public:
    Add();
    int ejecutarse(stack<int>& pila) override;
};

class Dup: public Instruccion {
public:
    Dup();
    int ejecutarse(stack<int>& pila) override;
};

class Jumpif: public Instruccion {
    int par;
public:
    Jumpif(int p);
    int ejecutarse(stack<int>& pila) override;
};

class Mul: public Instruccion {
public:
    Mul();
    int ejecutarse(stack<int>& pila) override;
};

class Over: public Instruccion {
public:
    Over();
    int ejecutarse(stack<int>& pila) override;
};

class Push: public Instruccion {
    int par;
public:
    Push(int p);
    int ejecutarse(stack<int>& pila) override;
};

class Read: public Instruccion {
public:
    Read();
    int ejecutarse(stack<int>& pila) override;
};

class Swap: public Instruccion {
public:
    Swap();
    int ejecutarse(stack<int>& pila) override;
};

class Write: public Instruccion {
public:
    // Constructor
    Write();
    int ejecutarse(stack<int>& pila) override;
};
