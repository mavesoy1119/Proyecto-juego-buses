#ifndef FILA_H
#define FILA_H

#include <queue>
#include "Pasajero.h"

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
};

#endif
