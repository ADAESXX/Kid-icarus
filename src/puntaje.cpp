#include <iostream>

using namespace std;

class Puntaje {

    private:
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

            corazones++;
            calcularPuntaje();
        }

        void eliminarEnemigo() {

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

int main() {

    Puntaje jugador;

    jugador.agregarCorazon();
    jugador.agregarCorazon();

    jugador.eliminarEnemigo();

    jugador.perderVida();

    jugador.mostrarPuntaje();

    return 0;
}