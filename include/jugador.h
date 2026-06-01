//Nombre del archivo: items.h
//Descripción: Declaración de la clase Items para el juego Kid Icarus
//Autor 1: Abigail Escobar
//Autor 2: Maria Renée
//Fecha: 16/05/2026
//Modificaciones por: Dulce Granados 
//Fecha: 31/05/26
//Estado. completa
//Modificaciones realizadas:
    //agregue la variable de salud, escudo, xinicio y yinicio
    //inclui el metodo de recibir daño, agregar puntaje, activar escudo, etc.

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
        //0-100, si llega a cero pierde
        int salud;
        int puntaje;
        //si está activo absorbe el golpe
        bool escudo;
        //frames de invulnerabilidad tras recibir daño
        int invuln;
        //variables para manejar movimiento suave y colisiones por pixel
        int direccionX;
        float vx;
        float vy;
        float xReal;
        float yReal;
        //Punto de reaparicion del nivel actual
        int xInicio;
        int yInicio;
    
    public:
        //constructor para inicializar el jugador con su posición y sprite
        Jugador(int x, int y);
        //métodos 
        void moverIzquierda(Mapa& mapa);
        void moverDerecha(Mapa& mapa);
        void saltar();
        void disparar();
        void morir();
        void recogerCorazon();
        void recibirDanio(int d);
        void agregarPuntaje(int p);
        void activarEscudo();
        void aplicarGravedad(Mapa& mapa);
        void actualizar(Mapa& mapa) override;

        // fija el punto de reaparicion
        void setInicio(int x, int y);
        //recoloca al jugador
        void colocar(int x, int y);

        int getVidas() const;
        int getSalud() const;
        int getPuntaje() const;
        bool tieneEscudo() const;
        int getDireccionX() const { return direccionX; }
};

#endif