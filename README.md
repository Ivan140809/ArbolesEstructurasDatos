# Arboles - Estructuras de Datos. 

Implementación de cinco tipos de estructuras de árbol en C++: **Árbol General**, **Árbol Binario**, **Árbol AVL**, **Árbol Rojinegro** y **Árbol Montículo**.

## 📋 Tabla de Contenidos

- [Descripción](#descripción)
- [Tipos de Árboles](#tipos-de-árboles)
- [Estructura del Proyecto](#estructura-del-proyecto)
- [Operaciones Disponibles](#operaciones-disponibles)
- [Ejemplos de Uso](#ejemplos-de-uso)
- [Compilación y Ejecución](#compilación-y-ejecución)
- [Casos de Uso](#casos-de-uso)

## Descripción

Este repositorio contiene la implementación detallada de cinco estructuras de árbol fundamentales en C++. Cada tipo de árbol tiene sus propias características, ventajas y casos de uso específicos. El proyecto incluye ejemplos de ejecución para cada estructura, con una implementación y logicas determinadas ayudando a comprender las operaciones de los elementos asociados a los arboles.

##  Tipos de Árboles

### Arbol General

**Archivos:** `ArbolGeneral.h`, `ArbolGeneral.hxx`, `NodoGeneral.h`, `NodoGeneral.hxx` en directorio `Arbol_General`

Un árbol donde cada nodo puede tener **N hijos** sin un limite establecido y con comportamiento general, arbol orientado a ser una generalización de los demas arboles para su implemetacion. 

**Caracteristicas del arbol:**
- Estructura principalmente jerárquica
- Cada nodo almacena una lista de hijos
- Ideal para datos jerárquicos complejos

**Aplicaciones del arbol general:**
- Sistemas de archivos
- Organigramas empresariales
- Árboles genealógicos
- Menús de aplicaciones

**Operaciones principales:**
```cpp
ArbolGeneral<int> ag(1);           // Crear con raíz
ag.insertarNodo(1, 2);             // Insertar hijo
ag.eliminarNodo(2);                // Eliminar nodo
ag.preOrden();                      // Recorridos disponibles
```

### Arbol Binario de Búsqueda
**Archivos:** `Arbolbinario.h`, `Arbolbinario.hxx`, `NodoBinario.h`, `NodoBinario.hxx` en directorio `Arbol_binario`
 
Árbol donde cada nodo tiene máximo 2 hijos (izquierdo y derecho) y que cumple propiedad de menores a la izquierda mayores a la derecha.
 
**Caracteristicas:**
- Propiedad de arboles binarios: izquierda < raíz < derecha
- Busqueda eficiente en árboles balanceados
- Puede desbalancearse en peor caso nececitando otros tipos de arboles para mantenerlo bonito
 
**Complejidad:**
- Insercion peor caso O(n)
- Busqueda peor caso: O(n)
- Eliminacion peor caso: O(n)
 
**Operaciones principales:**
```cpp
ArbolBinario<int> ab;
ab.insertar(5);                    // Insertar elemento
ab.eliminar(3);                    // Eliminar elemento
ab.buscar(7);                      // Buscar elemento
ab.InOrden();                      // Recorrido ordenado
```
### Arbol AVL 
**Archivos:** `ArbolAVL.h`, `ArbolAVL.hxx`, `NodoAVL.h`, `NodoAVL.hxx` en directorio `Arbol_AVL` en el directorio `Arbol_AVL`
Arbol binario de búsqueda automáticamente balanceado mediante rotaciones al operar con insercion, eliminacion y busqueda garantizando complejidad en peor caso O(log n).
 
**Características:**
- Factor de balance en cada nodo: -1, 0 o 1
- Garantiza O(log n) en todas las operaciones
- Realiza rotaciones al insertar/eliminar
 
**Tipos de Rotaciones:**
- `rotarDerecha()` - Rotación simple derecha
- `rotarIzquierda()` - Rotación simple izquierda
- `rotarIzqDer()` - Rotación doble izq-der
- `rotarDerIzq()` - Rotación doble der-izq
 
**Operaciones principales:**
```cpp
ArbolAVL<int> avl;
avl.insertar(50);                  // Insertar (auto-balancea)
avl.eliminar(30);                  // Eliminar (auto-balancea)
int h = avl.altura();              // Obtener altura
```
 
**Ventajas:**
- Garantía de complejidad O(log n)
- Equilibrio perfecto entre nodos
 
**Desventajas:**
- Mas rotaciones que un rojinegro
- Implementación más compleja al no estar estandarizada
### Arbol RojiNegro
**Archivos:** `ArbolRN.h`, `ArbolRN.hxx` en el directorio `Arbol_RN`
Arbol binario balanceado con propiedades de color (rojo/negro).
 
**Propiedades:**
- Cada nodo es rojo o negro
- La raiz es siempre negra
- No hay dos nodos rojos consecutivos
- Todos los caminos hoja tienen el mismo número de nodos negros
 
**Caracteristicas:**
- Menos rotaciones que AVL
- Rebalanceo más simple
- O(log n) garantizado
 
**Aplicaciones:**
- std::set en C++
- std::map en C++
- Sistemas de archivos Linux
 
**Operaciones principales:**
```cpp
ArbolRN<int> rn;
rn.insertar(50);                   // Insertar con propiedades
rn.eliminar(30);                   // Eliminar manteniendo propiedades
rn.InOrden();                      // Recorrido
```
 ### Arbol Montículo (Heap)
**Archivos:** `ArbolMonticulo.h`, `ArbolMonticulo.hxx` en el directorio `Arbol_Monticulo` 
Arbol binario completamente lleno con propiedad heap.
 
**Caracteristicas:**
- Arbol binario perfecto (niveles completos)
- Propiedad heap: padre ≥ hijos (max-heap)
- Implementación tipica: array contiguo
 
**Aplicaciones:**
- Priority queues
- Algoritmo Heapsort
- Algoritmo de Dijkstra
- Algoritmo de Huffman
 
**Operaciones principales:**
```cpp
ArbolMonticulo<int> heap;
heap.insertar(50);                 // Insertar (mantiene propiedad)
heap.eliminar(30);                 // Eliminar
list<int> lista;
heap.InOrden(lista);               // Obtener elementos
```
 
**Complejidad:**
- Inserción: O(log n)
- Eliminación: O(log n)
- Acceso a máximo: O(1)
 
---
   
## Estructura de archivos
 
```
ArbolesEstructurasDatos/
│
├── main.cpp # Programa principal de pruebas
│
├── Árbol General
│   ├── ArbolGeneral.h
│   ├── ArbolGeneral.hxx
│   ├── NodoGeneral.h
│   └── NodoGeneral.hxx
│
├── Árbol Binario
│   ├── Arbolbinario.h
│   ├── Arbolbinario.hxx
│   ├── NodoBinario.h
│   └── NodoBinario.hxx
│
├── Árbol AVL
│   ├── ArbolAVL.h
│   ├── ArbolAVL.hxx
│   ├── NodoAVL.h
│   └── NodoAVL.hxx
│
├── Árbol Rojo-Negro
│   ├── ArbolRN.h
│   └── ArbolRN.hxx
│
└── Árbol Montículo
    ├── ArbolMonticulo.h
    └── ArbolMonticulo.hxx
```
 
 ## ⚙️ Operaciones Disponibles
 
### Operaciones Comunes
 
| Operación | Descripción | Complejidad |
|-----------|-------------|-------------|
| `insertar(T)` | Añade un elemento al árbol | O(log n) |
| `eliminar(T)` | Elimina un elemento del árbol | O(log n) |
| `buscar(T)` | Busca un elemento | O(log n) |
| `altura()` | Retorna la altura del arbol | O(n) |
| `tamano()` | Cuenta el número de nodos | O(n) |
| `esVacio()` | Verifica si el árbol está vacío | O(1) |
 
### Recorridos Disponibles
 
| Recorrido | Orden |
|-----------|-------|
| `PreOrden()` | Raiz → Izq → Der | 
| `InOrden()` | Izq → Raíz → Der |
| `PosOrden()` | Izq → Der → Raíz |
| `NivelOrden()` | Por niveles |

## 👤 Autor
Ivan140809
 
## 📄 Licencia
Este proyecto es de código abierto y puede ser utilizado con fines educativos.
