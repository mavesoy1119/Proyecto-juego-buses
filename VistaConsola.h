/*
Clase: Vista Consola
Curso: Fundamentos de Programacion Orientada a Objetos (FPOO)
Universidad del Valle

Documentacion CRC:

Clase: Vista Consola

Responsabilidades:
    - Mostrar el menú principal del juego con las opciones disponibles (mostrarMenu).
    - Solicitar al usuario el nivel que desea jugar (solicitarNivel).
    - Mostrar el tablero de juego con todos los vehículos en su posición actual, 
      incluyendo índices, tipos, orientación y colores (mostrarTablero).
    - Mostrar el contenido de la fila de pasajeros con sus colores (mostrarFila).
    - Mostrar el estado de los parqueaderos (ocupados o libres) en formato visual 
      (mostrarParqueaderos).
    - Solicitar al usuario qué vehículo desea mover (solicitarMovimiento).
    - Mostrar mensajes de victoria (mostrarVictoria) y derrota (mostrarDerrota) 
      con formato visual atractivo.

Colaboradores:
    - Tablero: Colabora mediante dependencia por parámetro. Recibe un puntero a 
      Tablero en mostrarTablero para consultar las dimensiones del tablero 
      (getFilas, getColumnas) y obtener los vehículos en cada celda (getVehiculo).
    - Vehiculo: Colabora mediante dependencia por parámetro. Recibe un vector de 
      punteros a Vehiculo en mostrarTablero. Usa métodos de Vehiculo como 
      getTipo(), getOrientacion() y getColor() para mostrar la información 
      visual de cada vehículo.
    - Fila: Colabora mediante dependencia por parámetro. Recibe un puntero a Fila 
      en mostrarFila para mostrar su contenido usando fila->mostrarFila().
*/
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