#ifndef CONTROLADORJUEGO_H
#define CONTROLADORJUEGO_H
#include <vector>

#include "Tablero.h"
#include "Fila.h"
#include "Parqueo.h"
#include "GestorArchivos.h"

class ControladorJuego
{
    private:
    Tablero tablero;
    Fila fila;
    std::vector<Parqueo>parqueos;
    GestorArchivos gestorArchivos;

    public:

    ControladorJuego();

    void IniciarNivel(int nivel);
    void MoverVehiculoTablero();
    void MoverVehiculoParqueo();
    void AbordarPasajero();
    bool ValidarMovimientoTablero();
    bool ValidarMovimientoParqueo();
    bool VerificarParqueo();
    bool VerificarVictoria();

};
#endif