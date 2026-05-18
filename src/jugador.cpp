//Nombre del archivo: jugador.cpp
//Descripción: Implementación de la clase Jugador para el juego Kid Icarus
//Autor: Abigail Escobar
//Fecha: 16/05/2026


#include "jugador.h"

Jugador::Jugador(int x, int y)
    : Entidad(x, y, "P")
{
    saltando = false;

    fuerzaSalto = 0;

    vidas = 3;

    puntaje = 0;
    moviendoIzquierda = false;
    moviendoDerecha = false;
}

void Jugador::moverIzquierda(Mapa& mapa) {

    if(!mapa.esSolido(x - 1, y)) {

        x -= 1;
    }
}

void Jugador::moverDerecha(Mapa& mapa) {

    if(!mapa.esSolido(x + 1, y)) {

        x += 1;
    }
}

void Jugador::saltar() {

    if(!saltando) {

        saltando = true;

        vy = -3;
    }
}

void Jugador::aplicarGravedad(Mapa& mapa) {

    if(!mapa.esSolido(x, y + 1)) {

        // gravedad suave
        if(vy < 1)
            vy++;
    }
    else {

        if(vy > 0)
            vy = 0;

        saltando = false;
    }
}

void Jugador::actualizar(Mapa& mapa) {

    aplicarGravedad(mapa);

    // movimiento horizontal continuo
    if(moviendoDerecha) {

    int velocidad = saltando ? 2 : 1;

    if(!mapa.esSolido(x + velocidad, y)) {

        x += velocidad;
    }
}

if(moviendoIzquierda) {

    int velocidad = saltando ? 2 : 1;

    if(!mapa.esSolido(x - velocidad, y)) {

        x -= velocidad;
    }
}

    // movimiento vertical
    if(!mapa.esSolido(x, y + vy)) {

        y += vy;
    }
    else {

        vy = 0;
    }
}

void Jugador::disparar() {
}

void Jugador::morir() {
}

void Jugador::recogerCorazon() {

    vidas++;
}

int Jugador::getVidas() const {

    return vidas;
}

int Jugador::getPuntaje() const {

    return puntaje;
}

void Jugador::setMoviendoIzquierda(bool estado) {

    moviendoIzquierda = estado;
}

void Jugador::setMoviendoDerecha(bool estado) {

    moviendoDerecha = estado;
}