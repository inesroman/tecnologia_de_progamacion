//----------------------------------------------------
// File: ExceptionNoExisteNodo.java
// Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
// Fecha: 04/04/2023
//----------------------------------------------------

public class ExcepcionNoExisteNodo extends ExcepcionArbolFicheros {
    

    public ExcepcionNoExisteNodo(String nombre) {
        super.message = "No existe el nodo de nombre '" + nombre + "'";
    }

    public String toString() {
        return message;
    }
}