//----------------------------------------------------
// File: Nodo.java
// Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
// Fecha: 04/04/2023
//----------------------------------------------------

public abstract class Nodo {
    protected String name;
    
    public Nodo(String name) { 
        this.name = name; 
    }
    
    public String getName() { 
        return name; 
    }
    
    public abstract int getSize(int n);
}
