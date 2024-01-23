//------------------------------------------------------------------------------
// File:   almacen.h
// Autoras: Inés Román 820731, Alicia Lázaro 820574
// Date:   18/03/2023
//------------------------------------------------------------------------------
#pragma once
#include "item.h"
#include <vector>

template <class T>
class Almacen : virtual public Item {
protected:
    vector<T*> vec;

public:
    Almacen(string nombre, double volumen, double peso) 
    : Item(nombre, volumen, peso) {}

    double peso() const override {
        double p = 0.0;
        for (auto i : this->vec) {
            p += i->peso();
        }
        return p;
    }

    bool guardar(T* p) {
        double v = 0.0;               
        for (auto i : vec) {
            v += i->volumen();
        }
        if ((v + p->volumen()) <= vol) {
           vec.push_back(p);
           return true;
        }
        return false;
    }

    virtual string espacio() const = 0;

    string to_string() const override {
        stringstream s;
        s << nom << " [" << volumen(); 
        s << " m3] [" << peso() << " kg]" << endl;
        for (auto i : vec) {
            s << espacio(); 
            s << i->to_string();
            if (i != vec.back()) {
                s << endl;
            }
        }
        return s.str();
    }
    
    friend ostream& operator<<(ostream& os, const Almacen& a) {
        os << a.to_string();
        return os;
    }
};
