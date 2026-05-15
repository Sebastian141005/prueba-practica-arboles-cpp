/**
 * 
 * ArbolBST.h
 * Declaración de la clase ArbolBST (Árbol Binario de Búsqueda)
 * Universidad Técnica de Ambato - Estructura de Datos
 * 
 */

#ifndef ARBOL_BST_H
#define ARBOL_BST_H

#include "Nodo.h"
#include <string>

/**
 * Clase ArbolBST: implementa un Árbol Binario de Búsqueda
 * que gestiona estudiantes ordenados por cédula.
 *
 * Métodos públicos exponen las operaciones del menú.
 * Métodos privados implementan la lógica recursiva interna.
 */
class ArbolBST {
private:
    Nodo* raiz; // Puntero a la raíz del árbol

    // --- Métodos privados recursivos ---
    bool insertar(Nodo*& nodo, Estudiante est);
    Nodo* buscar(Nodo* nodo, const string& cedula);
    Nodo* encontrarMinimo(Nodo* nodo);
    bool eliminar(Nodo*& nodo, const string& cedula);
    void inorden(Nodo* nodo);
    void preorden(Nodo* nodo);
    void postorden(Nodo* nodo);
    int contarNodos(Nodo* nodo);
    int calcularAltura(Nodo* nodo);
    void buscarNotaMayor(Nodo* nodo, Nodo*& mejor);
    void buscarNotaMenor(Nodo* nodo, Nodo*& peor);
    void mostrarAprobados(Nodo* nodo, int& conteo);
    void mostrarReprobados(Nodo* nodo, int& conteo);
    void destruir(Nodo* nodo);

public:
    // Constructor y destructor
    ArbolBST();
    ~ArbolBST();

    // Utilidad para mostrar datos de un estudiante
    void mostrarEstudiante(const Estudiante& est);

    // --- Métodos públicos del menú ---
    bool insertarEstudiante(Estudiante est);
    Nodo* buscarEstudiante(const string& cedula);
    bool eliminarEstudiante(const string& cedula);
    void recorridoInorden();
    void recorridoPreorden();
    void recorridoPostorden();
    void recorridoPorNiveles();
    int contarEstudiantes();
    int obtenerAltura();
    void mostrarNotaMayor();
    void mostrarNotaMenor();
    void listarAprobados();
    void listarReprobados();
};

#endif // ARBOL_BST_H
