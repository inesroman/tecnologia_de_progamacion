# Práctica 3: Paquetería - Documentación
## Objetivos

En esta práctica, se busca aprender a combinar la herencia y la programación genérica, maximizando la reutilización de código. La implementación se realiza en un lenguaje orientado a objetos, eligiendo entre C++ o Java.

## 1. Productos, Contenedores, Camiones
### 1.1. Planteamiento

Una empresa de paquetería transporta productos entre ciudades, gestionando productos, contenedores y camiones. Los productos tienen volumen y peso, los contenedores tienen capacidad y pueden contener productos o incluso otros contenedores, y los camiones transportan cargas.
### 1.2. Tareas
- Diseñar clases: Producto, Contenedor, Carga, Camion.
- Métodos comunes: nombre(), volumen(), peso().
- Implementar el método guardar(??? elemento) en Contenedor y Camion.
- Mostrar representación textual de objetos.

## 2. Productos Especiales
### 2.1. Planteamiento

Introducir productos especiales: seres vivos y productos tóxicos. Se deben permitir contenedores específicos para estas categorías.
### 2.2. Tareas

- Modificar clases: Producto, SerVivo, Toxico, Carga, Contenedor.
- Crear contenedores específicos para seres vivos y productos tóxicos.
- Modificar método guardar(??? elemento) para validar tipos.

## 3. Pruebas

Se deben realizar pruebas exhaustivas de las clases generadas. Se proporciona un archivo (main.cc o Main.java) para probar la biblioteca. La biblioteca debe compilar sin errores con este archivo principal, sin necesidad de modificaciones.
