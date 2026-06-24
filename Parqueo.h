/*
Clase: Parqueo
Curso: Fundamentos de Programacion Orientada a Objetos (FPOO)
Universidad del Valle

Documentacion CRC:

Clase: Parqueo

Responsabilidades:
    -Almacenar su posicion en el tablero con fila y columna 
    -Provee metodos para consultar el estado actual el estado del parqueadero (estaOcupado())
    -Gestiona el estado de ocupacion del parqueadero, siendo ocupado=true cuando el vehiculo se estaciona y ocupado=true cuando este se libera

Colaboradores:
-Ninguno
*/
#ifndef PARQUEO_H
#define PARQUEO_H

class Parqueo
{
    private:
    
    int fila;
    int columna;
    bool ocupado;

    public:

     Parqueo(int fila, int columna);
    
     int getFila() const;
     int getColumna() const;
     bool estaOcupado() const;

     void ocupar();
     void liberar();

};
#endif 
