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
