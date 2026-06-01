//Nombre del archivo: pantallas.cpp
//Descripción: Implementación de las funciones para mostrar las pantallas de inicio, victoria y derrota del juego Kid Icarus  
    //Inicializa ncurses una sola vez para todo el proyecto
//Autor 1: María Renée
//Autor 2: Dulce Granados
//Fecha: 16/05/2026
//Modificaciones realizadas por: Abigail Escobar
//Estado: Completo

#include "menu.h"
#include "pantallas.h"
#include <thread>
#include <chrono>
#include <ncurses.h>
#include <iostream>
#include <cstdlib>

using namespace std;
int main() {
//inicialización de librería ncurses
    //abre el modo pantalla de ncurse
    initscr();
    //no imprime las teclas pulsadas
    noecho();
    //entrega las teclas sin esperar enter
    cbreak();
    //oculta l cursos
    curs_set(0);

    //se usa para permitir los colores
    if(has_colors())
    {
        start_color();
        //Definir el color de fondo para todas las pantallas
        use_default_colors();
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        bkgd(COLOR_PAIR(1));
        clear();
        refresh();
    }



    Pantallas pantallas;
    pantallas.inicio();
    this_thread::sleep_for(chrono::seconds(3));

    Menu menu;
    menu.mostrarMenu();

    endwin();
    return 0;
}