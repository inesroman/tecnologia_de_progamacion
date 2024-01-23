//------------------------------------------------------------------------------
// File:   camion.h
// Autoras: Inés Román 820731, Alicia Lázaro 820574
// Date:   18/03/2023
//------------------------------------------------------------------------------
#pragma once
#include "item.h"
#include "almacen.h"

class Camion : public Almacen<Carga> {
public:
    Camion(double volumen) 
        : Item("Camion", volumen, 0.0),
        Almacen("Camion", volumen, 0.0) {}
        
    string espacio() const override { return " ";}
};
