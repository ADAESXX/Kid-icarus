//Nombre del archivo: juego.h
//Descripción: Archivo de cabecera para el juego Kid Icarus, que incluye las declaraciones de las clases Jugador, Enemigo, Mapa y Menu
//Autor: Abigail Escobar
//Fecha: 16/05/2026

#ifndef JUEGO_H
#define JUEGO_H

#include "jugador.h"
#include "enemigo.h"
#include "mapa.h"

#include <vector>

class Juego {

private:

    Jugador jugador;

    std::vector<Enemigo> enemigos;

    Mapa mapa;

    bool ejecutando;

public:

    Juego();

    void iniciar();

    void loop();

    void procesarEntrada();

    void actualizar();

    void renderizar();

    void cargarNivel();

    void terminar();
};

#endif