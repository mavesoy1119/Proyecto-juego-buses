/*
Clase: Tablero
Curso: Fundamentos de Programacion Orientada a Objetos (FPOO)
Universidad del Valle

Documentacion CRC:

Clase: Tablero

Responsabilidades:
    -
Colaboradores:
-
*/
#ifndef TABLERO_H
#define TABLERO_H

#include "Vehiculo.h"
#include <vector>
using namespace std;

class Tablero
{
    private:

    int filas;
    int columnas;
    vector<vector<Vehiculo*>> grid;


    public:

    Tablero(int auxFilas, int auxColumnas);
    ~Tablero();
    
    int getFilas() const;
    int getColumnas() const;

    void colocarVehiculo(Vehiculo* vehiculo);
    void retirarVehiculo(Vehiculo* vehiculo);

    bool celdaLibre(int fila, int columna) const;
    Vehiculo* getVehiculo(int fila, int columna) const;

    void mostrarTablero() const;
    
};

#endif