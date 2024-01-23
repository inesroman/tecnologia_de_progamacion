/*
* File: Add.java
* Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
* Fecha: 03/03/2023
* Coms: javac Main.java para compilar, después java Main
*/
public class Main{
    public static void main(String[] args) {  
        Programa[] p = new Programa[3];
        p[0] = new Suma();
        p[1] = new CuentaAtras();
        p[2] = new Factorial();

        System.out.println("------------------------------------------");
        System.out.println("                   SUMA                   ");
        System.out.println("------------------------------------------");
        System.out.println("Instrucciones:");
        p[0].listarse();
        System.out.println();
        System.out.println("Ejecución:");
        p[0].ejecutarse();
        
        System.out.println("------------------------------------------");
        System.out.println("                CUENTA ATRÁS              ");
        System.out.println("------------------------------------------");
        System.out.println("Instrucciones:");
        p[1].listarse();
        System.out.println();
        System.out.println("Ejecución:");
        p[1].ejecutarse();
        
        System.out.println("------------------------------------------");
        System.out.println("                 FACTORIAL                ");
        System.out.println("------------------------------------------");
        System.out.println("Instrucciones:");
        p[2].listarse();
        System.out.println();
        System.out.println("Ejecución:");
        p[2].ejecutarse();
    }
}
