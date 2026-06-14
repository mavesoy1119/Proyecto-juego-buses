include "Carro.h"
#ifndef BUS_H
#define BUS_H
class Bus : public Carro {
public:
    Bus();
    void mover() override;
};
