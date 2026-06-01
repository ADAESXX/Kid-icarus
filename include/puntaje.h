// Nombre del archivo: puntaje.cpp
// Descripción: Implementación de la clase Puntaje para el juego Kid Icarus
// Autor 1 : Abigail Escobar
//Autor 2: Maria Renée
// Fecha: 18/05/2026
//Estado:completo

#ifndef PUNTAJE_H
#define PUNTAJE_H

class Puntaje {

    private:
    //atributos
        int corazones;
        int vidas;
        int enemigos;
        int puntajeTotal;
        //true cuando ya se jugo al menos una partida
        bool registrado;
        //resultado de la última partida
        bool ultimaVictoria;

    public:

        Puntaje();
        void agregarCorazon();
        void eliminarEnemigo();
        void perderVida();
        void calcularPuntaje();
        void mostrarPuntaje();
        // Carga el resultado real de la última partida (lo llama el menú)
        void setDatos(int corazones, int vidas, int enemigos, int puntaje, bool victoria); 
};

#endif