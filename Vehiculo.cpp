#include "Vehiculo.h"

Vehiculo::Vehiculo(string auxColor, int auxFila, int auxColumna, char auxOrientacion)
   :color(auxColor),
   fila(auxFila),
   columna(auxColumna),
   orientacion(auxOrientacion),
   pasajerosAbordo(0),
   largo(0),
   capacidad(0){
   }

Vehiculo::~Vehiculo() {}

string Vehiculo::getColor() const{ return color; }
int Vehiculo::getFila() const{ return fila; }
int Vehiculo::getColumna() const{ return columna; }
char Vehiculo::getOrientacion() const{ return orientacion; }
int Vehiculo::getLargo() const{ return largo; }
int Vehiculo::getCapacidad() const{ return capacidad; }
int Vehiculo::getPasajerosAbordo() const{ return pasajerosAbordo; }

void Vehiculo::setFila(int nuevaFila) { fila = nuevaFila; }
void Vehiculo::setColumna(int nuevaColumna) { columna = nuevaColumna; }

bool Vehiculo::subirPasajero(){
    if (pasajerosAbordo < capacidad) {
        pasajerosAbordo++;
        return true;
    }
    return false;
}

bool Vehiculo::estaLleno() const {
    return pasajerosAbordo >= capacidad;
}