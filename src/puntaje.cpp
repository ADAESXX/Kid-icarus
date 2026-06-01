// Nombre del archivo: puntaje.cpp
// Descripción: Implementación de la clase Puntaje para el juego Kid Icarus
// Autor: Abigail Escobar
// Fecha: 18/05/2026
//Estado. completo

#include "puntaje.h"
#include <ncurses.h>


Puntaje::Puntaje() {

    corazones = 0;
    vidas = 3;
    enemigos = 0;
    puntajeTotal = 0;
    registrado = false;
    ultimaVictoria = false;
}

void Puntaje::agregarCorazon() {
    //cada vez que el jugador recoge un corazón, se incrementa el contador de corazones y se recalcula el puntaje total
    corazones++;
    calcularPuntaje();
}

void Puntaje::eliminarEnemigo() {
    //cada vez que el jugador elimina un enemigo, se incrementa el contador de enemigos eliminados y se recalcula el puntaje total
    enemigos++;
    puntajeTotal += 100;
}

void Puntaje::perderVida() {
    vidas--;
}

void Puntaje::calcularPuntaje() {
    puntajeTotal = (corazones * 10) + (enemigos * 100);
}

void Puntaje::setDatos(int c, int v, int e, int p, bool victoria) {
    corazones = c;
    vidas = v;
    enemigos = e;
    puntajeTotal = p;
    ultimaVictoria = victoria;
    registrado = true;
}


void Puntaje::mostrarPuntaje() {
    mvprintw(5, 30, "============================");
    mvprintw(6, 30, "         PUNTAJE            ");
    mvprintw(7, 30, "============================");
    if(!registrado) {
        mvprintw(9, 30, "Aun no has jugado ninguna partida.");
        mvprintw(10, 30, "Juega para registrar tu puntaje!");
        mvprintw(12, 30, "============================");
        return;
    }
    mvprintw(8,  30, "Ultima partida: %s", ultimaVictoria ? "VICTORIA" : "DERROTA");
    mvprintw(9,  30, "Corazones: %d", corazones);
    mvprintw(10, 30, "Vidas restantes: %d", vidas);
    mvprintw(11, 30, "Enemigos eliminados: %d", enemigos);
    mvprintw(12, 30, "Puntaje total: %d", puntajeTotal);
    mvprintw(13, 30, "============================");
}
