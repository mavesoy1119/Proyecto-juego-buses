#ifndef BUSETA_H
#define BUSETA_H
#include "Vehiculo.h"

class Buseta : public Vehiculo
{
    public:
    
    Buseta(const std::string color,
             int fila,
             int columna,
             int pasajerosAbordo,
             const int largo,
             const int capacidad,
             char orientacion);

};
#endif