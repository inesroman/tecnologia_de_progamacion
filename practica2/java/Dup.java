/*
* File: Dup.java
* Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
* Fecha: 03/03/2023
*/
import java.util.*;

class Dup extends Instruccion {
    Dup(){
        nombre = "Dup";
    }

    public int ejecutarse(Deque<Integer> pila){
        int a;
        if(!pila.isEmpty()){
            a = pila.peek();
            pila.push(a);
        }
        return -1;
    }
}
