#include "VistaConsola.h"
#include "ControladorJuego.h"
#include <iostream>
using namespace std;

int main() {
    VistaConsola vista;
    ControladorJuego controlador;

    int opcion = 0;

    do {
        vista.mostrarMenu();
        cin >> opcion;

        if (opcion == 1) {
            // Solicitar nivel
            int nivel = vista.solicitarNivel();
            controlador.iniciarNivel(nivel);

            bool juegoTerminado = false;

            while (!juegoTerminado) {
                // Mostrar estado del juego
                vista.mostrarTablero(controlador.getTablero(), controlador.getVehiculos());
                vista.mostrarFila(controlador.getFila());
                vista.mostrarParqueaderos(controlador.getNumParqueos(), controlador.getParqueosOcupados());

                // Verificar victoria o derrota
                if (controlador.verificarVictoria()) {
                    vista.mostrarVictoria();
                    juegoTerminado = true;
                    break;
                }

                if (controlador.verificarDerrota()) {
                    vista.mostrarDerrota();
                    juegoTerminado = true;
                    break;
                }

                // Solicitar movimiento
                int indice = vista.solicitarMovimiento();
                controlador.moverVehiculoParqueo(indice - 1);
            }
        }

    } while (opcion != 2);

    cout << "¡Hasta luego!" << endl;
    return 0;
}