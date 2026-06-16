#ifndef CONTROLADORJUEGO_H
#define CONTROLADORJUEGO_H
#include <vector>

#include "Tablero.h"
#include "Fila.h"
#include "Parqueo.h"
#include "GestorArchivos.h"
#include "Vehiculo.h"
#include <vector>
using namespace std;

class ControladorJuego
{
    private:
    Tablero* tablero;
    Fila* fila;
    vector<Parqueo*>parqueos;
    GestorArchivos gestorArchivos;
    vector<Vehiculo*> vehiculos;

    public:

    ControladorJuego();
    ~ControladorJuego();

    void iniciarNivel(int nivel);

    void moverVehiculoParqueo(int indice);

    void moverVehiculoTablero(Vehiculo* vehiculo);

    bool validarMovimientoTablero(Vehiculo* vehiculo);

    bool validarMovimientoParqueo(Parqueo* parqueo);

    void abordarPasajero(Vehiculo* vehiculo);

    bool verificarParqueo();

    bool verificarVictoria();

    bool verificarDerrota();

    Tablero* getTablero() const;
    
    vector<Vehiculo*> getVehiculos() const;

    Fila* getFila() const;
    
    vector<Parqueo*> getParqueos() const;

};  
#endif