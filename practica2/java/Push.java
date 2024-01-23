/*
* File: Push.java
* Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
* Fecha: 03/03/2023
*/
import java.util.*;

class Push extends Instruccion {
    int par;
    Push(int p){
        par = p;
        nombre = "push";
    }

    public int ejecutarse(Deque<Integer> pila){
        pila.push(par);
        return -1;
    }
}
