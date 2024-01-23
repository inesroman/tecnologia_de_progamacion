/*
* File: CuentaAtras.java
* Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
* Fecha: 03/03/2023
*/
class CuentaAtras extends Programa {
    
    CuentaAtras(){
        total = 7;
        instrucciones = new Instruccion[7];
        instrucciones[0] = new Read();
        instrucciones[1] = new Dup();
        instrucciones[2] = new Write();
        instrucciones[3] = new Push(-1);
        instrucciones[4] = new Add();
        instrucciones[5] = new Dup();
        instrucciones[6] = new Jumpif(1);
    }
    
}