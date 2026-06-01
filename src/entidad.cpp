//Nombre del archivo: entidad.cpp
//Descripción: Implementación de la clase Entidad, que es la clase base para Jugador y Enemigo en el juego Kid Icarus
//Autor: Abigail Escobar
//Fecha: 18/05/2026
//Estado: completo
#include "entidad.h"
//se incluyen las cabeceras necesarias para la implementación de la clase Entidad, como la clase Mapa para interactuar con el entorno del juego
Entidad::Entidad(int x, int y, std::string sprite)
    : x(x), y(y), vx(0), vy(0), sprite(sprite){}

int Entidad::getX() const {
    return x;
}

int Entidad::getY() const {
    return y;
}

std::string Entidad::getSprite() const {
    return sprite;
}
