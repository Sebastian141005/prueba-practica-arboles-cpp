/**
 * 
 * Nodo.h
 * Definición del nodo del árbol binario de búsqueda
 * Universidad Técnica de Ambato - Estructura de Datos
 * 
 */

#ifndef NODO_H
#define NODO_H

#include "Estudiante.h"

/**
 * Estructura Nodo del árbol binario de búsqueda.
 * Contiene un Estudiante y punteros a los hijos izquierdo y derecho.
 */
struct Nodo {
    Estudiante dato;    // Datos del estudiante almacenado
    Nodo* izquierdo;    // Puntero al hijo izquierdo (cédulas menores)
    Nodo* derecho;      // Puntero al hijo derecho (cédulas mayores)

    /**
     * Constructor: crea un nodo con un estudiante dado.
     * Inicializa ambos hijos como nullptr (nodo hoja).
     * @param est Estudiante a almacenar en el nodo
     */
    Nodo(Estudiante est) : dato(est), izquierdo(nullptr), derecho(nullptr) {}
};

#endif // NODO_H
