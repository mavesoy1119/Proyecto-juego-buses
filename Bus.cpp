#include "Bus.h"
Bus::Bus(string auxColor, int auxFila, int auxColumna, char auxOrientacion)
    : Vehiculo(auxColor, auxFila, auxColumna, auxOrientacion) {
    largo = 5;
    capacidad = 10;
}

string Bus::getTipo() const {
    return "Bus";
}