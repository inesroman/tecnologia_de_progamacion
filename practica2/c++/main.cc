/*
* File: instruccion.cc
* Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
* Fecha: 03/03/2023
* Coms: make para compilar, después ./main
*/
#include <iostream>
#include "programa.h"

int main(){
    Programa* p[3];
    p[0] = new Suma();
    p[1] = new CuentaAtras();
    p[2] = new Factorial();

    cout << "------------------------------------------" << endl;
    cout << "                   SUMA                   " << endl;
    cout << "------------------------------------------" << endl;
    cout << "Instrucciones:" << endl;
    p[0]->listarse();
    cout << endl;
    cout << "Ejecución:" << endl;
    p[0]->ejecutarse();
    
    cout << "------------------------------------------" << endl;
    cout << "                CUENTA ATRÁS              " << endl;
    cout << "------------------------------------------" << endl;
    cout << "Instrucciones:" << endl;
    p[1]->listarse();
    cout << endl;
    cout << "Ejecución:" << endl;
    p[1]->ejecutarse();
    
    cout << "------------------------------------------" << endl;
    cout << "                 FACTORIAL                " << endl;
    cout << "------------------------------------------" << endl;
    cout << "Instrucciones:" << endl;
    p[2]->listarse();
    cout << endl;
    cout << "Ejecución:" << endl;
    p[2]->ejecutarse();


    for(int i=0;i<3;i++)
        delete p[i];
    return 0;
}