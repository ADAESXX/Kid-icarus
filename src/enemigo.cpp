//Nombre del archivo: enemigo.cpp
//Descripción: Implementación de la clase Enemigo para el juego Kid Icarus
//Autor 1: Abigail Escobar
//Autor 2: Maria Renée
//Fecha: 18/05/2026
//Estado: completo
//Modificaciones: cambie la lógica del mov de los enemigos

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
    framesVol=0;
    volDir=0;
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
    switch(tipo) {
        // CAMINANTE: respeta la gravedad y solo se mueve sobre las plataformas,
        // dando la vuelta al chocar contra una pared o al llegar a un borde.
        case TipoEnemigo::CAMINANTE: {
            // cae si no hay piso
            if(!mapa.esSolido(x, y + 1)) { y++; return; }   
            if(direccion == 1) {
                if(mapa.esSolido(x + 1, y) || !mapa.esSolido(x + 1, y + 1))
                    direccion = -1;
                else
                    x += velocidad;
            } else {
                if(mapa.esSolido(x - 1, y) || !mapa.esSolido(x - 1, y + 1))
                    direccion = 1;
                else
                    x -= velocidad;
            }
            break;
        }

        // VOLADOR: ignora la gravedad. Vuela en horizontal y oscila levemente
        // en vertical para simular el vuelo.
        case TipoEnemigo::VOLADOR: {
            if(direccion == 1) {
                if(mapa.esSolido(x + 1, y)) direccion = -1;
                else x += velocidad;
            } else {
                if(mapa.esSolido(x - 1, y)) direccion = 1;
                else x -= velocidad;
            }
            framesVol++;
            if(framesVol % 10 == 0) {
                int ny = y + volDir;
                if(!mapa.esSolido(x, ny)) y = ny; else volDir = -volDir;
                // limita la amplitud
                if(framesVol % 30 == 0) volDir = -volDir; 
            }
            break;
        }

        // MEDUSA (jefe): permanece fija. Su ataque (lanzar bolas de fuego) lo
        // coordina el hilo de enemigos en la clase Juego, porque necesita
        // acceso a la lista de proyectiles del juego.
        case TipoEnemigo::MEDUSA:
            break;
    }
}

void Enemigo::actualizar(Mapa& mapa) {
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
//se coordina en el juego, pero este es la documentacion del contrato
void Enemigo::atacar() {}


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