#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estructura para representar a un colaborador
struct Colaborador {
    string nombre;
    float salarioBase;
    float bono;
    float deducciones;
};

// Base de datos de colaboradores
vector<Colaborador> colaboradores;

// Contraseña maestra
const string contrasenaMaestra = "geraldiospro";

bool ingresarContrasena() {
    cout << "Contraseña: ";
    string contrasena;
    cin >> contrasena;

    if (contrasena == contrasenaMaestra) {
        return true;
    } else {
        cout << "Contraseña incorrecta." << endl;
        return false;
    }
}

void mostrarMenu() {
    cout << "\nMenú:" << endl;
    cout << "1. Agregar nuevo colaborador" << endl;
    cout << "2. Consultar colaborador (individual)" << endl;
    cout << "3. Consultar plantilla completa" << endl;
    cout << "4. Modificar colaborador" << endl;
    cout << "5. Eliminar colaborador" << endl;
    cout << "6. Gestionar salarios" << endl;
    cout << "0. Salir" << endl;
}

void agregarColaborador() {
    Colaborador nuevoColaborador;

    cout << "Nombre del colaborador: ";
    cin >> nuevoColaborador.nombre;

    cout << "Salario base: ";
    cin >> nuevoColaborador.salarioBase;

    cout << "Bono: ";
    cin >> nuevoColaborador.bono;

    cout << "Deducciones: ";
    cin >> nuevoColaborador.deducciones;

    colaboradores.push_back(nuevoColaborador);

    cout << "Colaborador agregado" << endl;
}

void consultarColaborador() {
    string nombre;
    cout << "Colaborador a consultar: ";
    cin >> nombre;

    for (const Colaborador& colaborador : colaboradores) {
        if (colaborador.nombre == nombre) {
            // Mostrar detalles del colaborador
            cout << "Nombre: " << colaborador.nombre << endl;
            cout << "Salario Base: " << colaborador.salarioBase << endl;
            cout << "Bono: " << colaborador.bono << endl;
            cout << "Deducciones: " << colaborador.deducciones << endl;
            return;
        }
    }

    cout << "Colaborador no encontrado." << endl;
}

void consultarPlantillaCompleta() {
    if (colaboradores.empty()) {
        cout << "No hay colaboradores en la plantilla." << endl;
    } else {
        cout << "Plantilla completa:" << endl;
        for (const Colaborador& colaborador : colaboradores) {
            cout << "Nombre: " << colaborador.nombre << endl;
            cout << "Salario Base: " << colaborador.salarioBase << endl;
            cout << "Bono: " << colaborador.bono << endl;
            cout << "Deducciones: " << colaborador.deducciones << endl;
            cout << "---------------------" << endl;
        }
    }
}

void modificarColaborador() {
    string nombre;
    cout << "Colaborador a modificar: ";
    cin >> nombre;

    for (Colaborador& colaborador : colaboradores) {
        if (colaborador.nombre == nombre) {
            // Modificar detalles del colaborador
            cout << "Ingrese el nuevo salario base: ";
            cin >> colaborador.salarioBase;

            cout << "Nuevo bono: ";
            cin >> colaborador.bono;

            cout << "Nuevas Deducciones: ";
            cin >> colaborador.deducciones;

            cout << "Colaborador modificado" << endl;
            return;
        }
    }

    cout << "Colaborador no encontrado." << endl;
}

void eliminarColaborador() {
    string nombre;
    cout << "Nombre del colaborador a eliminar: ";
    cin >> nombre;

    for (auto it = colaboradores.begin(); it != colaboradores.end(); ++it) {
        if (it->nombre == nombre) {
            it = colaboradores.erase(it);
            cout << "Colaborador eliminado" << endl;
            return;
        }
    }

    cout << "Colaborador no encontrado." << endl;
}

int main() {
    if (!ingresarContrasena()) {
        return 1; // Salir del programa si la contraseña es incorrecta
    }

    int opcion;
    do {
        mostrarMenu();

        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarColaborador();
                break;
            case 2:
                consultarColaborador();
                break;
            case 3:
                consultarPlantillaCompleta();
                break;
            case 4:
                modificarColaborador();
                break;
            case 5:
                eliminarColaborador();
                break;
            case 6:
                // Implementa la gestión de salarios según tus necesidades
                cout << "Opción no implementada." << endl;
                break;
            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Inténtelo de nuevo." << endl;
        }

    } while (opcion != 0);

    return 0;
}