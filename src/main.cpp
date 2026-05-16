//Nombre del archivo: pantallas.cpp
//Descripción: Implementación de las funciones para mostrar las pantallas de inicio, victoria y derrota del juego Kid Icarus    
//Autor 1: María Renée
//Autor 2: Dulce Granados
//Fecha: 16/05/2026
//Modificaciones realizadas por: Abigail Escobar


#include <ncurses.h>

using namespace std;

int main() {
    // Configuración de ncurses para el menú
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    return 0;
}