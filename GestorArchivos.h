#ifndef GESTORARCHIVOS_H
#define GESTORARCHIVOS_H
#include <string>
#include "Tablero.h"
#include "Vehiculo.h"
#include "Parqueo.h"
#include "Fila.h"

class GestorArchivos
{
    public:
    GestorArchivos();
    ~GestorArchivos();

    void CargarArchivos(std::string nombreArchivo);
    Tablero getTablero();
    Vehiculo getVehiculos();
    Parqueo getParqueos();
    Fila getFila();

};

#endif