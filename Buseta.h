/*
Clase: Buseta
Curso: Fundamentos de Programacion Orientada a Objetos (FPOO)
Universidad del Valle

Documentacion CRC:

Clase: Buseta

Responsabilidades:
    -Define el tamaño que ocupa y la capacidad respecto a los pasajeros de una Buseta
    -Hereda y reutiliza los atributos y comportamientos de la  clase vehiculo
    -Implementa el método getTipo para devolver "Buseta", es decir el tipo de vehículo
    
Colaboradores:
- Colabora con la clase vehículo mediante herencia, 
llama al construcctor de vehiculo para iniciar datos como el color, posicion y la orientacion
*/
#ifndef BUSETA_H
#define BUSETA_H
#include "Vehiculo.h"

class Buseta : public Vehiculo
{
    public:
    
     Buseta(string auxColor, int auxFila, int auxColumna, char auxOrientacion);

     string getTipo() const override;
};
#endif