//----------------------------------------------------
// File: ExceptionExisteDirOLink.java
// Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
// Fecha: 04/04/2023
//----------------------------------------------------

public class ExcepcionExisteDirOLink extends ExcepcionArbolFicheros {
    

    public ExcepcionExisteDirOLink(String nombre) {
        super.message = "Ya existe un enlace o directorio de nombre '" + nombre + "'";
    }

    public String toString() {
        return message;
    }
}