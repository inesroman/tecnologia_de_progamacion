/*
* File: Suma.java
* Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
* Fecha: 03/03/2023
*/
class Suma extends Programa {
    
    Suma() {
        total = 4;
        instrucciones = new Instruccion[4];
        instrucciones[0] = new Read();
        instrucciones[1] = new Read();
        instrucciones[2] = new Add();
        instrucciones[3] = new Write();
    }
    
}
