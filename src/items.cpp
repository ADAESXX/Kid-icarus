//Nombre del archivo: items.cpp
//Descripción: Implementación de la clase Items para el juego Kid Icarus
//Autor: Abigail Escobar
//Fecha: 18/05/2026

#include "items.h"


Items::Items(int x, int y, int tipo)
    : x(x),
      y(y),
      tipo(tipo),
      activo(true)
{
    switch(tipo) {
        //Corazon, aumenta vidas
        case 1:
            sprite = "C";
            break;

        //Espada, aumenta puntaje
        case 2:
            sprite = "A";
            break;

        //Escudo, protege al jugador de un ataque enemigo
        case 3:
            sprite = "S";
            break;
    }
}

// muestra el sprite correspondiente
void Items::usar() {

    activo = false;
}

//Obtiene la posición y el sprite del item
int Items::getX() {

    return x;
}

int Items::getY() {

    return y;
}

std::string Items::getSprite() {

    return sprite;
}

int Items::getTipo() {

    return tipo;
}

bool Items::estaActivo() {

    return activo;
}