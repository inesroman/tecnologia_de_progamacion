//------------------------------------------------------------------------------
// File:   contenedor.h
// Autoras: Inés Román 820731, Alicia Lázaro 820574
// Date:   18/03/2023
//------------------------------------------------------------------------------
#pragma once
#include "item.h"
#include "almacen.h"

template <class T>
class Contenedor : public Carga, public Almacen<T> {
public:
    Contenedor(double volumen) 
        : Item("Contenedor", volumen, 0.0),
        Carga("Contenedor", volumen, 0.0), 
        Almacen<T>("Contenedor", volumen, 0.0) {}

    string espacio() const override { return "   "; }

};