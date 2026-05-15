/**
 *
 * Estudiante.h
 * Definición de la estructura Estudiante
 * Universidad Técnica de Ambato - Estructura de Datos
 * 
 */

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
using namespace std;

/**
 * Estructura que almacena los datos académicos de un estudiante.
 * Se usa como dato contenido en cada nodo del árbol binario.
 */
struct Estudiante {
    string cedula;      // Cédula de identidad (10 dígitos) - clave del ABB
    string apellidos;   // Apellidos del estudiante
    string nombres;     // Nombres del estudiante
    double notaFinal;   // Nota final (0.0 - 10.0)
    string carrera;     // Carrera universitaria
    string nivel;       // Nivel académico (ej: Tercer Nivel)
};

#endif // ESTUDIANTE_H
