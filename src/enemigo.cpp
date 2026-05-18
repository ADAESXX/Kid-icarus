#include "enemigo.h"

Enemigo::Enemigo(
    int x,
    int y,
    TipoEnemigo tipo,
    int valorEnemigo,
    bool aparecido,
    int velocidad
)
: Entidad(x, y, "X"),
  tipo(tipo),
  valorEnemigo(valorEnemigo),
  aparecido(aparecido),
  velocidad(velocidad)
{
    direccion = 1;
    framesMovimiento = 0;

    switch(tipo) {

        case TipoEnemigo::CAMINANTE:
            sprite = "X";
            break;

        case TipoEnemigo::VOLADOR:
            sprite = "\\Y/";
            break;

        case TipoEnemigo::MEDUSA:
            sprite = "(M)";
            break;
    }
}

void Enemigo::mover(Mapa& mapa) {

    // gravedad
    if(!mapa.esSolido(x, y + 1)) {

        y++;

        return;
    }

    if(direccion == 1) {

        if(mapa.esSolido(x + 1, y) ||
           !mapa.esSolido(x + 1, y + 1)) {

            direccion = -1;
        }
        else {

            x += velocidad;
        }
    }
    else {

        if(mapa.esSolido(x - 1, y) ||
           !mapa.esSolido(x - 1, y + 1)) {

            direccion = 1;
        }
        else {

            x -= velocidad;
        }
    }
}

void Enemigo::actualizar(Mapa& mapa) {

    framesMovimiento++;

    // mover cada 6 frames
    if(framesMovimiento < 6)
        return;

    framesMovimiento = 0;

    mover(mapa);
}

void Enemigo::atacar() {
}

void Enemigo::morir() {
    x = 3;
    y = 5;
}

Enemigo::TipoEnemigo Enemigo::getTipo() const {

    return tipo;
}

int Enemigo::getValorEnemigo() const {

    return valorEnemigo;
}

bool Enemigo::getAparecido() const {

    return aparecido;
}

int Enemigo::getVelocidad() const {

    return velocidad;
}