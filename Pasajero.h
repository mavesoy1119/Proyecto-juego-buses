/*
Clase: Pasajero
Curso: Fundamentos de Programacion Orientada a Objetos (FPOO)
Universidad del Valle

Documentacion CRC:

Clase: Pasajero

Responsabilidades:
    -Crea objetos pasajero, que tienen un color predeterminado
    -Almacena y Provee el color del pasajero para que otras clases como Fila, puedan consultarlo

Colaboradores:
Ninguno

*/
#ifndef PASAJERO_H
#define PASAJERO_H
#include <string>
using namespace std;

class Pasajero {
private:
    string color;
public:
    Pasajero(string auxcolor);
    string getColor();
};

#endif