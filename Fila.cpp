/*
Proyecto: Bus Scape - Traffic Jam
Curso: Fundamentos de Programacion Orientada a Objetos
Universidad del Valle

Descripcion:
Este proyecto busca hacer una recreacion del juego Bus Scape, manejado por consola, permitiendo al jugador elegir su vehiculo, 
con el fin de recoger los pasajeros, entre los diferentes niveles de dificultad.

Autores:
*Juan Angel Mavesoy  (2535293)
*Sarah Alejandra Villota (2437438)
*Juan Miguel Garay (2538076)

Correos:
juan.mavesoy@correounivalle.edu.co
sarah.villota@correounivalle.edu.co
juan.miguel.salcedo@correounivalle.edu.co

fecha: Junio 2026
*/
#include "Fila.h"

Fila::Fila(){
}
void Fila::agregarPasajero(Pasajero &auxpasajero){
    pasajeros.push(auxpasajero);
}

Pasajero Fila::obtenerPrimero(){
    return pasajeros.front();
}

void Fila::retirarPrimero(){
    pasajeros.pop();
}

bool Fila::estaVacia(){
    return pasajeros.empty();
}
void Fila::mostrarFila() {
    queue<Pasajero> copia = pasajeros;
    while (!copia.empty()) {
        cout << copia.front().getColor() << " ";
        copia.pop();
    }
}