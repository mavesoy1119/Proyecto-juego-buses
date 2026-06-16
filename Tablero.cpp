#include "Tablero.h"
#include <iostream>
using namespace std;

Tablero::Tablero(int auxFilas, int auxColumnas)
    : filas(auxFilas),
      columnas(auxColumnas),
      grid(auxFilas, vector<Vehiculo*>(auxColumnas, nullptr)) {
}

Tablero::~Tablero() {
}

int Tablero::getFilas() const {
    return filas;
}

int Tablero::getColumnas() const {
    return columnas;
}

void Tablero::colocarVehiculo(Vehiculo* vehiculo) {
    int f = vehiculo->getFila();
    int c = vehiculo->getColumna();
    int largo = vehiculo->getLargo();
    char orientacion = vehiculo->getOrientacion();

    for (int i = 0; i < largo; i++) {
        if (orientacion == 'E' || orientacion == 'O') {
            grid[f][c + i] = vehiculo;
        } else {
            grid[f + i][c] = vehiculo;
        }
    }
}

void Tablero::retirarVehiculo(Vehiculo* vehiculo) {
    int f = vehiculo->getFila();
    int c = vehiculo->getColumna();
    int largo = vehiculo->getLargo();
    char orientacion = vehiculo->getOrientacion();

    for (int i = 0; i < largo; i++) {
        if (orientacion == 'E' || orientacion == 'O') {
            grid[f][c + i] = nullptr;
        } else {
            grid[f + i][c] = nullptr;
        }
    }
}

bool Tablero::celdaLibre(int fila, int columna) const {
    return grid[fila][columna] == nullptr;
}

Vehiculo* Tablero::getVehiculo(int fila, int columna) const {
    return grid[fila][columna];
}

void Tablero::mostrarTablero() const {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (grid[i][j] == nullptr) {
                cout << "[ ]";
            } else {
                cout << "[" << grid[i][j]->getColor()[0] << "]";
            }
        }
        cout << endl;
    }
}