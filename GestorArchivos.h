/*
Clase: Gestor Archivos
Curso: Fundamentos de Programacion Orientada a Objetos (FPOO)
Universidad del Valle

Documentacion CRC:

Clase: Gestor Archivos

Responsabilidades:
    - Leer y procesar archivos de configuración de niveles que contienen la información del tablero, vehículos, parqueos y pasajeros.
    - Construir el tablero, la fila de pasajeros y los vehículos (Bus, Carro, Buseta) a partir de los datos leídos.
    - Almacenar los objetos creados (tablero, vehículos, fila) para que otras clases puedan acceder a ellos.
    - Proveer métodos getter para acceder al tablero, la lista de vehículos,el número de parqueos y la fila de pasajeros.

Colaboradores:
    - Tablero: Colabora mediante asociación, lo crea con new en cargarArchivos y lo inicializa con las dimensiones leídas 
      del archivo. Luego, usa tablero->colocarVehiculo() para colocar cada vehículo 
      en su posición inicial.
    - Fila: Colabora mediante asociación,Lo crea con new en cargarArchivos. Luego, usa fila->agregarPasajero() para 
      añadir cada pasajero leído del archivo.
    - Vehiculo: Colabora mediante asociación, crea objetos de las clases derivadas (Bus, Carro, Buseta) usando new según 
      el tipo leído del archivo. Los almacena en el vector vehiculos para que 
      otras clases los usen.
    - Bus, Carro, Buseta: Colabora mediante herencia polimórfica. Crea objetos 
      de estos tipos concretos usando new, pero los guarda como punteros a 
      Vehiculo* para aprovechar el polimorfismo.
    - Pasajero: Colabora mediante dependencia local. Crea objetos Pasajero con 
      new temporalmente para agregarlos a la Fila. No los almacena directamente, 
      sino que los pasa a fila->agregarPasajero(), que los copia o almacena.
    - Archivos de texto (ifstream): Colabora mediante dependencia de biblioteca. 
      Usa ifstream para leer el archivo, y istringstream para parsear cada línea.
*/
#ifndef GESTORARCHIVOS_H
#define GESTORARCHIVOS_H
#include "Vehiculo.h"
#include "Bus.h"
#include "Carro.h"
#include "Buseta.h"
#include "Tablero.h"
#include "Fila.h"
#include "Parqueo.h"
#include <vector>
#include <string>
using namespace std;


class GestorArchivos{
    private:
     Tablero* tablero;
     vector<Vehiculo*> vehiculos;
     int numParqueos;
     Fila* fila;


    public:
     GestorArchivos();
     ~GestorArchivos();

     void cargarArchivos(string nombreArchivo);

     Tablero* getTablero() const;

     vector<Vehiculo*> getVehiculos() const;

     vector<Parqueo*> getParqueos() const;

     int getNumParqueos() const;

     Fila* getFila() const;

};

#endif