//Nombre del archivo: jugador.cpp
//Descripción: Implementación de la clase Jugador para el juego Kid Icarus
//Autor: Abigail Escobar
//Fecha: 16/05/2026


#include "jugador.h"
#include <iostream>

using namespace std;

Jugador::Jugador(int x, int y) {
    this->x = x;
    this->y = y;
    sprite = "ʚPɞ";
}

void Jugador::moverIzquierda(int dx) {
    
}

void Jugador::moverDerecha(int dx) {

}

void Jugador::saltar() {

}

void Jugador::caer() {
    
}

void Jugador::disparar(int x, int y) {
    
}

void Jugador::morir() {
    
}

void Jugador::recogerCorazon() {
    
}

void Jugador::aplicarGravedad() {
    
}

void Jugador::actualizar() {

}

void Jugador::puntaje() {

}

void Jugador::vidas() {

}

void Jugador::enemigosDerrotados() {

}

void Jugador::zonasNuevas() {

}

int Jugador::getX() {
    return x;
}

int Jugador::getY() {
    return y;
}

string Jugador::getSprite() {
    return sprite;
}