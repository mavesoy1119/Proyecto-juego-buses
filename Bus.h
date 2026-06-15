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