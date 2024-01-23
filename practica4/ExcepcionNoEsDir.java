//----------------------------------------------------
// File: ExceptionNoExisteDir.java
// Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
// Fecha: 04/04/2023
//----------------------------------------------------

public class ExcepcionNoEsDir extends ExcepcionArbolFicheros {
    

    public ExcepcionNoEsDir(String nombre) {
        super.message = "El nodo de nombre '" + nombre + "' no es un directorio";
    }

    public String toString() {
        return message;
    }
}