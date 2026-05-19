// Nombre del archivo: puntaje.cpp
// Descripción: Implementación de la clase Puntaje para el juego Kid Icarus
// Autor: Abigail Escobar
// Fecha: 18/05/2026

//Falta aplicarlo a la lógica real del juego
#include <iostream>

using namespace std;

class Puntaje {

    private:
    //atributos
        int corazones;
        int vidas;
        int enemigos;
        int puntajeTotal;

    public:

        Puntaje() {

            corazones = 0;
            vidas = 3;
            enemigos = 0;
            puntajeTotal = 0;
        }

        void agregarCorazon() {
            //cada vez que el jugador recoge un corazón, se incrementa el contador de corazones y se recalcula el puntaje total
            corazones++;
            calcularPuntaje();
        }

        void eliminarEnemigo() {
            //cada vez que el jugador elimina un enemigo, se incrementa el contador de enemigos eliminados y se recalcula el puntaje total
            enemigos++;
            puntajeTotal += 100;
        }

        void perderVida() {
            vidas--;
        }

        void calcularPuntaje() {
            puntajeTotal = (corazones * 10) + (enemigos * 100);
        }

        void mostrarPuntaje() {

            cout << "============================" << endl;
            cout << "         PUNTAJE            " << endl;
            cout << "============================" << endl;
            cout << "Corazones: " << corazones << endl;
            cout << "Vidas: " << vidas << endl;
            cout << "Enemigos eliminados: " << enemigos << endl;
            cout << "Puntaje total: " << puntajeTotal << endl;
            cout << "============================" << endl;
        }
};
