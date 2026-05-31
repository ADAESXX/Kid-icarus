//Nombre del archivo: juego.h
//Descripción: Archivo de cabecera para el juego Kid Icarus, que incluye las declaraciones de las clases Jugador, Enemigo, Mapa y Menu
//Autor: Abigail Escobar
//Fecha: 16/05/2026

#ifndef JUEGO_H
#define JUEGO_H

#include "jugador.h"
#include "enemigo.h"
#include "mapa.h"
#include "proyectil.h"
//el vector se usa para almacenar múltiples enemigos y proyectiles en el juego, lo que permite gestionar dinámicamente la cantidad de entidades presentes en el mapa
#include <vector>

class Juego {

    private:
        //atributos
        Jugador jugador;
        std::vector<Enemigo> enemigos;
        std::vector<Proyectil> proyectiles;
        Mapa mapa;
        bool ejecutando;
        bool gano = false;
        bool perdio = false;
        int nivelActual = 1;

    public:
        //PARTE PRINCIPAL DEL JUEGO - fundamental para iniciar el juego, procesar la lógica principal y renderizar los gráficos
        Juego();
        void iniciar();
        void loop();
        void procesarEntrada();
        void actualizar();
        //renderizar es el método encargado de dibujar el estado actual del juego en la pantalla, mostrando al jugador, los enemigos, los proyectiles y el mapa
        void renderizar();
        void cargarNivel(int nivel);
        void terminar();
};

#endif