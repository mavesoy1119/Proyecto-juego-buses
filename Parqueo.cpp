#include "Parqueo.h"

Parqueo::Parqueo(int auxFila, int auxColumna)
    : fila(auxFila),
      columna(auxColumna),
      ocupado(false) {
}

int Parqueo::getFila() const {
    return fila;
}

int Parqueo::getColumna() const {
    return columna;
}

bool Parqueo::estaOcupado() const {
    return ocupado;
}

void Parqueo::ocupar() {
    ocupado = true;
}

void Parqueo::liberar() {
    ocupado = false;    
}