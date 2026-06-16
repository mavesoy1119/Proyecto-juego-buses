#include "ControladorJuego.h"
#include <iostream>
using namespace std;

ControladorJuego::ControladorJuego()
    : tablero(nullptr), fila(nullptr) {
}

ControladorJuego::~ControladorJuego() {
}

void ControladorJuego::iniciarNivel(int nivel) {
    string nombreArchivo = "nivel" + to_string(nivel) + ".txt";
    gestorArchivos.cargarArchivos(nombreArchivo);

    tablero = gestorArchivos.getTablero();
    fila = gestorArchivos.getFila();
    parqueos = gestorArchivos.getParqueos();
    vehiculos = gestorArchivos.getVehiculos();
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

bool ControladorJuego::validarMovimientoParqueo(Parqueo* parqueo) {
    return !parqueo->estaOcupado();
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

    Parqueo* parqueoLibre = nullptr;
    for (Parqueo* p : parqueos) {
        if (validarMovimientoParqueo(p)) {
            parqueoLibre = p;
            break;
        }
    }

    if (parqueoLibre == nullptr) {
        cout << "No hay parqueos disponibles." << endl;
        return;
    }

    while (vehiculo->getFila() != parqueoLibre->getFila() ||
           vehiculo->getColumna() != parqueoLibre->getColumna()) {
        moverVehiculoTablero(vehiculo);
    }

    parqueoLibre->ocupar();
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

    if (vehiculo->estaLleno()) {
        for (Parqueo* p : parqueos) {
            if (p->getFila() == vehiculo->getFila() &&
                p->getColumna() == vehiculo->getColumna()) {
                p->liberar();
                cout << "Parqueo liberado." << endl;
                break;
            }
        }
    }
}

bool ControladorJuego::verificarVictoria() {
    return fila->estaVacia();
}

bool ControladorJuego::verificarDerrota() {
    for (Parqueo* p : parqueos) {
        if (!p->estaOcupado()) {
            return false;
        }
    }

    if (fila->estaVacia()) {
        return false;
    }

    Pasajero primero = fila->obtenerPrimero();
    for (Vehiculo* v : vehiculos) {
        if (v->getColor() == primero.getColor() && !v->estaLleno()) {
            return false;
        }
    }

    return true;

}
Tablero* ControladorJuego::getTablero() const { return tablero; }
vector<Vehiculo*> ControladorJuego::getVehiculos() const { return vehiculos; }
Fila* ControladorJuego::getFila() const { return fila; }
vector<Parqueo*> ControladorJuego::getParqueos() const { return parqueos; }