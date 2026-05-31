//Nombre del archivo: eventmanager.cpp
//Descripción: Implementación de la clase EventManager para gestionar los eventos del juego Kid Icarus
//Autor: Abigail Escobar
//Fecha: 18/05/2026
//Modificaciones por: Dulce Granados 
//Fecha: 31/05/26

#include "eventmanager.h"
#include "evento.h"

void EventManager::push(Evento evento) {

    colaEventos.push(evento);
}

bool EventManager::hayEventos()
{
    return !colaEventos.empty();
}

Evento EventManager::pop()
{
    Evento evento = colaEventos.front();

    colaEventos.pop();

    return evento;
}