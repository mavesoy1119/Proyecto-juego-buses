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