//Nombre del archivo: eventmanager.cpp
//Descripción: Implementación de la clase EventManager para gestionar los eventos del juego Kid Icarus
//Autor: Abigail Escobar
//Fecha: 18/05/2026

#include "eventmanager.h"

void EventManager::push(Evento evento) {

    colaEventos.push(evento);
}