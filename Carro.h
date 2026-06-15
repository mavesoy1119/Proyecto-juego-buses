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