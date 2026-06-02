#ifndef VEHICULO_H
#define VEHICULO_h
#include <string>

class Vehiculo
{
    private:
    const std::string color;
    
    const int capacidad;
    char orientacion;
    int x; //posicion en x
    int y; //posicion en y

    public:

    Vehiculo(const std:: string color,
             const int capacidad,
             char orientacion,
             int x,
             int y);
    
    void moverVehiculo();

    std:: string getcolor();
    char getorientacion();
    int  getcapacidad();
    int getx();
    int gety();

};

#endif