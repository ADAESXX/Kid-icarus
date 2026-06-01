
//Nombre del archivo: evento.h
//Descripción: Declaración de la estructura Evento y el enum EventoTipo para gestionar los eventos del juego Kid Icarus
//Autor: Abigail Escobar
//Fecha: 18/05/2026
//Estado: completo
#ifndef EVENTO_H
#define EVENTO_H

enum class EventoTipo {

    MOVER_IZQUIERDA,
    MOVER_DERECHA,
    SALTAR,
    DISPARAR,
    SALIR
};
//structura para representar un evento que ocurre en el juego, como el movimiento del jugador, el salto o el disparo
struct Evento {
    EventoTipo tipo;
};

#endif