# Máquina Virtual de Pila - Práctica 2

Esta práctica implementa una máquina virtual de tipo pila en C++ y Java para simular un microcontrolador de pila. El objetivo principal es utilizar la herencia para maximizar la reutilización de código y diseñar jerarquías de herencia que permitan el polimorfismo por inclusión.

## Contenido del Proyecto

### 1. Máquina de Pila

Se desarrolla una máquina virtual que emula un microcontrolador de pila. El microcontrolador tiene un juego de instrucciones para realizar operaciones sobre una pila.

### 2. Implementación de la Máquina Virtual

Se desarrollan las piezas fundamentales de la máquina de pila, como la representación de la pila, las instrucciones y el programa. Se utiliza herencia y polimorfismo por inclusión para representar las instrucciones como una clase base con clases derivadas para cada instrucción específica.

### 3. Primer Programa: Suma de Dos Números

Se implementa un programa simple que calcula la suma de dos números introducidos por el usuario. El formato del programa se presenta así:

```
0 read
1 read
2 add
3 write
```
Se introducen las instrucciones `add`, `read`, y `write` al juego de instrucciones.

### 4. Cuenta Atrás

Se crea un programa que solicita un número al usuario y muestra una cuenta atrás desde ese número hasta cero. El formato del programa se presenta así:

```
0 read
1 dup
2 write
3 push -1
4 add
5 dup
6 jumpif 1

```

Se introducen las instrucciones `push`, `dup`, y `jumpif`.

### 5. Factorial

Se desarrolla un programa que calcula el factorial de un número ingresado por el usuario. El formato del programa se presenta así:

```
0 push 1
1 read
2 swap
3 over
4 mul
5 swap
6 push -1
7 add
8 dup
9 push -2
10 add
11 jumpif 2
12 swap
13 write

```
Se agregan las instrucciones `mul`, `swap`, y `over` al juego de instrucciones.
