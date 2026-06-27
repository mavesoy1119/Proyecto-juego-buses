/*
Clase: ControladorJuego
Curso: Fundamentos de Programacion Orientada a Objetos (FPOO)
Universidad del Valle

Documentacion CRC:

Clase: Controlador Juego

Responsabilidades:
    -Inicializar un nivel, cargando la configuración desde un archivo txt.
    -Validar si un vehículo puede moverse en línea recta hacia el borde del tablero, 
      verificando que todas las celdas en su camino estén libres.
    - Gestionar el estacionamiento de un vehículo (moverVehiculoParqueo).
    - Controlar el proceso de abordaje: mientras el vehículo no esté lleno y haya pasajeros en la fila, comparar colores, si coinciden, subir al pasajero y 
      retirarlo de la fila, si no coinciden, detener el proceso. Si el vehículo se llena, liberar el parqueo.
    - Verificar las condiciones de victoria y derrota
    - Proveer métodos getter para consultar el estado del juego como tablero, fila, 
      vehículos, número de parqueos y parqueos ocupados.
Colaboradores:
- GestorArchivos: Colabora mediante composición, se usa en iniciarNivel para cargar el tablero, la fila, los vehículos y el número de parqueos desde un archivo de nivel
- Tablero: Colabora mediante asociación, se usa para obtener dimensiones del tablero, retirar y colocar vehículos, consultar si una celda está libre
- Fila: Colabora mediante asociación, se usa para verificar si la fila está vacía en verificarVictoria y abordarPasajero,, obtiene y retira el primer pasajero en abordarPasajero     
- Vehiculo: Colabora mediante asociación, se usa para obtener su posición, color, orientación y largo para mover y validar sus movimientos
- Pasajero: Se usa en abordarPasajero y verificarDerrota se obtienen objetos Pasajero de la Fila para consultar su color y compararlo con el color del vehículo
*/
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