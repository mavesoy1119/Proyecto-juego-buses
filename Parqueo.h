#ifndef PARQUEO_H
#define PARQUEO_h

class Parqueo
{
    private:
    
    int fila;
    int columna;
    bool ocupado;

    public:

    Parqueo(int fila, int columna);
    
    int getFila();
    int getColumna();
    bool EstaOcupado();

};
#endif 
