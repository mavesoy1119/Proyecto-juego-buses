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