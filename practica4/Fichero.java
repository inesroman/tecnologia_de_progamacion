//----------------------------------------------------
// File: Fichero.java
// Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
// Fecha: 04/04/2023
//----------------------------------------------------

public class Fichero extends Nodo {
    private int size;

    public Fichero(String name, int size) {
        super(name);
        this.size = size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public int getSize(int n) {
        return this.size;
    }
}
