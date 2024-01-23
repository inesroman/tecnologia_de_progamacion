/*
* File: Add.java
* Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
* Fecha: 03/03/2023
*/
import java.util.*;

class Add extends Instruccion {
    Add(){
        nombre = "add";
    }

    public int ejecutarse(Deque<Integer> pila){
        int a, b;
        if(pila.size() > 1){
            a = pila.pop();
            b = pila.pop();
            pila.push(a+b);
        }
        return -1;
    }
}