/*
* File: Programa.java
* Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
* Fecha: 03/03/2023
*/
import java.util.*;

abstract class Programa {
    protected Instruccion[] instrucciones;
    protected int total;

    Programa(){};

    public void listarse() {
        for(int i = 0; i < total; i++)
        System.out.println(instrucciones[i].listarse());
    }

    public void ejecutarse() {
        Deque<Integer> pila = new ArrayDeque<Integer>();
        int n, i = 0;
        while(i < total){
            n = instrucciones[i].ejecutarse(pila);
            if(n >= 0){
                i = n;
            }else{
                i++;
            }
        }
    }

}