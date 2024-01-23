/*
* File: Write.java
* Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
* Fecha: 03/03/2023
*/
import java.util.*;

class Write extends Instruccion {
   
    Write(){
        nombre = "write";
    }

    public int ejecutarse(Deque<Integer> pila){
        int num;
        if(!pila.isEmpty()){
            num = pila.pop();
            System.out.println(num);
        }
        return -1;
    }
}