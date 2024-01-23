/*
* File: programa.cc
* Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
* Fecha: 03/03/2023
*/
#include "programa.h"

// Constructor
Programa::Programa() { total = 0;}
// Destructor
Programa::~Programa() {
    for(int i = 0; i < total; i++)
        delete instrucciones[i];
    delete instrucciones;
}
// Metodos
void Programa::listarse() const {
    int aux = 0;
    while(aux < total){
        cout << instrucciones[aux]->listarse() << endl;
        aux++;
    }
}

void Programa::ejecutarse() const {
    stack<int> pila;
    int n, i = 0;
    while(i < total){
        n = instrucciones[i]->ejecutarse(pila);
        if( n >= 0){
            i = n;
        }else{
            i++;
        }
    }
}

CuentaAtras::CuentaAtras() :Programa(){
    total = 7;
    instrucciones = new Instruccion*[7];
    instrucciones[0] = new Read();
    instrucciones[1] = new Dup();
    instrucciones[2] = new Write();
    instrucciones[3] = new Push(-1);
    instrucciones[4] = new Add();
    instrucciones[5] = new Dup();
    instrucciones[6] = new Jumpif(1);
}

Factorial::Factorial() :Programa(){
    total = 14;
    instrucciones = new Instruccion*[14];
    instrucciones[0] = new Push(1);
    instrucciones[1] = new Read();
    instrucciones[2] = new Swap();
    instrucciones[3] = new Over();
    instrucciones[4] = new Mul();
    instrucciones[5] = new Swap();
    instrucciones[6] = new Push(-1);
    instrucciones[7] = new Add();
    instrucciones[8] = new Dup();
    instrucciones[9] = new Push(-2);
    instrucciones[10] = new Add();
    instrucciones[11] = new Jumpif(2);
    instrucciones[12] = new Swap();
    instrucciones[13] = new Write();
}

Suma::Suma() :Programa(){
    total = 4;
        instrucciones = new Instruccion*[4];
        instrucciones[0] = new Read();
        instrucciones[1] = new Read();
        instrucciones[2] = new Add();
        instrucciones[3] = new Write();
}
