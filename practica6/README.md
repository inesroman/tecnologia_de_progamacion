# Práctica 6: Árboles Binarios en Haskell
## Objetivos
En esta práctica, el objetivo es comprender la definición y manejo de tipos y estructuras de datos en Haskell, así como introducir los mecanismos de las clases y la programación genérica. Trabajaremos con árboles binarios de búsqueda (BST) y desarrollaremos diversas funciones para manipularlos.

## 1. Árboles Binarios
Define en Haskell los tipos necesarios para implementar una estructura de datos que represente un árbol binario genérico pero homogéneo. Implementa funciones para construir y visualizar árboles, así como para determinar su tamaño.

### 1.1. Tarea
```
    empty: Devuelve un árbol vacío, sin ningún elemento.
    leaf x: Devuelve un árbol que consta de una única hoja que contiene el elemento x.
    tree x lc rc: Devuelve un árbol que contiene en la raíz el elemento x, con hijo izquierdo lc e hijo derecho rc.
    size t: Devuelve el número de elementos del árbol.
```
Asegúrate de que los árboles puedan ser visualizados por pantalla utilizando la función print, implementando la instancia de la clase Show para tu tipo de árbol.

### 1.2. Ejemplo de Uso

```
testTree = tree 1 (tree 2 (leaf 3) (leaf 4)) (tree 5 empty (leaf 6))
main = print testTree
```
Salida:
```
1
|− 2
|− 3
|− 4
|− 5
|− <>
|− 6
```

## 2. Construcción de Árboles Binarios de Búsqueda (BST)
Implementa funciones para trabajar con árboles binarios de búsqueda, asegurando que se mantenga la propiedad de orden.

### 2.1. Tarea
```
    add t x: Añade el elemento x al árbol t, devolviendo el árbol binario de búsqueda resultante.
    build xs: Construye un árbol binario de búsqueda a partir de los elementos de una lista xs.
```

## 3. Árboles Binarios de Búsqueda Equilibrados
Implementa una función que construya un árbol binario de búsqueda equilibrado a partir de los elementos de una lista.

### 3.1. Tarea
```
    buildBalanced xs: Construye un árbol binario de búsqueda equilibrado ordenando la lista y dividiéndola por la mediana.
```

## 4. Recorrido de Árboles Binarios
Implementa funciones para realizar tres tipos de recorridos en profundidad en un árbol binario.

### 4.1. Tarea
```
    preorder t, postorder t, inorder t: Devuelven listas con los elementos del árbol en el orden correspondiente.
```

## 5. Búsquedas
Implementa una función que realice búsquedas en un árbol binario de búsqueda.

### 5.1. Tarea
```
    between t xmin xmax: Busca en el árbol binario de búsqueda t y devuelve una lista con elementos entre xmin y xmax (inclusive).
```

## 6. Pruebas
Se proporciona un archivo BinaryTreeTest.hs para probar las funciones solicitadas en la práctica. Asegúrate de que tus funciones compilen con este archivo de pruebas.
