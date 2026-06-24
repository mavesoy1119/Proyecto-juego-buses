
#ifndef VISTACONSOLA_H
#define VISTACONSOLA_H

#include "Tablero.h"
#include "Fila.h"
#include "Parqueo.h"
#include <vector>
using namespace std;

class VistaConsola
{
 public:
    VistaConsola();
    void mostrarMenu();
    int solicitarNivel();
    void mostrarTablero(Tablero* tablero, vector<Vehiculo*> vehiculos);
    void mostrarFila(Fila* fila);
    void mostrarParqueaderos(int numParqueos, int parqueosOcupados);
    int solicitarMovimiento();
    void mostrarMensaje(string mensaje);
    void mostrarVictoria();
    void mostrarDerrota();
};

#endif