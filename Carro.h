/*
Clase: Carro
Curso: Fundamentos de Programacion Orientada a Objetos (FPOO)
Universidad del Valle

Documentacion CRC:

Clase: Carro

Responsabilidades:
    -Define el tamaño que ocupa y la capacidad respecto a los pasajeros de un carro
    -Hereda y reutiliza los atributos y comportamientos de la  clase vehiculo
    -Implementa el método getTipo para devolver "Carro", es decir el tipo de vehículo
    
Colaboradores:
- Colabora con la clase vehículo mediante herencia, 
llama al construcctor de vehiculo para iniciar datos como el color, posicion y la orientacion
*/
#ifndef CARRO_H
#define CARRO_H
#include "Vehiculo.h"

class Carro : public Vehiculo
{
    public:
    
     Carro(string auxColor, int auxFila, int auxColumna, char auxOrientacion);

     string getTipo() const override;

};
#endif