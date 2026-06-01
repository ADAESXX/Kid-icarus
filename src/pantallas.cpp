//Nombre del archivo: pantallas.cpp
//Descripción: Implementación de las funciones para mostrar las pantallas de inicio, victoria y derrota del juego Kid Icarus    
//Autor: Abigail Escobar
//Fecha: 16/05/2026
//Estado. completo

#include <ncurses.h>
#include <cstring>
#include "pantallas.h"

using namespace std;

void imprimirCentro(int y, const char* texto) {
    //strlen se usa para obtener la longitud del texto, lo que es necesario para calcular la posición horizontal correcta para centrar el texto en la pantalla
    int x = (COLS - strlen(texto)) / 2;
    mvprintw(y, x, "%s", texto);
}

void Pantallas::inicio() {
    
    clear();
    start_color();
    //se define el color de fondo para todas las pantallas
    bkgd(COLOR_PAIR(1));
    clear();
    refresh();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);

    attron(COLOR_PAIR(2));

    int anchoColumnas = 12;
    int espacioLogo = 70;

    int anchoTotal = espacioLogo + (anchoColumnas * 2);

    int inicioX = (COLS - anchoTotal) / 2;

    int xIzq = inicioX;
    int xDer = inicioX + espacioLogo + anchoColumnas;

    // alas
    mvprintw(4, xIzq,  R"( \\    // )");
    mvprintw(5, xIzq,  R"(  \\__//  )");
    mvprintw(6, xIzq,  R"( /|##|\\ )");

    mvprintw(4, xDer,  R"( \\    // )");
    mvprintw(5, xDer,  R"(  \\__//  )");
    mvprintw(6, xDer,  R"( /|##|\\ )");

    // columnas superiores
    mvprintw(7, xIzq, "============");
    mvprintw(8, xIzq, "|==========|");

    mvprintw(7, xDer, "============");
    mvprintw(8, xDer, "|==========|");

    // cuerpo
    for(int i = 9; i < 31; i++) {

        mvprintw(i, xIzq, "|  ||||  |");
        mvprintw(i, xDer, "|  ||||  |");
    }

    // base
    mvprintw(31, xIzq, "|==========|");
    mvprintw(32, xIzq, "============");

    mvprintw(31, xDer, "|==========|");
    mvprintw(32, xDer, "============");

    attroff(COLOR_PAIR(2));


    // LOGO
    const char* logo[] = {

        R"( _  ___ ____    ___ ____    _    ____  _   _ ____ )",
        R"(| |/ (_)  _ \  |_ _/ ___|  / \  |  _ \| | | / ___|)",
        R"(| ' /| | | | |  | | |     / _ \ | |_) | | | \___ \)",
        R"(| . \| | |_| |  | | |___ / ___ \|  _ <| |_| |___) |)",
        R"(|_|\_\_|____/  |___\____/_/   \_\_| \_\\___/|____/)"
    };

    int lineasLogo = sizeof(logo) / sizeof(logo[0]);

    // usar una línea visualmente equilibrada
    int anchoLogo = strlen(logo[0]);
    int xLogo = (COLS - anchoLogo) / 2;

    attron(COLOR_PAIR(1) | A_BOLD);

    for(int i = 0; i < lineasLogo; i++) {

        mvprintw(4 + i, xLogo, "%s", logo[i]);
    }

    attroff(COLOR_PAIR(1) | A_BOLD);

    // subtítulo
    attron(COLOR_PAIR(4) | A_BOLD);

    imprimirCentro(18, "* WELCOME *");

    attroff(COLOR_PAIR(4) | A_BOLD);

    attron(COLOR_PAIR(3));

    imprimirCentro(22, "El reino celestial te necesita");

    attroff(COLOR_PAIR(3));

    attron(COLOR_PAIR(1) | A_BLINK);

    imprimirCentro(28, "Preparando aventura...");

    attroff(COLOR_PAIR(1) | A_BLINK);
    attron(A_BOLD);
    

    refresh();
}

void Pantallas::victoria() {
    //se define el color de fondo para todas las pantallas
    clear();
    start_color();
    bkgd(COLOR_PAIR(1));
    clear();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);


    int xCentro = 50;

    attron(COLOR_PAIR(1) | A_BOLD);

    mvprintw(10, xCentro, R"(__        _____ _   _ )");
    mvprintw(11, xCentro, R"(\ \      / /_ _| \ | |)");
    mvprintw(12, xCentro, R"( \ \ /\ / / | ||  \| |)");
    mvprintw(13, xCentro, R"(  \ V  V /  | || |\  |)");
    mvprintw(14, xCentro, R"(   \_/\_/  |___|_| \_|)");

    mvprintw(18, xCentro - 2, "YOU WIN!");

    attroff(COLOR_PAIR(1) | A_BOLD);

    refresh();
}

void Pantallas::derrota() {

    clear();
    start_color();
    bkgd(COLOR_PAIR(1));
    clear();
    
    init_pair(5, COLOR_RED, COLOR_BLACK);

    int xCentro = 45;

    attron(COLOR_PAIR(5) | A_BOLD);

    const char* gameOver[] = {

        R"(  ____    _    __  __ _____    _____     _______ ____  )",
        R"( / ___|  / \  |  \/  | ____|  / _ \ \   / / ____|  _ \ )",
        R"(| |  _  / _ \ | |\/| |  _|   | | | \ \ / /|  _| | |_) |)",
        R"(| |_| |/ ___ \| |  | | |___  | |_| |\ V / | |___|  _ < )",
        R"( \____/_/   \_\_|  |_|_____|  \___/  \_/  |_____|_| \_\)"
    };
    
    int lineas = sizeof(gameOver) / sizeof(gameOver[0]);
    //usar una línea visualmente equilibrada
    for(int i = 0; i < lineas; i++) {

        mvprintw(10 + i, xCentro, "%s", gameOver[i]);
    }

    mvprintw(18, 58, "GAME OVER");

    attroff(COLOR_PAIR(5) | A_BOLD);

    refresh();
}