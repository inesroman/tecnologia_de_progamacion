//----------------------------------------------------
// File: Directorio.java
// Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
// Fecha: 04/04/2023
//----------------------------------------------------

import java.util.ArrayList;

public class Directorio extends Nodo{
    private ArrayList<Nodo> list;

    public Directorio(String name) {
        super(name);
        list = new ArrayList<Nodo>();
    }

    public int getSize(int n){
        try {
            if(n >= 10) {
                throw new ExcepcionBucle(); 
            }
            int s = 0;
            for(int i = 0; i < list.size(); i++) {
               s += list.get(i).getSize(n+1); 
            }
            return s;
        } catch(ExcepcionBucle e) {
            System.out.println(e.toString());
            return -1;
        }
        
    }

    public void add(Nodo n) {
        list.add(n);
    }

    public void remove(String name) {
        for(int i = 0; i < list.size(); i++) {
            if(list.get(i).getName().equals(name)) 
                list.remove(list.get(i));
        }
    }

    public void clear() {
        list.clear();
    }

    public ArrayList<Nodo> getContent() {
        return this.list;
    }

    public boolean isEmpty() {
        return list.isEmpty(); 
    }

    public boolean contains(String name) {
        for(int i = 0; i < list.size(); i++) {
            if(list.get(i).getName().equals(name)) 
                return true;
        }
        return false;
    }

    public String getListOfContents() {
        String s = "";
        for(int i = 0; i < list.size(); i++) {
           s += list.get(i).getName() + " " ;
           if(i < (list.size() - 1)) s += "\n" ;
        }
        return s;
    }

    public String getListOfContentsAndSize() {
        String s = "";
        for(int i = 0; i < list.size(); i++) {
           s += list.get(i).getName() + " " + list.get(i).getSize(0); 
           if(i < (list.size() - 1)) s += "\n" ;
        }
        return s;
    }

    public int getIndexOf(String name) {
        for(int i = 0; i < list.size(); i++) {
            if(list.get(i).getName().equals(name)) {
                return i;              
            }    
        }
        return -1;
    }
}
