//Nombre del archivo: jugador.h
//Descripción: Declaración de la clase Jugador para el juego Kid Icarus
//Autor: Abigail Escobar
//Fecha: 16/05/2026

#ifndef JUGADOR_H
#define JUGADOR_H

#include "entidad.h"
#include "mapa.h"

class Jugador : public Entidad {

    private:
        //atributos del jugador
        bool saltando;
        int fuerzaSalto;
        int vidas;
        int puntaje;
        //variables para manejar movimiento suave y colisiones por pixel
        int direccionX;
        float vy;
        float yReal;
        float xReal;
        float vx;
    public:
        //constructor para inicializar el jugador con su posición y sprite
        Jugador(int x, int y);
        //métodos 
        void moverIzquierda(Mapa& mapa);
        void moverDerecha(Mapa& mapa);
        void saltar();
        void disparar();
        void morir();
        //algunas aun no se impplementan
        void recogerCorazon();
        void aplicarGravedad(Mapa& mapa);
        void actualizar(Mapa& mapa) override;
        int getVidas() const;
        int getPuntaje() const;
        int getDireccionX() const { return direccionX; }

};

#endif