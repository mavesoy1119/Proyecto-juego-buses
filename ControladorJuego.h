#ifndef CONTROLADORJUEGO_H
#define CONTROLADORJUEGO_H

#include "Tablero.h"
#include "Fila.h"
#include "GestorArchivos.h"
#include "Vehiculo.h"
#include <vector>
using namespace std;

class ControladorJuego {
private:
    Tablero* tablero;
    Fila* fila;
    int numParqueos;
    int parqueosOcupados;
    GestorArchivos gestorArchivos;
    vector<Vehiculo*> vehiculos;
    vector<Vehiculo*> vehiculosEnParqueo;

    void moverVehiculoTablero(Vehiculo* vehiculo);
    bool llegoAlBorde(Vehiculo* vehiculo);

public:
    ControladorJuego();
    ~ControladorJuego();

    void iniciarNivel(int nivel);
    void moverVehiculoParqueo(int indice);
    bool validarMovimientoTablero(Vehiculo* vehiculo);
    void abordarPasajero(Vehiculo* vehiculo);
    bool verificarVictoria();
    bool verificarDerrota();

    Tablero* getTablero() const;
    vector<Vehiculo*> getVehiculos() const;
    Fila* getFila() const;
    int getNumParqueos() const;
    int getParqueosOcupados() const;
};

#endif