/**
 * ============================================================
 * main.cpp
 * Programa principal: menú interactivo del sistema académico
 * Universidad Técnica de Ambato - Estructura de Datos
 * ============================================================
 * Este archivo contiene únicamente el menú y la lógica de
 * entrada/salida. Toda la lógica del árbol está en ArbolBST.
 * ============================================================
 */

#include <iostream>
#include <string>
#include <limits>
#include "ArbolBST.h"

using namespace std;

// ============================================================
// Funciones auxiliares de validación e ingreso de datos
// ============================================================

/**
 * Limpia el buffer de entrada para evitar lecturas incorrectas
 * después de usar cin >> con tipos numéricos.
 */
void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * Valida que la cédula tenga exactamente 10 dígitos numéricos.
 * @param cedula Cédula a validar
 * @return true si es válida, false en caso contrario
 */
bool validarCedula(const string& cedula) {
    if (cedula.length() != 10) return false;
    for (char c : cedula) {
        if (!isdigit(c)) return false;
    }
    return true;
}

/**
 * Lee y valida una nota final entre 0.0 y 10.0.
 * Repite la solicitud hasta obtener un valor válido.
 * @return Nota válida ingresada por el usuario
 */
double leerNota() {
    double nota;
    while (true) {
        cout << "    Nota final (0.0 - 10.0): ";
        cin >> nota;
        if (cin.fail() || nota < 0.0 || nota > 10.0) {
            cout << "    [ERROR] Nota invalida. Ingrese un valor entre 0.0 y 10.0." << endl;
            limpiarBuffer();
        } else {
            limpiarBuffer();
            return nota;
        }
    }
}

/**
 * Solicita al usuario todos los datos de un estudiante.
 * Incluye validación de cédula y nota.
 * @return Estructura Estudiante con los datos ingresados
 */
Estudiante leerDatosEstudiante() {
    Estudiante est;

    // Validar cédula (10 dígitos numéricos)
    while (true) {
        cout << "    Cedula (10 digitos): ";
        getline(cin, est.cedula);
        if (validarCedula(est.cedula)) break;
        cout << "    [ERROR] La cedula debe tener exactamente 10 digitos numericos." << endl;
    }

    cout << "    Apellidos: ";
    getline(cin, est.apellidos);

    cout << "    Nombres: ";
    getline(cin, est.nombres);

    est.notaFinal = leerNota();

    cout << "    Carrera: ";
    getline(cin, est.carrera);

    cout << "    Nivel: ";
    getline(cin, est.nivel);

    return est;
}

/**
 * Precarga 5 estudiantes de ejemplo para facilitar las pruebas
 * y demostraciones del sistema.
 * @param arbol Referencia al objeto ArbolBST
 */
void precargarDatos(ArbolBST& arbol) {
    Estudiante e1 = {"1804567890", "Garcia Lopez", "Juan Carlos", 8.5,
                     "Ingenieria en Software", "Tercer Nivel"};
    Estudiante e2 = {"1801234567", "Martinez Ruiz", "Maria Jose", 9.2,
                     "Ingenieria en Software", "Tercer Nivel"};
    Estudiante e3 = {"1807654321", "Perez Sanchez", "Luis Fernando", 6.3,
                     "Ingenieria en Software", "Tercer Nivel"};
    Estudiante e4 = {"1803456789", "Rodriguez Mora", "Ana Patricia", 7.8,
                     "Ingenieria en Software", "Tercer Nivel"};
    Estudiante e5 = {"1809876543", "Vargas Torres", "Carlos Andres", 5.1,
                     "Ingenieria en Software", "Tercer Nivel"};

    arbol.insertarEstudiante(e1);
    arbol.insertarEstudiante(e2);
    arbol.insertarEstudiante(e3);
    arbol.insertarEstudiante(e4);
    arbol.insertarEstudiante(e5);

    cout << "  [INFO] Se precargaron 5 estudiantes de ejemplo." << endl;
}

/**
 * Muestra el menú principal del sistema con todas las opciones.
 */
void mostrarMenu() {
    cout << endl;
    cout << "  =============================================" << endl;
    cout << "   SISTEMA ACADEMICO UTA - Arbol Binario (C++)" << endl;
    cout << "  =============================================" << endl;
    cout << "   1.  Insertar estudiante" << endl;
    cout << "   2.  Buscar estudiante por cedula" << endl;
    cout << "   3.  Eliminar estudiante" << endl;
    cout << "   4.  Recorrido Inorden" << endl;
    cout << "   5.  Recorrido Preorden" << endl;
    cout << "   6.  Recorrido Postorden" << endl;
    cout << "   7.  Recorrido por niveles (BFS)" << endl;
    cout << "   8.  Contar estudiantes" << endl;
    cout << "   9.  Calcular altura del arbol" << endl;
    cout << "   10. Mostrar estudiante con mayor nota" << endl;
    cout << "   11. Mostrar estudiante con menor nota" << endl;
    cout << "   12. Mostrar estudiantes aprobados" << endl;
    cout << "   13. Mostrar estudiantes reprobados" << endl;
    cout << "   14. Salir" << endl;
    cout << "  =============================================" << endl;
    cout << "  Seleccione una opcion: ";
}

// ============================================================
// Función principal
// ============================================================
int main() {
    ArbolBST arbol;  // Crear el árbol binario de búsqueda
    int opcion;

    // Precargar datos de ejemplo
    precargarDatos(arbol);

    do {
        mostrarMenu();
        cin >> opcion;

        // Validar que la entrada sea numérica
        if (cin.fail()) {
            limpiarBuffer();
            cout << "  [ERROR] Ingrese un numero valido." << endl;
            continue;
        }
        limpiarBuffer();

        switch (opcion) {
            case 1: {
                cout << endl << "  --- INSERTAR ESTUDIANTE ---" << endl;
                Estudiante est = leerDatosEstudiante();
                if (arbol.insertarEstudiante(est))
                    cout << "  [OK] Estudiante insertado correctamente." << endl;
                else
                    cout << "  [ERROR] Ya existe un estudiante con esa cedula." << endl;
                break;
            }
            case 2: {
                cout << endl << "  --- BUSCAR ESTUDIANTE ---" << endl;
                string cedula;
                cout << "    Ingrese la cedula: ";
                getline(cin, cedula);
                Nodo* encontrado = arbol.buscarEstudiante(cedula);
                if (encontrado != nullptr) {
                    cout << "  [OK] Estudiante encontrado:" << endl;
                    arbol.mostrarEstudiante(encontrado->dato);
                } else {
                    cout << "  [INFO] Estudiante no encontrado." << endl;
                }
                break;
            }
            case 3: {
                cout << endl << "  --- ELIMINAR ESTUDIANTE ---" << endl;
                string cedula;
                cout << "    Ingrese la cedula: ";
                getline(cin, cedula);
                if (arbol.eliminarEstudiante(cedula))
                    cout << "  [OK] Estudiante eliminado correctamente." << endl;
                else
                    cout << "  [INFO] Estudiante no encontrado." << endl;
                break;
            }
            case 4:
                cout << endl << "  --- RECORRIDO INORDEN (Izq -> Raiz -> Der) ---" << endl;
                arbol.recorridoInorden();
                break;
            case 5:
                cout << endl << "  --- RECORRIDO PREORDEN (Raiz -> Izq -> Der) ---" << endl;
                arbol.recorridoPreorden();
                break;
            case 6:
                cout << endl << "  --- RECORRIDO POSTORDEN (Izq -> Der -> Raiz) ---" << endl;
                arbol.recorridoPostorden();
                break;
            case 7:
                cout << endl << "  --- RECORRIDO POR NIVELES (BFS) ---" << endl;
                arbol.recorridoPorNiveles();
                break;
            case 8:
                cout << endl << "  Total de estudiantes: " << arbol.contarEstudiantes() << endl;
                break;
            case 9:
                cout << endl << "  Altura del arbol: " << arbol.obtenerAltura() << endl;
                break;
            case 10:
                cout << endl;
                arbol.mostrarNotaMayor();
                break;
            case 11:
                cout << endl;
                arbol.mostrarNotaMenor();
                break;
            case 12:
                cout << endl;
                arbol.listarAprobados();
                break;
            case 13:
                cout << endl;
                arbol.listarReprobados();
                break;
            case 14:
                cout << endl << "  Saliendo del sistema. Hasta luego!" << endl;
                break;
            default:
                cout << "  [ERROR] Opcion no valida. Intente de nuevo." << endl;
        }

    } while (opcion != 14);

    return 0;
}
