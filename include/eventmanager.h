//Nombre del archivo: eventmanager.h
//Descripción: Declaración de la clase EventManager, que se encarga de gestionar los eventos del juego, como las acciones del jugador y las interacciones con los enemigos y el entorno
//Autor: Abigail Escobar
//Fecha: 18/05/2026
#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

//Se usan colas para almacenar los eventos que ocurren en el juego, lo que permite procesarlos de manera ordenada y eficiente
#include <queue>
#include "evento.h"



class EventManager {

    private:
       //cola para almacenar los eventos que ocurren en el juego
        std::queue<Evento> colaEventos;

    public:

        void push(Evento evento);
        bool hayEventos();
        Evento pop();
};

#endif
