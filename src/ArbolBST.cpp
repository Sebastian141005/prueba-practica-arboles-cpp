/**

 * ArbolBST.cpp
 * Implementación de la clase ArbolBST
 * Universidad Técnica de Ambato - Estructura de Datos
 * ============================================================
 */

#include "ArbolBST.h"
#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;


// Constructor y Destructor


/** Constructor: inicializa el árbol vacío */
ArbolBST::ArbolBST() : raiz(nullptr) {}

/** Destructor: libera toda la memoria del árbol */
ArbolBST::~ArbolBST() {
    destruir(raiz);
}


// Métodos privados recursivos


/**
 * Inserta un estudiante en el subárbol con raíz 'nodo'.
 * Compara por cédula para mantener la propiedad BST.
 * @param nodo Puntero al nodo actual (por referencia a puntero)
 * @param est  Estudiante a insertar
 * @return true si se insertó, false si la cédula ya existe
 */
bool ArbolBST::insertar(Nodo*& nodo, Estudiante est) {
    if (nodo == nullptr) {
        nodo = new Nodo(est);
        return true;
    }
    if (est.cedula < nodo->dato.cedula) {
        return insertar(nodo->izquierdo, est);
    } else if (est.cedula > nodo->dato.cedula) {
        return insertar(nodo->derecho, est);
    }
    // Cédula duplicada: no se inserta
    return false;
}

/**
 * Busca un estudiante por cédula en el subárbol.
 * @param nodo   Puntero al nodo actual
 * @param cedula Cédula a buscar
 * @return Puntero al nodo encontrado o nullptr si no existe
 */
Nodo* ArbolBST::buscar(Nodo* nodo, const string& cedula) {
    if (nodo == nullptr) return nullptr;
    if (cedula == nodo->dato.cedula) return nodo;
    if (cedula < nodo->dato.cedula)
        return buscar(nodo->izquierdo, cedula);
    else
        return buscar(nodo->derecho, cedula);
}

/**
 * Encuentra el nodo con la cédula mínima (más a la izquierda).
 * Se usa para la eliminación con dos hijos (sucesor inorden).
 * @param nodo Puntero al nodo desde donde buscar
 * @return Puntero al nodo con cédula mínima
 */
Nodo* ArbolBST::encontrarMinimo(Nodo* nodo) {
    while (nodo->izquierdo != nullptr)
        nodo = nodo->izquierdo;
    return nodo;
}

/**
 * Elimina un nodo por cédula del subárbol.
 * Maneja los tres casos clásicos de eliminación en BST:
 *   1. Nodo hoja (sin hijos): se elimina directamente.
 *   2. Nodo con un solo hijo: se reemplaza por su hijo.
 *   3. Nodo con dos hijos: se reemplaza por el sucesor inorden.
 * @param nodo   Puntero al nodo actual (por referencia)
 * @param cedula Cédula del estudiante a eliminar
 * @return true si se eliminó, false si no se encontró
 */
bool ArbolBST::eliminar(Nodo*& nodo, const string& cedula) {
    if (nodo == nullptr) return false;

    if (cedula < nodo->dato.cedula) {
        return eliminar(nodo->izquierdo, cedula);
    } else if (cedula > nodo->dato.cedula) {
        return eliminar(nodo->derecho, cedula);
    } else {
        // Caso 1: Nodo hoja
        if (nodo->izquierdo == nullptr && nodo->derecho == nullptr) {
            delete nodo;
            nodo = nullptr;
        }
        // Caso 2a: Solo tiene hijo derecho
        else if (nodo->izquierdo == nullptr) {
            Nodo* temp = nodo;
            nodo = nodo->derecho;
            delete temp;
        }
        // Caso 2b: Solo tiene hijo izquierdo
        else if (nodo->derecho == nullptr) {
            Nodo* temp = nodo;
            nodo = nodo->izquierdo;
            delete temp;
        }
        // Caso 3: Tiene ambos hijos
        else {
            Nodo* sucesor = encontrarMinimo(nodo->derecho);
            nodo->dato = sucesor->dato;
            eliminar(nodo->derecho, sucesor->dato.cedula);
        }
        return true;
    }
}

/**
 * Recorrido Inorden: izquierdo -> raíz -> derecho.
 * Muestra los estudiantes ordenados ascendentemente por cédula.
 */
void ArbolBST::inorden(Nodo* nodo) {
    if (nodo == nullptr) return;
    inorden(nodo->izquierdo);
    mostrarEstudiante(nodo->dato);
    inorden(nodo->derecho);
}

/**
 * Recorrido Preorden: raíz -> izquierdo -> derecho.
 * Útil para copiar o serializar la estructura del árbol.
 */
void ArbolBST::preorden(Nodo* nodo) {
    if (nodo == nullptr) return;
    mostrarEstudiante(nodo->dato);
    preorden(nodo->izquierdo);
    preorden(nodo->derecho);
}

/**
 * Recorrido Postorden: izquierdo -> derecho -> raíz.
 * Útil para liberar memoria del árbol (hijos antes que padre).
 */
void ArbolBST::postorden(Nodo* nodo) {
    if (nodo == nullptr) return;
    postorden(nodo->izquierdo);
    postorden(nodo->derecho);
    mostrarEstudiante(nodo->dato);
}

/**
 * Cuenta el total de nodos en el subárbol de forma recursiva.
 * @param nodo Puntero al nodo actual
 * @return Número total de nodos
 */
int ArbolBST::contarNodos(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    return 1 + contarNodos(nodo->izquierdo) + contarNodos(nodo->derecho);
}

/**
 * Calcula la altura del subárbol de forma recursiva.
 * Árbol vacío = -1, un solo nodo = 0.
 * @param nodo Puntero al nodo actual
 * @return Altura del subárbol
 */
int ArbolBST::calcularAltura(Nodo* nodo) {
    if (nodo == nullptr) return -1;
    int altIzq = calcularAltura(nodo->izquierdo);
    int altDer = calcularAltura(nodo->derecho);
    return 1 + max(altIzq, altDer);
}

/**
 * Busca recursivamente el estudiante con la nota más alta.
 * @param nodo  Puntero al nodo actual
 * @param mejor Puntero al nodo con mejor nota (se actualiza)
 */
void ArbolBST::buscarNotaMayor(Nodo* nodo, Nodo*& mejor) {
    if (nodo == nullptr) return;
    if (mejor == nullptr || nodo->dato.notaFinal > mejor->dato.notaFinal) {
        mejor = nodo;
    }
    buscarNotaMayor(nodo->izquierdo, mejor);
    buscarNotaMayor(nodo->derecho, mejor);
}

/**
 * Busca recursivamente el estudiante con la nota más baja.
 * @param nodo Puntero al nodo actual
 * @param peor Puntero al nodo con peor nota (se actualiza)
 */
void ArbolBST::buscarNotaMenor(Nodo* nodo, Nodo*& peor) {
    if (nodo == nullptr) return;
    if (peor == nullptr || nodo->dato.notaFinal < peor->dato.notaFinal) {
        peor = nodo;
    }
    buscarNotaMenor(nodo->izquierdo, peor);
    buscarNotaMenor(nodo->derecho, peor);
}

/**
 * Muestra recursivamente los estudiantes aprobados (nota >= 7.0).
 * @param nodo   Puntero al nodo actual
 * @param conteo Contador de aprobados (se incrementa)
 */
void ArbolBST::mostrarAprobados(Nodo* nodo, int& conteo) {
    if (nodo == nullptr) return;
    mostrarAprobados(nodo->izquierdo, conteo);
    if (nodo->dato.notaFinal >= 7.0) {
        mostrarEstudiante(nodo->dato);
        conteo++;
    }
    mostrarAprobados(nodo->derecho, conteo);
}

/**
 * Muestra recursivamente los estudiantes reprobados (nota < 7.0).
 * @param nodo   Puntero al nodo actual
 * @param conteo Contador de reprobados (se incrementa)
 */
void ArbolBST::mostrarReprobados(Nodo* nodo, int& conteo) {
    if (nodo == nullptr) return;
    mostrarReprobados(nodo->izquierdo, conteo);
    if (nodo->dato.notaFinal < 7.0) {
        mostrarEstudiante(nodo->dato);
        conteo++;
    }
    mostrarReprobados(nodo->derecho, conteo);
}

/**
 * Libera la memoria de todos los nodos (recorrido postorden).
 * @param nodo Puntero al nodo actual
 */
void ArbolBST::destruir(Nodo* nodo) {
    if (nodo == nullptr) return;
    destruir(nodo->izquierdo);
    destruir(nodo->derecho);
    delete nodo;
}


// Métodos públicos


/**
 * Muestra los datos de un estudiante con formato de tabla.
 * @param est Referencia constante al estudiante a mostrar
 */
void ArbolBST::mostrarEstudiante(const Estudiante& est) {
    cout << "  +-------------------------------+" << endl;
    cout << "  | Cedula:   " << left << setw(20) << est.cedula << "|" << endl;
    cout << "  | Apellidos:" << left << setw(20) << est.apellidos << "|" << endl;
    cout << "  | Nombres:  " << left << setw(20) << est.nombres << "|" << endl;
    cout << "  | Nota:     " << left << setw(20) << fixed << setprecision(2) << est.notaFinal << "|" << endl;
    cout << "  | Carrera:  " << left << setw(20) << est.carrera << "|" << endl;
    cout << "  | Nivel:    " << left << setw(20) << est.nivel << "|" << endl;
    cout << "  +-------------------------------+" << endl;
}

/** Inserta un estudiante en el árbol */
bool ArbolBST::insertarEstudiante(Estudiante est) {
    return insertar(raiz, est);
}

/** Busca un estudiante por cédula */
Nodo* ArbolBST::buscarEstudiante(const string& cedula) {
    return buscar(raiz, cedula);
}

/** Elimina un estudiante por cédula */
bool ArbolBST::eliminarEstudiante(const string& cedula) {
    return eliminar(raiz, cedula);
}

/** Ejecuta y muestra el recorrido Inorden */
void ArbolBST::recorridoInorden() {
    if (raiz == nullptr) {
        cout << "  El arbol esta vacio." << endl;
        return;
    }
    inorden(raiz);
}

/** Ejecuta y muestra el recorrido Preorden */
void ArbolBST::recorridoPreorden() {
    if (raiz == nullptr) {
        cout << "  El arbol esta vacio." << endl;
        return;
    }
    preorden(raiz);
}

/** Ejecuta y muestra el recorrido Postorden */
void ArbolBST::recorridoPostorden() {
    if (raiz == nullptr) {
        cout << "  El arbol esta vacio." << endl;
        return;
    }
    postorden(raiz);
}

/**
 * Recorrido por niveles (BFS) usando una cola (std::queue).
 * Visita los nodos nivel por nivel, de izquierda a derecha.
 */
void ArbolBST::recorridoPorNiveles() {
    if (raiz == nullptr) {
        cout << "  El arbol esta vacio." << endl;
        return;
    }
    queue<Nodo*> cola;
    cola.push(raiz);
    int nivel = 0;

    while (!cola.empty()) {
        int tamNivel = cola.size();
        cout << "  --- Nivel " << nivel << " ---" << endl;
        for (int i = 0; i < tamNivel; i++) {
            Nodo* actual = cola.front();
            cola.pop();
            mostrarEstudiante(actual->dato);
            if (actual->izquierdo != nullptr)
                cola.push(actual->izquierdo);
            if (actual->derecho != nullptr)
                cola.push(actual->derecho);
        }
        nivel++;
    }
}

/** Retorna el número total de estudiantes en el árbol */
int ArbolBST::contarEstudiantes() {
    return contarNodos(raiz);
}

/** Retorna la altura del árbol */
int ArbolBST::obtenerAltura() {
    return calcularAltura(raiz);
}

/** Busca y muestra el estudiante con la mayor nota */
void ArbolBST::mostrarNotaMayor() {
    if (raiz == nullptr) {
        cout << "  El arbol esta vacio." << endl;
        return;
    }
    Nodo* mejor = nullptr;
    buscarNotaMayor(raiz, mejor);
    cout << "  Estudiante con la MAYOR nota:" << endl;
    mostrarEstudiante(mejor->dato);
}

/** Busca y muestra el estudiante con la menor nota */
void ArbolBST::mostrarNotaMenor() {
    if (raiz == nullptr) {
        cout << "  El arbol esta vacio." << endl;
        return;
    }
    Nodo* peor = nullptr;
    buscarNotaMenor(raiz, peor);
    cout << "  Estudiante con la MENOR nota:" << endl;
    mostrarEstudiante(peor->dato);
}

/** Muestra todos los estudiantes aprobados (nota >= 7.0) */
void ArbolBST::listarAprobados() {
    if (raiz == nullptr) {
        cout << "  El arbol esta vacio." << endl;
        return;
    }
    int conteo = 0;
    cout << "  === ESTUDIANTES APROBADOS (nota >= 7.0) ===" << endl;
    mostrarAprobados(raiz, conteo);
    if (conteo == 0)
        cout << "  No hay estudiantes aprobados." << endl;
    else
        cout << "  Total aprobados: " << conteo << endl;
}

/** Muestra todos los estudiantes reprobados (nota < 7.0) */
void ArbolBST::listarReprobados() {
    if (raiz == nullptr) {
        cout << "  El arbol esta vacio." << endl;
        return;
    }
    int conteo = 0;
    cout << "  === ESTUDIANTES REPROBADOS (nota < 7.0) ===" << endl;
    mostrarReprobados(raiz, conteo);
    if (conteo == 0)
        cout << "  No hay estudiantes reprobados." << endl;
    else
        cout << "  Total reprobados: " << conteo << endl;
}
