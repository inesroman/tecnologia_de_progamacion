//----------------------------------------------------
// File: ExceptionNoExisteDir.java
// Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
// Fecha: 04/04/2023
//----------------------------------------------------

public class ExcepcionBucle extends ExcepcionArbolFicheros {
    

    public ExcepcionBucle() {
        super.message = "Se ha producido un exceso de llamadas (10 o mas) para consultar el tamaño de un nodo";
    }

    public String toString() {
        return message;
    }
}