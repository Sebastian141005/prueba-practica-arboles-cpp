Información General
Campo	Detalle
Asignatura	Estructura de Datos
Tema	Árboles binarios de búsqueda, recorridos y aplicación práctica
Universidad	Universidad Técnica de Ambato (UTA)
Facultad	FISEI
Carrera	Ingeniería en Software
Lenguajes	C++ y Java
Repositorio	prueba-practica-arboles-cpp-java
Descripción del Proyecto

Este proyecto consiste en el desarrollo de un sistema académico utilizando Árboles Binarios de Búsqueda (ABB) para gestionar estudiantes de la Universidad Técnica de Ambato.

Cada estudiante almacena la siguiente información:

Cédula
Apellidos
Nombres
Nota final
Carrera
Nivel

El árbol binario organiza los estudiantes por número de cédula, permitiendo búsquedas y recorridos eficientes.

Objetivo

Aplicar los conceptos de:

Árboles Binarios de Búsqueda
Recursividad
Programación Orientada a Objetos
Punteros y referencias
Recorridos de árboles
BFS utilizando colas
Código modular
Implementación en C++
Estructura del Proyecto
cpp/
├── Estudiante.h
├── Nodo.h
├── ArbolBST.h
├── ArbolBST.cpp
└── main.cpp
Funciones Implementadas
Función	Descripción
insertarEstudiante()	Inserta un estudiante en el árbol
buscarEstudiante()	Busca por número de cédula
eliminarEstudiante()	Elimina un nodo del árbol
recorridoInorden()	Muestra datos ordenados por cédula
recorridoPreorden()	Recorre raíz, izquierda y derecha
recorridoPostorden()	Recorre izquierda, derecha y raíz
recorridoPorNiveles()	BFS utilizando cola
contarNodos()	Cuenta estudiantes registrados
calcularAltura()	Calcula altura del árbol
buscarNotaMayor()	Encuentra mayor nota
buscarNotaMenor()	Encuentra menor nota
mostrarAprobados()	Lista aprobados
mostrarReprobados()	Lista reprobados
Implementación en Java
Estructura del Proyecto
java/
├── Estudiante.java
├── Nodo.java
├── ArbolBST.java
└── Main.java
Características Aplicadas
Programación Orientada a Objetos
Clases y objetos
Métodos recursivos
Referencias en Java
Encapsulamiento
Modularidad
Recorridos del Árbol
Inorden

Izquierda → Raíz → Derecha

Permite mostrar los estudiantes ordenados por número de cédula.

Preorden

Raíz → Izquierda → Derecha

Postorden

Izquierda → Derecha → Raíz

BFS (Por niveles)

Recorrido nivel por nivel utilizando colas.

Menú del Programa
1. Insertar estudiante
2. Buscar estudiante por cédula
3. Eliminar estudiante
4. Recorrido Inorden
5. Recorrido Preorden
6. Recorrido Postorden
7. Recorrido por niveles BFS
8. Contar estudiantes
9. Calcular altura del árbol
10. Mostrar estudiante con mayor nota
11. Mostrar estudiante con menor nota
12. Mostrar estudiantes aprobados
13. Mostrar estudiantes reprobados
14. Salir
Compilación y Ejecución
C++
g++ -o sistema main.cpp ArbolBST.cpp -std=c++17
./sistema
Java
javac Main.java
java Main
Conceptos Aplicados
Árboles Binarios de Búsqueda
Recursividad
Punteros en C++
Referencias en Java
BFS con colas
Clases y objetos
Código modular
Validación de datos
Explicación del Recorrido Inorden

El recorrido Inorden en un árbol binario de búsqueda muestra los datos ordenados por cédula porque recorre primero el subárbol izquierdo, luego la raíz y finalmente el subárbol derecho.

En un ABB, los valores menores se almacenan a la izquierda y los mayores a la derecha, por lo que el recorrido Inorden presenta automáticamente los estudiantes en orden ascendente.

Autor

Rolando Miranda
Ingeniería en Software — FISEI
Universidad Técnica de Ambato
