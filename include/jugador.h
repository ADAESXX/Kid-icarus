//Nombre del archivo: jugador.h
//Descripción: Declaración de la clase Jugador para el juego Kid Icarus
//Autor: Abigail Escobar
//Fecha: 16/05/2026

#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
using namespace std;

class Jugador {
    //Atributos del jugador
    private:
        int x;
        int y;
        string sprite;
    //Métodos del jugador
    public:
        //Constructor para inicializar el jugador con su posición y sprite
        Jugador(int x, int y);
        //movimientos
        void moverIzquierda(int dx);
        void moverDerecha(int dy);
        void saltar();
        void caer();
        //Acciones del jugador
        void disparar(int x, int y);
        void morir();
        void recogerCorazon();
        //Gravedad y actualización
        void aplicarGravedad();
        void actualizar();
        //Informacion importante del jugador
        void puntaje();
        void vidas();
        void enemigosDerrotados();
        void zonasNuevas();
        //Getters para obtener la posición y el sprite del jugador
        int getX();
        int getY();

};
//Constructor de la clase Jugador
#endif