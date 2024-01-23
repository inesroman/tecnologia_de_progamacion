/*
* File: Jumpif.java
* Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
* Fecha: 03/03/2023
*/
import java.util.*;

class Jumpif extends Instruccion {
    int par;
    Jumpif(int p){
        par = p;
        nombre = "jumpif";
    }

    public int ejecutarse(Deque<Integer> pila){
        int n;
        if(!pila.isEmpty()){
            n = pila.pop();
            if(n < 0){
                return -1;
            }else{
                return par;
            }
        }
        return -1;
    }
}
