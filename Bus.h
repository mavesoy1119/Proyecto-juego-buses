#ifndef BUS_H
#define BUS_H
#include "Vehiculo.h"

class Bus : public Vehiculo
{
    public:
    
    Bus(const std::string color,
             int fila,
             int columna,
             int pasajerosAbordo,
             const int largo,
             const int capacidad,
             char orientacion);

};
#endif