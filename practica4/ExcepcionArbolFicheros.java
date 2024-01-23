//----------------------------------------------------
// File: Exception.java
// Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
// Fecha: 04/04/2023
//----------------------------------------------------

public class ExcepcionArbolFicheros extends Exception {
    String message;

    public ExcepcionArbolFicheros() {
        this.message = "message";
    }

    public String toString() {
        return message;
    }
}