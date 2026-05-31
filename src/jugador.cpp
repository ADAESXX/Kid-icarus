//Nombre del archivo: jugador.cpp
//Descripción: Implementación de la clase Jugador para el juego Kid Icarus
//Autor: Abigail Escobar
//Fecha: 16/05/2026


#include "jugador.h"
#include "enemigo.h"

Jugador::Jugador(int x, int y)
    : Entidad(x, y, "P")
{
    saltando = false;
    fuerzaSalto = 0;
    direccionX = 0;

    vidas = 3;
    puntaje = 0;

    yReal = y;
    vy = 0;
    xReal = (float)x;
    vx = 0;
}

void Jugador::moverIzquierda(Mapa& mapa) {
    direccionX = -1;
    if (!saltando) {                      
        if (!mapa.esSolido(x - 1, y)) {
            x -= 1;
            xReal = (float)x;
        }
    }
}

void Jugador::moverDerecha(Mapa& mapa) {
    direccionX = 1;
    if (!saltando) {
        if (!mapa.esSolido(x + 1, y)) {
            x += 1;
            xReal = (float)x;
        }
    }
}

void Jugador::saltar() {
    // solo saltar si estoy en el piso
    if (!saltando && vy == 0) {
        saltando = true;
        vy = -1.6f;     
    }
}

void Jugador::aplicarGravedad(Mapa& mapa) {
    // Indica si hay puso o no
    bool enSuelo = mapa.esSolido(x, y + 1);

    if (!enSuelo) {
        //aplicar gravedad incrementando la velocidad vertical (vy) para simular la caída, con un límite de velocidad terminal para evitar que el jugador caiga demasiado rápido
        vy += 0.35f;            
        if (vy > 1.0f) vy = 1.0f; // velocidad terminal
    } else if (vy >= 0) {
        vy = 0;
        saltando = false;
        yReal = (float)y;       // alinear con la grilla
        xReal = (float)x;
    }
}

void Jugador::actualizar(Mapa& mapa) {
    aplicarGravedad(mapa);
    // movimiento horizontal suave mientras salto, lo que permite al jugador moverse lateralmente con mayor fluidez durante el salto, en lugar de moverse solo por celdas enteras
    if (saltando && direccionX != 0) {
        xReal += 0.45f * direccionX;      
        int destinoX = (int)xReal;

        if (destinoX > x) {
            while (x < destinoX) {
                if (mapa.esSolido(x + 1, y)) { xReal = (float)x; break; }
                x++;
            }
        } else if (destinoX < x) {
            while (x > destinoX) {
                if (mapa.esSolido(x - 1, y)) { xReal = (float)x; break; }
                x--;
            }
        }
    }

    
    // acumular posición real
    yReal += vy;
    int destinoY = (int)yReal;

    // mover celda por celda chequeando colisiones
    if (destinoY > y) {           // cayendo
        while (y < destinoY) {
            if (mapa.esSolido(x, y + 1)) {
                yReal = (float)y;
                vy = 0;
                saltando = false;
                break;
            }
            y++;
        }
    } else if (destinoY < y) {    // subiendo
        while (y > destinoY) {
            if (mapa.esSolido(x, y - 1)) {
                yReal = (float)y;
                vy = 0;            // chocó con techo
                break;
            }
            y--;
        }
    }

}

//implementación del disparo del jugador
void Jugador::disparar() {

    puntaje += 10;
}

void Jugador::morir() {
    vidas--;
    // reiniciar posición del jugador al morir, lo que permite al jugador volver a intentarlo desde un punto de partida conocido después de perder una vida
    x = 3;
    y = 11;
    yReal = 11.0f;
    vy = 0;
    saltando = false;
}

void Jugador::recogerCorazon() {
    vidas++;
}

int Jugador::getVidas() const {
    return vidas;
}

int Jugador::getPuntaje() const {
    return puntaje;
}