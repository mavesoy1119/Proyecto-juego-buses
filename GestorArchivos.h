#ifndef GESTORARCHIVOS_H
#define GESTORARCHIVOS_H
#include "Vehiculo.h"
#include "Bus.h"
#include "Carro.h"
#include "Buseta.h"
#include "Tablero.h"
#include "Fila.h"
#include "Parqueo.h"
#include <vector>
#include <string>
using namespace std;


class GestorArchivos{
    private:
     Tablero* tablero;
     vector<Vehiculo*> vehiculos;
     vector<Parqueo*> parqueos;
     Fila* fila;


    public:
     GestorArchivos();
     ~GestorArchivos();

     void cargarArchivos(string nombreArchivo);

     Tablero* getTablero() const;

     vector<Vehiculo*> getVehiculos() const;

     vector<Parqueo*> getParqueos() const;

     Fila* getFila() const;

};

#endif