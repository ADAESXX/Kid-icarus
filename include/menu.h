//Nombre del archivo: menu.h
//Descripción: Declaración de la clase Menu para el juego Kid Icarus
//Autor: Abigail Escobar
//Fecha: 16/05/2026
//Estado: Completo

#ifndef MENU_H
#define MENU_H
#include "puntaje.h"

class Menu {
    private:
        //marcador persistente entre partidas
        Puntaje ultimoPuntaje;
        //1→ jugador 
        //2→ IA
        int seleccionarModalidad();
    public:
        //métodos de la clase Menu
        void mostrarMenu();
        void iniciarJuego();
        void instrucciones();
        void mostrarPuntajes();
        
};

#endif