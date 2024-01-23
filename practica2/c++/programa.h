/*
* File: programa.h
* Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
* Fecha: 03/03/2023
*/
#pragma once

#include "instruccion.h"
#include <iostream>
#include <stack>

using namespace std;

class Programa {
protected: 
   // Atributos
    Instruccion** instrucciones;
    int total;
public:
    // Constructor
    Programa();
    // Destructor
    ~Programa();
    // Metodos
    void listarse() const;
    void ejecutarse() const;
};

class CuentaAtras: public Programa {

public:
    // Constructor
    CuentaAtras();
};

class Suma: public Programa {

public:
    // Constructor
    Suma();
};

class Factorial: public Programa {

public:
    // Constructor
    Factorial();
};