# Prueba Práctica: Árboles Binarios de Búsqueda en C++

## Información General

| Campo | Detalle |
|-------|---------|
| **Asignatura** | Estructura de Datos |
| **Tema** | Árboles binarios de búsqueda, recorridos y aplicación práctica |
| **Universidad** | Universidad Técnica de Ambato (UTA) |
| **Facultad** | FISEI |
| **Carrera** | Ingeniería en Software |
| **Lenguaje** | C++ |

## Descripción del Proyecto

Sistema académico para gestionar estudiantes de la UTA mediante un **Árbol Binario de Búsqueda (ABB)** ordenado por cédula. Cada estudiante almacena: cédula, apellidos, nombres, nota final, carrera y nivel.

## Estructura del Proyecto

```
cpp/
├── Estudiante.h    → Estructura de datos del estudiante
├── Nodo.h          → Nodo del árbol (contiene Estudiante + punteros)
├── ArbolBST.h      → Declaración de la clase ArbolBST
├── ArbolBST.cpp    → Implementación de todos los métodos del árbol
└── main.cpp        → Menú interactivo y funciones de entrada/salida
```

## Diseño Orientado a Objetos

El código sigue principios de **POO y modularidad**:

- **`Estudiante.h`**: estructura de datos pura, sin lógica.
- **`Nodo.h`**: nodo del árbol con punteros a hijos izquierdo y derecho.
- **`ArbolBST` (clase)**: encapsula toda la lógica del árbol. Los métodos recursivos son **privados** y los métodos del menú son **públicos**.
- **`main.cpp`**: solo contiene el menú, validaciones de entrada y la función `main()`.

## Funciones Implementadas

| Función | Descripción |
|---------|-------------|
| `insertarEstudiante()` | Inserta un nuevo estudiante en el ABB |
| `buscarEstudiante()` | Busca un estudiante por su cédula |
| `eliminarEstudiante()` | Elimina un estudiante (maneja 3 casos: hoja, 1 hijo, 2 hijos) |
| `recorridoInorden()` | Izquierdo → Raíz → Derecho (orden ascendente por cédula) |
| `recorridoPreorden()` | Raíz → Izquierdo → Derecho |
| `recorridoPostorden()` | Izquierdo → Derecho → Raíz |
| `recorridoPorNiveles()` | BFS nivel por nivel usando `std::queue` |
| `contarEstudiantes()` | Cuenta el total de nodos del árbol |
| `obtenerAltura()` | Calcula la altura del árbol recursivamente |
| `mostrarNotaMayor()` | Encuentra el estudiante con la nota más alta |
| `mostrarNotaMenor()` | Encuentra el estudiante con la nota más baja |
| `listarAprobados()` | Lista estudiantes con nota ≥ 7.0 |
| `listarReprobados()` | Lista estudiantes con nota < 7.0 |

## Menú del Programa

```
1.  Insertar estudiante
2.  Buscar estudiante por cédula
3.  Eliminar estudiante
4.  Recorrido Inorden
5.  Recorrido Preorden
6.  Recorrido Postorden
7.  Recorrido por niveles (BFS)
8.  Contar estudiantes
9.  Calcular altura del árbol
10. Mostrar estudiante con mayor nota
11. Mostrar estudiante con menor nota
12. Mostrar estudiantes aprobados
13. Mostrar estudiantes reprobados
14. Salir
```

## Compilación y Ejecución

```bash
cd cpp/
g++ -o sistema_academico main.cpp ArbolBST.cpp -std=c++17
./sistema_academico
```

## Conceptos Aplicados

- **Árboles binarios de búsqueda (BST)**: estructura jerárquica ordenada por cédula.
- **Recursividad**: inserción, búsqueda, eliminación y todos los recorridos.
- **Punteros en C++**: gestión dinámica de memoria con `new` y `delete`.
- **Colas para BFS**: `std::queue` para el recorrido por niveles.
- **Clases y objetos**: encapsulamiento con métodos privados y públicos.
- **Código modular**: archivos separados por responsabilidad (`.h` y `.cpp`).
- **Validación de datos**: cédula de 10 dígitos y nota entre 0.0 y 10.0.

## Datos de Prueba Precargados

El programa incluye 5 estudiantes al iniciar:

| Cédula | Apellidos | Nombres | Nota | Estado |
|--------|-----------|---------|------|--------|
| 1804567890 | García López | Juan Carlos | 8.5 | Aprobado |
| 1801234567 | Martínez Ruiz | María José | 9.2 | Aprobado |
| 1807654321 | Pérez Sánchez | Luis Fernando | 6.3 | Reprobado |
| 1803456789 | Rodríguez Mora | Ana Patricia | 7.8 | Aprobado |
| 1809876543 | Vargas Torres | Carlos Andrés | 5.1 | Reprobado |

## Autor

Estudiante de Ingeniería en Software — FISEI, Universidad Técnica de Ambato
