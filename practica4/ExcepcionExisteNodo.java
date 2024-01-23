//----------------------------------------------------
// File: ExceptionExisteDir.java
// Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
// Fecha: 04/04/2023
//----------------------------------------------------

public class ExcepcionExisteNodo extends ExcepcionArbolFicheros {
    

    public ExcepcionExisteNodo(String nombre) {
        super.message = "Ya existe un nodo de nombre '" + nombre + "'";
    }

    public String toString() {
        return message;
    }
}