/*
* File: Over.java
* Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
* Fecha: 03/03/2023
*/
import java.util.*;

class Over extends Instruccion {
    Over(){
        nombre = "over";
    }

    public int ejecutarse(Deque<Integer> pila){
        int a, b;
        if(pila.size() > 1){
            a = pila.pop();
            b = pila.pop();
            pila.push(b);
            pila.push(a);
            pila.push(b);
        }
        return -1;
    }
}