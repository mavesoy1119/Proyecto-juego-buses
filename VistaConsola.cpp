/*
Proyecto: Bus Scape - Traffic Jam
Curso: Fundamentos de Programacion Orientada a Objetos
Universidad del Valle

Descripcion:
Este proyecto busca hacer una recreacion del juego Bus Scape, manejado por consola, permitiendo al jugador elegir su vehiculo, 
con el fin de recoger los pasajeros, entre los diferentes niveles de dificultad.

Autores:
*Juan Angel Mavesoy  (2535293)
*Sarah Alejandra Villota (2437438)
*Juan Miguel Garay (2538076)

Correos:
juan.mavesoy@correounivalle.edu.co
sarah.villota@correounivalle.edu.co
juan.miguel.salcedo@correounivalle.edu.co

fecha: Junio 2026
*/
#include "VistaConsola.h"
#include <iostream>
using namespace std;

VistaConsola::VistaConsola() {
}

void VistaConsola::mostrarMenu() {
    cout << "================================" << endl;
    cout << "=== BUS ESCAPE: TRAFFIC JAM ===" << endl;
    cout << "================================" << endl;
    cout << "1. Jugar" << endl;
    cout << "2. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int VistaConsola::solicitarNivel() {
    int nivel;
    cout << "Seleccione el nivel (1, 2, 3): ";
    cin >> nivel;
    return nivel;
}

void VistaConsola::mostrarTablero(Tablero* tablero, vector<Vehiculo*> vehiculos) {
    cout << endl;

    cout << "     ";
    for (int j = 0; j < tablero->getColumnas(); j++) {
        cout << j << "       ";
    }
    cout << endl;

    for (int i = 0; i < tablero->getFilas(); i++) {
        cout << i << "    ";
        for (int j = 0; j < tablero->getColumnas(); j++) {
            Vehiculo* v = tablero->getVehiculo(i, j);
            if (v == nullptr) {
                cout << ".       ";
            } else {
                int indice = -1;
                for (int k = 0; k < (int)vehiculos.size(); k++) {
                    if (vehiculos[k] == v) {
                        indice = k + 1;
                        break;
                    }
                }

                string tipo = "";
                if (v->getTipo() == "Bus") tipo = "B";
                else if (v->getTipo() == "Carro") tipo = "C";
                else if (v->getTipo() == "Buseta") tipo = "U";

                string flecha = "";
                if (v->getOrientacion() == 'N') flecha = "^";
                else if (v->getOrientacion() == 'S') flecha = "v";
                else if (v->getOrientacion() == 'E') flecha = "->";
                else if (v->getOrientacion() == 'O') flecha = "<-";

                string color = string(1, v->getColor()[0]);

                cout << indice << tipo << flecha << color << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void VistaConsola::mostrarFila(Fila* fila) {
    cout << "Fila de pasajeros: ";
    fila->mostrarFila();
    cout << endl;
}

void VistaConsola::mostrarParqueaderos(int numParqueos, int parqueosOcupados) {
    cout << "Parqueos: ";
    for (int i = 0; i < numParqueos; i++) {
        if (i < parqueosOcupados) {
            cout << "[Ocupado] ";
        } else {
            cout << "[Libre]   ";
        }
    }
    cout << endl;
}

int VistaConsola::solicitarMovimiento() {
    int indice;
    cout << "Seleccione un vehiculo: ";
    cin >> indice;
    return indice;
}

void VistaConsola::mostrarMensaje(string mensaje) {
    cout << mensaje << endl;
}

void VistaConsola::mostrarVictoria() {
    cout << "================================" << endl;
    cout << "      ¡FELICITACIONES!          " << endl;
    cout << "   ¡Todos los pasajeros        " << endl;
    cout << "    fueron recogidos!           " << endl;
    cout << "================================" << endl;
}

void VistaConsola::mostrarDerrota() {
    cout << "================================" << endl;
    cout << "         ¡PERDISTE!             " << endl;
    cout << "  Los parqueos están llenos     " << endl;
    cout << "   y hay un atasco total.       " << endl;
    cout << "================================" << endl;
}