//----------------------------------------------------
// File: Enlace.java
// Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
// Fecha: 04/04/2023
//----------------------------------------------------

public class Enlace extends Nodo {
    private Nodo pointer;

    public Enlace(String name, Nodo ptr) {
        super(name);
        this.pointer = ptr;
    }
    
    public Nodo getEnlace() {
        return pointer;
    }
    
    public int getSize(int n) {
        try {
            if(n >= 10) {
                throw new ExcepcionBucle(); 
            }
        return pointer.getSize(n+1);
        } catch(ExcepcionBucle e) {
            System.out.println(e.toString());
            return -1;
        }
    }
}
