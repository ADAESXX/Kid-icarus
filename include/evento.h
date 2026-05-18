#ifndef EVENTO_H
#define EVENTO_H

enum class EventoTipo {

    MOVER_IZQUIERDA,
    MOVER_DERECHA,
    SALTAR,
    DISPARAR,
    SALIR
};

struct Evento {

    EventoTipo tipo;
};

#endif