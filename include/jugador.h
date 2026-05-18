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

        bool saltando;

        int fuerzaSalto;

        int vidas;

        int puntaje;
        bool moviendoIzquierda;

        bool moviendoDerecha;

    public:

        Jugador(int x, int y);

        void moverIzquierda(Mapa& mapa);

        void moverDerecha(Mapa& mapa);

        void saltar();

        void disparar();

        void morir();

        void recogerCorazon();

        void aplicarGravedad(Mapa& mapa);

        void actualizar(Mapa& mapa) override;

        int getVidas() const;

        int getPuntaje() const;
        void setMoviendoIzquierda(bool estado);

        void setMoviendoDerecha(bool estado);
};

#endif