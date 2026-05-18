//Nombre del archivo: menu.cpp
//Descripción: Implementación de la clase Menu para el juego Kid Icarus
//Autor 1: María Renée
//Autor 2: Dulce Granados
//Fecha: 16/05/2026
//Modificaciones realizadas por: Abigail Escobar

#include <iostream>
#include <cstdlib>
#include <limits>
#include <thread>
#include <chrono>
#include <cstring>
#include <ncurses.h>

#include "menu.h"
#include "juego.h"
#include "pantallas.h"

using namespace std;

// Implementación de los métodos de la clase Menu
//Menu:: sirve para indicar que el método pertenece a la clase Menu


void Menu::mostrarMenu() {

    int opcion = 1;
    int tecla;

    keypad(stdscr, TRUE);

    while(true) {

        clear();

        attron(A_BOLD);


        mvprintw(5, 50, "======================================");
        mvprintw(6, 55, "KID ICARUS MENU");
        mvprintw(7, 50, "======================================");

        if(opcion == 1) attron(A_REVERSE);
        mvprintw(9, 55, "1. Iniciar Juego");
        if(opcion == 1) attroff(A_REVERSE);

        if(opcion == 2) attron(A_REVERSE);
        mvprintw(10, 55, "2. Instrucciones");
        if(opcion == 2) attroff(A_REVERSE);

        if(opcion == 3) attron(A_REVERSE);
        mvprintw(11, 55, "3. Puntajes");
        if(opcion == 3) attroff(A_REVERSE);

        if(opcion == 4) attron(A_REVERSE);
        mvprintw(12, 55, "4. Salir");
        if(opcion == 4) attroff(A_REVERSE);

        mvprintw(15, 45, "Usa FLECHAS ARRIBA/ABAJO y ENTER");

        attroff(A_BOLD);

        refresh();

        tecla = getch();

        switch(tecla) {

            case KEY_UP:
                opcion--;
                if(opcion < 1)
                    opcion = 4;
                break;

            case KEY_DOWN:
                opcion++;
                if(opcion > 4)
                    opcion = 1;
                break;

            case 10:

                switch(opcion) {

                    case 1:
                        iniciarJuego();
                        break;

                    case 2:
                        instrucciones();
                        break;

                    case 3:
                        mostrarPuntajes();
                        break;

                    case 4:
                        clear();
                        mvprintw(10, 55, "Saliendo del juego...");
                        refresh();
                        napms(1500);
                        return;
                }
                break;
        }
    }
}
/////////////////////////////////////////////FALTA ESTE
void Menu::iniciarJuego() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    clear();
    mvprintw(10, 55, "Iniciando juego...");
    refresh();
    this_thread::sleep_for(chrono::seconds(2));
    clear();
    Juego juego;
    juego.iniciar();

    endwin();
}

void Menu::instrucciones() {

    clear();

    start_color();

    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);

    const char* logo[] =

   {
	R"( _  ___ ____    ___ ____    _    ____  _   _ ____ )",
        R"(| |/ (_)  _ \  |_ _/ ___|  / \  |  _ \| | | / ___|)",
        R"(| ' /| | | | |  | | |     / _ \ | |_) | | | \___ \)",
        R"(| . \| | |_| |  | | |___ / ___ \|  _ <| |_| |___) |)",
        R"(|_|\_\_|____/  |___\____/_/   \_\_| \_\\___/|____/)"
    };
    int lineasLogo = sizeof(logo) / sizeof(logo[0]);

    int anchoLogo = strlen(logo[0]);
    int xLogo = (COLS - anchoLogo) / 3;

     attron(COLOR_PAIR(1) | A_BOLD);

    for(int i = 0; i < lineasLogo; i++)
    {
        mvprintw(2 + i, xLogo, "%s", logo[i]);
    }

    attroff(COLOR_PAIR(1) | A_BOLD);

    
    //bordes (columnas y alas)
    attron(COLOR_PAIR(2));

    //lados de columnas
    int xIzq = 8;
    int xDer = 125;

    //alas 
    mvprintw(7, xIzq,  R"( \\    // )");
    mvprintw(8, xIzq,  R"(  \\__//  )");
    mvprintw(9, xIzq,  R"( /|##|\\ )");

    mvprintw(7, xDer,  R"( \\    // )");
    mvprintw(8, xDer,  R"(  \\__//  )");
    mvprintw(9, xDer,  R"( /|##|\\ )");

    //parte de arriba de las columnas
    mvprintw(10, xIzq, "============");
    mvprintw(11, xIzq, "|==========|");

    mvprintw(10, xDer, "============");
    mvprintw(11, xDer, "|==========|");

    //cuerpo de las columnas
    for(int i = 12; i < 34; i++)
    {
    mvprintw(i, xIzq, "|  ||||  |");
    mvprintw(i, xDer, "|  ||||  |");
   }

    //parte de abajo de las columnas
    mvprintw(34, xIzq, "|==========|");
    mvprintw(35, xIzq, "============");

    mvprintw(34, xDer, "|==========|");
    mvprintw(35, xDer, "============");

    attroff(COLOR_PAIR(2));

    
    attron(COLOR_PAIR(4) | A_BOLD);

    mvprintw(10, 70, "INSTRUCCIONES");

    attroff(COLOR_PAIR(4) | A_BOLD);

    
    attron(COLOR_PAIR(3));

    mvprintw(13, 60, "¡Bienvenido al mundo de Pit!");
    mvprintw(15, 25, "Ahora que estas dentro, debes saber que hay muchos obstaculos y criaturas en el inframundo." );
    mvprintw(16, 25, "Tu misión será abrirte camino esquivando y atacando a tus enemigos para alcanzar la cima");
    mvprintw(17, 25, "Recurda que tu también puedes atacarlos disparando tus defensas en su contra");
    mvprintw(18, 25, "Avanza en cada nivel evitando que los enemigos te toquen, si lo hacen, perderas vida");
    mvprintw(19, 25, "Si llegas a cero deberás reiniciar el juego. Si logras llegar a la cima, avanzarás de nivel");
 

    mvprintw(22, 60, "Usa estas teclas para jugar: ");
    mvprintw(26, 60, "A       -> Mover izquierda");
    mvprintw(27, 60, "D       -> Mover derecha");
    mvprintw(28, 60, "W       -> Saltar");
    mvprintw(29, 60, "SPACE   -> Disparar");
    mvprintw(30, 60, "Q       -> Salir");

    mvprintw(32, 55, "¡Derrota enemigos y alcanza el Olimpo!");

    attroff(COLOR_PAIR(3));

    
    attron(COLOR_PAIR(1) | A_BLINK);

    mvprintw(33, 60, "Presiona ENTER para continuar");

    attroff(COLOR_PAIR(1) | A_BLINK);

    refresh();

    int tecla;

    while((tecla = getch()) != 10)
    {
    }
    
}

void Menu::mostrarPuntajes() {

    clear();
    attron(A_BOLD);
    mvprintw(10, 60, "============= PUNTAJES ==============");
    mvprintw(12, 60, "Jugador 1: 1500 puntos");
    mvprintw(13, 60, "Jugador 2: 1200 puntos");
    attroff(A_BOLD);
    mvprintw(16, 60, "Presiona ENTER para continuar");
    refresh();
    //espera a que el usuario presione ENTER para continuar
    while(getch() != 10)
    {
    }
}