/*
Clase: Bus
Curso: Fundamentos de Programacion Orientada a Objetos (FPOO)
Universidad del Valle

Documentacion CRC:

Clase: Bus

Responsabilidades:
    -Define el tamaño que ocupa y la capacidad respecto a los pasajeros de un bus
    -Hereda y reutiliza los atributos y comportamientos de la  clase vehiculo
    -Implementa el método getTipo para devolver "Bus", es decir el tipo de vehículo
    
Colaboradores:
- Colabora con la clase vehículo mediante herencia, 
llama al construcctor de vehiculo para iniciar datos como el color, posicion y la orientacion
*/
#ifndef BUS_H
#define BUS_H
#include "Vehiculo.h"

class Bus : public Vehiculo
{
    public:
    
     Bus(string color, int fila, int columna, char orientacion);
     string getTipo() const override;
};
#endif