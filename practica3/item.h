//------------------------------------------------------------------------------
// File:   item.h
// Autoras: Inés Román 820731, Alicia Lázaro 820574
// Date:   18/03/2023
//------------------------------------------------------------------------------
#pragma once
#include <sstream>
#include <string>

using namespace std;

class Item {
protected:
    string nom;
    double vol;
    double pes;

public:
    Item(const string& nombre, double volumen, double peso) 
        : nom(nombre), vol(volumen), pes(peso) {}
        
    string nombre() const { return nom; }

    double volumen() const { return vol; }

    virtual double peso() const { return pes;}

    virtual string to_string() const {
        stringstream s;
        s << nom << " [" << volumen();
        s << " m3] [" << peso() << " kg]";
        return s.str();
    }

    virtual string tipo() const { return "Carga Estandar";}
};

class Carga : virtual public Item {
public:
    Carga(const string& nombre, double volumen, double peso) 
        : Item(nombre, volumen, peso) {}
};

class Producto : public Carga {
public:
    Producto(const string& nombre, double volumen, double peso)  
        : Item(nombre, volumen, peso),
        Carga(nombre, volumen, peso) {}
};

class SerVivo : public Item {
public:
    SerVivo(const string& nombre, double volumen, double peso) : Item(nombre, volumen, peso) {}

    string tipo() const override { return "Seres vivos"; }
};

class Toxico : public Item {
public:
    Toxico(const string& nombre, double volumen, double peso) : Item(nombre, volumen, peso) {}

    string tipo() const override { return "Productos tóxicos"; }
};
