#include "Buseta.h"

Buseta::Buseta(string auxColor, int auxFila, int auxColumna, char auxOrientacion)
    : Vehiculo(auxColor, auxFila, auxColumna, auxOrientacion) {
    largo = 3;
    capacidad = 6;
}

string Buseta::getTipo() const {
    return "Buseta";
}