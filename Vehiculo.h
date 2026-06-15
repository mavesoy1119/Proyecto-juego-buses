#ifndef VEHICULO_H
#define VEHICULO_h

#include <string>

class Vehiculo
{
    private:
    const std::string color;
    int fila;
    int columna;
    int pasajerosAbordo;
    const int largo;
    const int capacidad;
    char orientacion;

    public:

    Vehiculo(const std::string color,
             int fila,
             int columna,
             int pasajerosAbordo,
             const int largo,
             const int capacidad,
             char orientacion);
    
    std::string getColor();
    int getFila();
    int getColumna();
    int getPasajerosAbordo();
    int getLargo();
    int getCapacidad();
    char getOrientacion();

    void SubirPasajero();
    bool EstaLleno();

};

#endif
