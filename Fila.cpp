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