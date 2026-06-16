#ifndef FILA_H
#define FILA_H

#include <queue>
#include "Pasajero.h"
#include <iostream>
using namespace std;

class Fila 
{
private:
    queue<Pasajero> pasajeros;
public:
    Fila();
    void agregarPasajero(Pasajero &auxpasajero);
    Pasajero obtenerPrimero();
    void retirarPrimero();
    bool estaVacia();
    void mostrarFila();
};

#endif