#include "juego.h"
#include <ncurses.h>

Juego::Juego()
    : jugador(3, 11)
{
    ejecutando = true;
}

void Juego::iniciar() {

    cargarNivel();

    loop();
}

void Juego::loop() {
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    while(ejecutando) {

        procesarEntrada();

        actualizar();

        renderizar();

        napms(16);
    }
}

void Juego::procesarEntrada() {

    int tecla = getch();

    // reset inputs
    jugador.setMoviendoIzquierda(false);
    jugador.setMoviendoDerecha(false);

    switch(tecla) {

        case 'a':
            jugador.setMoviendoIzquierda(true);
            break;

        case 'd':
            jugador.setMoviendoDerecha(true);
            break;

        case 'w':
            jugador.saltar();
            break;

        case 'q':
            terminar();
            break;
    }
}

void Juego::actualizar() {

    jugador.actualizar(mapa);

    for(auto& enemigo : enemigos) {

        enemigo.actualizar(mapa);

        // colisión enemigo
        if(jugador.getX() == enemigo.getX() &&
           jugador.getY() == enemigo.getY()) {

            jugador.morir();
        }
    }

    // META
    const auto& nivel = mapa.getNivel();

    if(nivel[jugador.getY()][jugador.getX()] == 'G') {

        terminar();
    }
}

void Juego::renderizar() {

    clear();

    const auto& nivel = mapa.getNivel();

    for(int y = 0; y < nivel.size(); y++) {

        mvprintw(y, 0, "%s", nivel[y].c_str());
    }

    mvprintw(
        jugador.getY(),
        jugador.getX(),
        "%s",
        jugador.getSprite().c_str()
    );

    for(auto& enemigo : enemigos) {

        mvprintw(
            enemigo.getY(),
            enemigo.getX(),
            "%s",
            enemigo.getSprite().c_str()
        );
    }

    refresh();
}

void Juego::cargarNivel() {

    mapa.cargarNivel({

        "============================================================",
        "#                                                          #",
        "#                                              G           #",
        "#                                        ========          #",
        "#                                                          #",
        "#                           ========                       #",
        "#                                                          #",
        "#                 ========                                 #",
        "#                                                          #",
        "#        ========                                          #",
        "#                                                          #",
        "#                                                          #",
        "#                                                          #",
        "============================================================"

    });

    enemigos.clear();

    enemigos.push_back(
        Enemigo(
            20,
            8,
            Enemigo::TipoEnemigo::CAMINANTE,
            100,
            true,
            1
        )
    );

    enemigos.push_back(
        Enemigo(
            38,
            5,
            Enemigo::TipoEnemigo::CAMINANTE,
            100,
            true,
            1
        )
    );
}

void Juego::terminar() {

    ejecutando = false;
}