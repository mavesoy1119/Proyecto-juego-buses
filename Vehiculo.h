#ifndef VEHICULO_H
#define VEHICULO_h

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
