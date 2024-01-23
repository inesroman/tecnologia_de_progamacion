//----------------------------------------------------
// File: ExceptionNoExisteDir.java
// Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
// Fecha: 04/04/2023
//----------------------------------------------------

public class ExcepcionNoExisteDir extends ExcepcionArbolFicheros {
    

    public ExcepcionNoExisteDir(String nombre) {
        super.message = "No existe el directorio de nombre '" + nombre + "'";
    }

    public String toString() {
        return message;
    }
}