#include "juego.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Juego::Juego()
    : jugador(10,10), mapa(80,25,".") {

    ejecutando = true;
    nivel = 1;
}

void Juego::iniciar() {

    cargarNivel(1);
    loop();
}

void Juego::loop() {

    while(ejecutando) {

        procesarEntrada();

        actualizar();

        renderizar();
    }
}

void Juego::procesarEntrada() {

    char tecla;
    cin >> tecla;

    switch(tecla) {

        case 'a':
            jugador.moverIzquierda(1);
            break;

        case 'd':
            jugador.moverDerecha(1);
            break;

        case 'w':
            jugador.saltar();
            break;
        
    }
}

void Juego::actualizar() {

}

void Juego::renderizar() {

    system("clear");


    
}

void Juego::cargarNivel(int numeroNivel) {

}

void Juego::terminar() {

    ejecutando = false;
}