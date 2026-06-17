#include "ControladorJuego.h"
#include <iostream>
#include <algorithm>
using namespace std;

ControladorJuego::ControladorJuego()
    : tablero(nullptr), fila(nullptr), numParqueos(0), parqueosOcupados(0) {
}

ControladorJuego::~ControladorJuego() {
}

void ControladorJuego::iniciarNivel(int nivel) {
    string nombreArchivo = "nivel" + to_string(nivel) + ".txt";
    gestorArchivos.cargarArchivos(nombreArchivo);

    tablero = gestorArchivos.getTablero();
    fila = gestorArchivos.getFila();
    numParqueos = gestorArchivos.getNumParqueos();
    vehiculos = gestorArchivos.getVehiculos();
    parqueosOcupados = 0;
}

bool ControladorJuego::llegoAlBorde(Vehiculo* vehiculo) {
    char orientacion = vehiculo->getOrientacion();
    int f = vehiculo->getFila();
    int c = vehiculo->getColumna();
    int largo = vehiculo->getLargo();

    if (orientacion == 'N' && f == 0) return true;
    if (orientacion == 'S' && f + largo - 1 == tablero->getFilas() - 1) return true;
    if (orientacion == 'E' && c + largo - 1 == tablero->getColumnas() - 1) return true;
    if (orientacion == 'O' && c == 0) return true;

    return false;
}

bool ControladorJuego::validarMovimientoTablero(Vehiculo* vehiculo) {
    char orientacion = vehiculo->getOrientacion();
    int f = vehiculo->getFila();
    int c = vehiculo->getColumna();
    int largo = vehiculo->getLargo();

    if (orientacion == 'N') {
        for (int i = f - 1; i >= 0; i--) {
            if (!tablero->celdaLibre(i, c)) return false;
        }
    } else if (orientacion == 'S') {
        for (int i = f + largo; i < tablero->getFilas(); i++) {
            if (!tablero->celdaLibre(i, c)) return false;
        }
    } else if (orientacion == 'E') {
        for (int i = c + largo; i < tablero->getColumnas(); i++) {
            if (!tablero->celdaLibre(f, i)) return false;
        }
    } else if (orientacion == 'O') {
        for (int i = c - 1; i >= 0; i--) {
            if (!tablero->celdaLibre(f, i)) return false;
        }
    }
    return true;
}

void ControladorJuego::moverVehiculoTablero(Vehiculo* vehiculo) {
    tablero->retirarVehiculo(vehiculo);

    char orientacion = vehiculo->getOrientacion();
    if (orientacion == 'N') {
        vehiculo->setFila(vehiculo->getFila() - 1);
    } else if (orientacion == 'S') {
        vehiculo->setFila(vehiculo->getFila() + 1);
    } else if (orientacion == 'E') {
        vehiculo->setColumna(vehiculo->getColumna() + 1);
    } else if (orientacion == 'O') {
        vehiculo->setColumna(vehiculo->getColumna() - 1);
    }

    tablero->colocarVehiculo(vehiculo);
}

void ControladorJuego::moverVehiculoParqueo(int indice) {
    if (indice < 0 || indice >= (int)vehiculos.size()) {
        cout << "Vehículo inválido." << endl;
        return;
    }

    Vehiculo* vehiculo = vehiculos[indice];

    if (!validarMovimientoTablero(vehiculo)) {
        cout << "El camino no está despejado." << endl;
        return;
    }

    if (parqueosOcupados >= numParqueos) {
        cout << "No hay parqueos disponibles." << endl;
        return;
    }

    // Mover hasta el borde
    while (!llegoAlBorde(vehiculo)) {
        moverVehiculoTablero(vehiculo);
    }

    // Retirar del tablero y agregar al parqueo
    tablero->retirarVehiculo(vehiculo);
    parqueosOcupados++;
    vehiculosEnParqueo.push_back(vehiculo);

    abordarPasajero(vehiculo);
}

void ControladorJuego::abordarPasajero(Vehiculo* vehiculo) {
    while (!vehiculo->estaLleno() && !fila->estaVacia()) {
        Pasajero primero = fila->obtenerPrimero();

        if (primero.getColor() == vehiculo->getColor()) {
            fila->retirarPrimero();
            vehiculo->subirPasajero();
            cout << "Pasajero " << primero.getColor()
                 << " abordó el vehículo." << endl;
        } else {
            cout << "Atasco: el pasajero al frente es de color "
                 << primero.getColor() << " y el vehículo es "
                 << vehiculo->getColor() << endl;
            break;
        }
    }

    // Si el vehículo está lleno liberar el parqueo
    if (vehiculo->estaLleno()) {
        parqueosOcupados--;
        vehiculosEnParqueo.erase(
            remove(vehiculosEnParqueo.begin(), vehiculosEnParqueo.end(), vehiculo),
            vehiculosEnParqueo.end()
        );
        cout << "Parqueo liberado." << endl;
    }
}

bool ControladorJuego::verificarVictoria() {
    return fila->estaVacia();
}

bool ControladorJuego::verificarDerrota() {
    if (parqueosOcupados < numParqueos) return false;
    if (fila->estaVacia()) return false;

    Pasajero primero = fila->obtenerPrimero();
    for (Vehiculo* v : vehiculosEnParqueo) {
        if (v->getColor() == primero.getColor() && !v->estaLleno()) {
            return false;
        }
    }

    return true;
}

Tablero* ControladorJuego::getTablero() const { return tablero; }
vector<Vehiculo*> ControladorJuego::getVehiculos() const { return vehiculos; }
Fila* ControladorJuego::getFila() const { return fila; }
int ControladorJuego::getNumParqueos() const { return numParqueos; }
int ControladorJuego::getParqueosOcupados() const { return parqueosOcupados; }