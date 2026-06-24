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
#include "GestorArchivos.h"
#include "Pasajero.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

GestorArchivos::GestorArchivos()
    : tablero(nullptr), fila(nullptr), numParqueos(0) {
}

GestorArchivos::~GestorArchivos() {
}

void GestorArchivos::cargarArchivos(string nombreArchivo) {
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "Error: no se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }


    int filas, columnas;
    archivo >> filas >> columnas;
    tablero = new Tablero(filas, columnas);
    fila = new Fila();

    // Leer número de parqueos
    archivo >> numParqueos;

    string linea;
    getline(archivo, linea); // consumir salto de línea

    // Leer vehículos y pasajeros
    while (getline(archivo, linea)) {
        if (linea == "PASAJEROS") {
            getline(archivo, linea);
            istringstream ss(linea);
            string color;
            while (ss >> color) {
                Pasajero* p = new Pasajero(color);
                fila->agregarPasajero(*p);
            }
            break;
        }

        istringstream ss(linea);
        string tipo, color;
        int f, c;
        char orientacion;
        ss >> tipo >> color >> f >> c >> orientacion;

        Vehiculo* v = nullptr;
        if (tipo == "Bus") {
            v = new Bus(color, f, c, orientacion);
        } else if (tipo == "Carro") {
            v = new Carro(color, f, c, orientacion);
        } else if (tipo == "Buseta") {
            v = new Buseta(color, f, c, orientacion);
        }

        if (v != nullptr) {
            vehiculos.push_back(v);
            tablero->colocarVehiculo(v);
        }
    }

    archivo.close();
}

Tablero* GestorArchivos::getTablero() const { return tablero; }
vector<Vehiculo*> GestorArchivos::getVehiculos() const { return vehiculos; }
int GestorArchivos::getNumParqueos() const { return numParqueos; }
Fila* GestorArchivos::getFila() const { return fila; }