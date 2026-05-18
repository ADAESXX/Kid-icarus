#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <queue>
#include "evento.h"



class EventManager {

private:

    std::queue<Evento> colaEventos;

public:

    void push(Evento evento);

    bool hayEventos();

    Evento pop();
};

#endif
