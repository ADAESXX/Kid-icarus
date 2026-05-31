//Nombre del archivo: enemigo.cpp
//Descripción: Implementación de la clase Enemigo para el juego Kid Icarus
//Autor: Abigail Escobar
//Fecha: 18/05/2026

#include "enemigo.h"
//se incluyen las cabeceras necesarias para la implementación de la clase Enemigo, como la clase base Entidad y la clase Mapa para interactuar con el entorno del juego
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
    //inicialización de atributos específicos de la clase Enemigo
    direccion = 1;
    framesMovimiento = 0;
    vivo = true;

    switch(tipo) {

        case TipoEnemigo::CAMINANTE:
            sprite = "X";
            break;

        case TipoEnemigo::VOLADOR:
            sprite = "Y";
            break;

        case TipoEnemigo::MEDUSA:
            sprite = "M";
            break;
    }
}

//Se define Enemigo:: para especificar que los métodos son de esa clase
//el Mapa& mapa se pasa como referencia para permitir que el enemigo interactúe con el entorno del juego
void Enemigo::mover(Mapa& mapa) {

    // analiza si hay piso debajo, si no, cae
    if(!mapa.esSolido(x, y + 1)) {
        y++;
        return;
    }

    // si hay piso, intenta avanzar en la dirección actual
    if(direccion == 1) {

        if(mapa.esSolido(x + 1, y) ||
           !mapa.esSolido(x + 1, y + 1)) {
            //cambia direccion hacia la izquierda si encuentra un bloque sólido o un precipicio
            direccion = -1;
        }
        else {

            x += velocidad;
        }
    }
    // si la dirección es -1, intenta avanzar hacia la izquierda
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

    if(!vivo)
        return;

    //contador para controlar la frecuencia de movimientos del enemigo
    framesMovimiento++;

    // mover cada 6 frames
    if(framesMovimiento < 6)
        return;

    //resetea el contador después de mover para mantener un ritmo constante de movimiento
    framesMovimiento = 0;

    mover(mapa);
}

//implementación básica del ataque del enemigo
void Enemigo::atacar() {

    if(!vivo)
        return;
}

// reinicia la posición del enemigo al morir
void Enemigo::morir() {

    vivo = false;
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

bool Enemigo::estaVivo() const {
    return vivo;
}