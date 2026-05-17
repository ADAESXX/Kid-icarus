#include "enemigo.h"
#include <iostream>

using namespace std;

Enemigo::Enemigo(int x, int y, int tipo, int valorEnemigo, bool aparecido, int velocidad) {

    this->x = x;
    this->y = y;
    this->tipo = tipo;
    this->valorEnemigo = valorEnemigo;
    this->aparecido = aparecido;
    this->velocidad = velocidad;

    sprite = "M";
}

void Enemigo::mover() {
    
}

void Enemigo::atacar() {
    
}

void Enemigo::morir() {
    
}

int Enemigo::getX() {
    return x;
}

int Enemigo::getY() {
    return y;
}

int Enemigo::getTipo() {
    return tipo;
}

int Enemigo::getValorEnemigo() {
    return valorEnemigo;
}

string Enemigo::getSprite() {
    return sprite;
}

bool Enemigo::getAparecido() {
    return aparecido;
}

int Enemigo::getVelocidad() {
    return velocidad;
}