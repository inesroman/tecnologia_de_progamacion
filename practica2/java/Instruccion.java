/*
* File: Instruccion.java
* Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
* Fecha: 03/03/2023
*/
import java.util.*;

abstract class Instruccion {
    String nombre;

    Instruccion() {}

    public String listarse() {
        return nombre;
    }

    abstract int ejecutarse(Deque<Integer> pila);
}