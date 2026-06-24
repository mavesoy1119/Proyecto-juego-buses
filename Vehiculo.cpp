/*
Proyecto: Bus Scape - Traffic Jam
Curso: Fundamentos de Programacion Orientada a Objetos
Universidad del Valle

Descripcion:
Este proyecto busca hacer una recreacion del juego Bus Scape, manejado por consola, permitiendo al jugador elegir su vehiculo, 
con el fin de recoger los pasajeros, entre los diferentes niveles de dificultad.

Autores:
*Juan Angel Mavesoy  (2535293)
*Sarah Alejandra Villota (2437438)
*Juan Miguel Garay (2538076)

Correos:
juan.mavesoy@correounivalle.edu.co
sarah.villota@correounivalle.edu.co
juan.miguel.salcedo@correounivalle.edu.co

fecha: Junio 2026
*/
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