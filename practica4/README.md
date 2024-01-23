# Práctica 4: Sistema de Ficheros en Memoria

## 1. Sistemas de Ficheros en Memoria
### 1.1. Planteamiento
Se busca implementar un sistema de ficheros de tipo ramdisk, que represente un sistema de ficheros en memoria.

### 1.2. Tareas
- Diseñar clases: Directorio, Fichero, Enlace.
- Representar el sistema de ficheros mediante una estructura de árbol de directorios.
- Implementar acciones sobre el árbol de directorios: crear/borrar ficheros, directorios, enlaces, entre otros.

## 2. Intérprete de Comandos
Se implementará un intérprete de comandos o shell que trabaje con el sistema de ficheros mencionado. El shell se representará como una clase con métodos que simulan comandos de un sistema de archivos.

### 2.1. Acciones sobre la Ruta Activa
Métodos implementados en la clase Shell:
```
        pwd(): Devuelve la ruta completa de forma textual.
        ls(): Devuelve un listado con el nombre de todos los nodos en la ruta actual.
        du(): Devuelve un listado con el nombre y tamaño de los nodos en la ruta actual.
        vi(String name, int size): Edita un fichero cambiando su tamaño.
        mkdir(String name): Crea un directorio en el directorio activo.
        cd(String path): Cambia la ruta activa a otro directorio.
        ln(String path, String name): Crea un enlace simbólico en el directorio actual.
        stat(String path): Devuelve el tamaño del nodo referenciado por la ruta.
        rm(String path): Elimina un nodo (fichero, enlace o directorio).
```

## 3. Gestión de Situaciones Excepcionales

Se implementa una jerarquía de excepciones que gestionan casos excepcionales para cada acción sobre la ruta activa.
