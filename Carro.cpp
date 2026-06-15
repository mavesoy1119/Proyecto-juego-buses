#include "Carro.h"

Carro::Carro(string auxColor, int auxFila, int auxColumna, char auxOrientacion)
    : Vehiculo(auxColor, auxFila, auxColumna, auxOrientacion) {
    largo = 2;
    capacidad = 4;
}

string Carro::getTipo() const {
    return "Carro";
}