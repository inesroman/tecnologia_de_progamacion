/*
* File: Read.java
* Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
* Fecha: 03/03/2023
*/
import java.util.*;

class Read extends Instruccion {
    
    Read(){
        nombre = "read";
    }

    public int ejecutarse(Deque<Integer> pila){
        
        int num;
        Scanner teclado = new Scanner(System.in);
        System.out.print("?");
        num = teclado.nextInt();
        pila.push(num);
        return -1;
    }
}
