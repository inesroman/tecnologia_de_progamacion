//----------------------------------------------------
// File: ExceptionNoExisteDir.java
// Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
// Fecha: 04/04/2023
//----------------------------------------------------

public class ExcepcionNoExistePadre extends ExcepcionArbolFicheros {
    

    public ExcepcionNoExistePadre(String nombre) {
        super.message = "El directorio '" + nombre + "' no tiene padre";
    }

    public String toString() {
        return message;
    }
}