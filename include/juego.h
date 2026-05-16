//Nombre del archivo: juego.h
//Descripción: Archivo de cabecera para el juego Kid Icarus, que incluye las declaraciones de las clases Jugador, Enemigo, Mapa y Menu
//Autor: Abigail Escobar
//Fecha: 16/05/2026

#ifndef JUEGO_H
#define JUEGO_H


#include "jugador.h"
#include "enemigo.h"
#include "mapa.h"
#include "menu.h"
#include "pantallas.h"
#include <vector>
using namespace std;

class Juego {

private:
    //Atributos del juego
    Jugador jugador;
    //Los enemigos se almacenan en un vector para poder tener una cantidad variable de ellos en cada nivel
    vector<Enemigo> enemigos;
    Mapa mapa;
    bool ejecutando;
    int nivel;

public:

    Juego();
    void iniciar();
    //La idea es que el juego se ejecute en un bucle hasta que el jugador pierda o gane, por eso se llama a la función loop
    void loop();
    //Obtiene la entrada del usuario (las teclas presionadas)
    void procesarEntrada();
    void actualizar();
    //Renderiza el juego en la pantalla (dibuja al jugador, los enemigos, el mapa, etc.)
    void renderizar();
    void cargarNivel(int numeroNivel);
    void terminar();
};

#endif