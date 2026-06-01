//Nombre del archivo: items.cpp
//Descripción: Implementación de la clase Items para el juego Kid Icarus
//Autor 1: Abigail Escobar
//Autor 2: Maria Renée
//Fecha: 18/05/2026
//Estado: completo
//Modificaciones: elimine lo de esta Activo porque es el juego que lo controla

#include "items.h"

Items::Items(int x, int y, int tipo)
    : x(x),
      y(y),
      tipo(tipo)
{
    switch(tipo) {
        //Corazon, recupera salud / suma puntos
        case 1:
            sprite = "C";
            break;

        //Espada, aumenta puntaje
        case 2:
            sprite = "A";
            break;

        //Escudo, abbsorbe un golpe
        case 3:
            sprite = "S";
            break;
    }
}

// El efecto sucede en el juego, pero este es la documentacion del contrato
void Items::usar() {}

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
