/*
Clase: Fila
Curso: Fundamentos de Programacion Orientada a Objetos (FPOO)
Universidad del Valle

Documentacion CRC:

Clase: Fila

Responsabilidades:
    -Usa queue que guarda pasajeros para gestion del orden de estos en la cola 
    -Obtiene el primero en la fila, saca al primero de la cola una vez recogido
    -Verificacion de que la fila no esté vacía, despues de recoger el pasajeros

Colaboradores:
Pasajero: Colabora con la clase Pasajero mediante composicion, ya que la clase fila contiene una cola de pasajeros
para gestionar de forma organizada el movimiento de los pasajeros en la fila cuando son recogidos por los vehículos según su color.
*/
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