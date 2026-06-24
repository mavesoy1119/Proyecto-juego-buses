
/*
Clase: Vehículo
Curso: Fundamentos de Programacion Orientada a Objetos (FPOO)
Universidad del Valle

Documentacion CRC:

Clase: Vehículo

Responsabilidades:
    -Almacena las caracteristicas del vehiculo 
    -Provee metodos para acceder a las caracteristicas del vehivulo
    -Incrementa en 1 la cantidad de pasajeros a bordo cada vez que esta sea menor a la capacidad del vehiculo
    -Verifica que el vehículo esté lleno despues de subir pasajeros
    -Permite mover el vehiculo por el tablero mediante los metodos set de fila y columna
    
Colaboradores:
- Colabora con sus clases derivadas (carro, bus, buseta) mediante herencia, para heredar sus atributos y metodos
*/
#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
using namespace std;

class Vehiculo
{
    protected:
    string color;
    int fila;
    int columna;
    int pasajerosAbordo;
    int largo;
    int capacidad;
    char orientacion;

    public:

    Vehiculo(string auxColor, int auxFila, int auxColumna, char auxOrientacion);
    virtual ~ Vehiculo();
    
    string getColor() const;
    int getFila()const;
    int getColumna()const;
    int getPasajerosAbordo()const;
    int getLargo()const;
    int getCapacidad()const;
    char getOrientacion()const;

    void setFila(int nuevaFila);
    void setColumna(int nuevaColumna);

    bool subirPasajero();
    bool estaLleno() const;

    virtual string getTipo() const = 0;

};

#endif
