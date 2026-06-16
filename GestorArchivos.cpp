#include "GestorArchivos.h"
#include "Pasajero.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

GestorArchivos::GestorArchivos()
    : tablero(nullptr), fila(nullptr) {
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

    
    int numParqueos;
    archivo >> numParqueos;

    string linea;
    getline(archivo, linea);


   
    for (int i = 0; i < numParqueos; i++) {
        getline(archivo, linea);
        istringstream ss(linea);
        string tipo;
        int f, c;
        ss >> tipo >> f >> c;
        Parqueo* p = new Parqueo(f, c);
        parqueos.push_back(p);
    }

    
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
vector<Parqueo*> GestorArchivos::getParqueos() const { return parqueos; }
Fila* GestorArchivos::getFila() const { return fila; }