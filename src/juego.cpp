#include "juego.h"
#include "pantallas.h"
#include <algorithm>
#include <cmath>
#include <ncurses.h>

Juego::Juego()
//inicializa el jugador en la posición (3, 14) con su sprite correspondiente, lo que establece el punto de partida para el jugador en el mapa del juego
    : jugador(3, 14)
{
    ejecutando = true;
}

void Juego::iniciar() {

    cargarNivel();
    loop();
    cargarNivel();
    loop();

    Pantallas pantallas;
    if (gano)    pantallas.victoria();
    else if (perdio) pantallas.derrota();

    refresh();
    nodelay(stdscr, FALSE);
    getch();
}

void Juego::loop() {
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    while(ejecutando) {

        procesarEntrada();
        actualizar();
        renderizar();
        //velocidad del juego
        napms(16);
    }
}

void Juego::procesarEntrada() {
    //getch() se usa para capturar la entrada del usuario, lo que permite al jugador controlar al personaje principal y realizar acciones como moverse, saltar o disparar durante el juego
    int tecla = getch();
    //si no se presiona ninguna tecla, getch() devuelve ERR, lo que permite que el juego continúe ejecutándose sin bloquearse esperando una entrada del usuario
    if(tecla == ERR) {
        return;
    }

    switch(tecla) {

        case 'a':
            jugador.moverIzquierda(mapa);
            break;

        case 'd':
            jugador.moverDerecha(mapa);
            break;

        case 'w':
            jugador.saltar();
            break;
        case ' ':  
            {
                //Se determina la direccion del disparo basandose en la direccion del jugador
                int dir = (jugador.getDireccionX() == 0) ? 1 : jugador.getDireccionX();
                proyectiles.push_back(Proyectil(jugador.getX() + dir, jugador.getY(), dir));
            }
            break;
        case 'q':
            terminar();
            break;
    }
}

void Juego::actualizar() {
    //Acrualiza el juego
    jugador.actualizar(mapa);

    for (auto& enemigo : enemigos) {
        //aparece el enemigo en el mapa, lo que permite que el enemigo comience a interactuar con el jugador y el entorno del juego
        enemigo.actualizar(mapa);
        //colision entre jugador y enemigo
        int dx = std::abs(jugador.getX() - enemigo.getX());
        int dy = std::abs(jugador.getY() - enemigo.getY());

        if (dx <= 1 && dy == 0) {
            jugador.morir();
        }
    }

    // proyectiles
    for (auto& p : proyectiles) {
        if (!p.estaActivo()) continue;
        p.mover();
        if (mapa.esSolido(p.getX(), p.getY())) { p.desactivar(); continue; }
        for (auto& e : enemigos) {
            if (std::abs(p.getX() - e.getX()) <= 1 && p.getY() == e.getY()) {
                e.morir();
                p.desactivar();
                break;
            }
        }
    }

    proyectiles.erase(
        std::remove_if(proyectiles.begin(), proyectiles.end(),
            [](const Proyectil& p) { return !p.estaActivo(); }),
        proyectiles.end()
    );

    // meta
    const auto& nivel = mapa.getNivel();
    if (nivel[jugador.getY()][jugador.getX()] == 'G') {
        gano = true;
        ejecutando = false;
    }

    if (jugador.getVidas() <= 0) {
        perdio = true;
        ejecutando = false;
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
    for (const auto& p : proyectiles) {
        if (p.estaActivo())
            mvprintw(p.getY(), p.getX(), "%s", p.getSprite().c_str());
    }
    refresh();
}

void Juego::cargarNivel() {

    mapa.cargarNivel({

        "============================================================",
        "#                                                          #",
        "#                                                          #",
        "#                                                          #",
        "#                                                          #",
        "#                                              G           #",
        "#                                     ===========          #",
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