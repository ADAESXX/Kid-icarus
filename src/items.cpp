//Nombre del archivo: items.cpp
//Descripción: Implementación de la clase Items para el juego Kid Icarus
//Autor: Abigail Escobar
//Fecha: 18/05/2026

#include "items.h"
//Aun no se ha conectado con el programa principal
Items::Items(int x, int y, int tipo)
    : x(x),
      y(y),
      tipo(tipo)
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
//falta implementar la lógica de uso de los items, por ahora solo se muestra el sprite correspondiente
void Items::usar() {    
}