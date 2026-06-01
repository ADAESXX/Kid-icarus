//Nombre del archivo: eventmanager.cpp
//Descripción: Implementación de la clase EventManager para gestionar los eventos del juego Kid Icarus
    //Cola productor-consumidor de eventos de entrada 
    //productor → hilo principal que lee el teclado
    //consumidpr → hilo del jugador
    //El acceso a esta cola se protege con el mutex del estado en la clase Juego.
//Autor: Abigail Escobar
//Fecha: 18/05/2026
//Modificaciones por: Dulce Granados 
//Fecha: 31/05/26
//Estado: completo

#include "eventmanager.h"

void EventManager::push(Evento evento) {
    colaEventos.push(evento);
}

bool EventManager::hayEventos(){
    return !colaEventos.empty();
}

Evento EventManager::pop()
{
    Evento evento = colaEventos.front();
    colaEventos.pop();
    return evento;
}