# Práctica 5: Gráficos de Tortuga y Sistemas de Lindenmayer en Haskell

## Objetivos
Esta práctica tiene como objetivos practicar las técnicas básicas de definición de funciones en un lenguaje funcional, diseñar funciones de forma recursiva para el tratamiento de listas, y conocer las funciones de orden superior básicas para el tratamiento de listas.

## 1. Gráficos de Tortuga
El sistema de Gráficos de Tortuga es un entorno programable de dibujo vectorial que permite generar gráficos 2D basados en líneas poligonales mediante el desplazamiento de una tortuga. En esta práctica, trabajaremos con una implementación simplificada en Haskell.
- '>': avanza la tortuga hacia delante
- '+': gira la tortuga hacia la derecha (sentido horario)
- '-': gira la tortuga hacia la izquierda (sentido anti–horario)

### 1.1. Tarea
Implementa una función Haskell llamada tplot que, a partir del estado inicial de la tortuga, genere la lista de puntos que corresponde al gráfico generado por una secuencia de comandos almacenados en una cadena. Utiliza esta función para generar distintas figuras geométricas (triángulo, cuadrado, círculo) y grábalas en formato SVG mediante las funciones proporcionadas.

Ejemplo:

```
figura = tplot (1, 90, (0,0), 90) ">+>+>+>+"
savesvg "cuadrado" figura
```

## 2. Sistemas de Lindenmayer (L-Systems)
Los Sistemas de Lindenmayer o L–Systems son gramáticas formales utilizadas para modelar de forma recursiva la forma de elementos naturales, como plantas o copos de nieve, mediante un sistema de gráficos de tortuga.

### 2.1. Tarea
Implementa la función lsystem, que a partir de una función que define las reglas de re-escritura, el axioma inicial y el número de veces que se deben aplicar, devuelve la cadena resultante.

Ejemplo:
```
rulesArrowhead :: Char -> String
rulesArrowhead 'F' = "G-F-G"
rulesArrowhead 'G' = "F+G+F"
rulesArrowhead c   = [c]

lsystem :: (Char -> String) -> String -> Int -> String
lsystem rules axiom iterations

-- Ejemplo de uso:
lsystem rulesArrowhead "F" 3
```
### 2.2. Implementación de Reglas

Implementa diversas versiones de la función rules, que definan distintos L-Systems.
