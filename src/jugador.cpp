//Nombre del archivo: jugador.cpp
//Descripción: Implementación de la clase Jugador para el juego Kid Icarus
//Autor 1: Abigail Escobar
//Autor 2: Maria Renée
//Fecha: 16/05/2026
//Modificacones por: Dulce Granados
//Fecha: 31/05/26
//Estado:Completo


#include "jugador.h"

Jugador::Jugador(int x, int y)
    : Entidad(x, y, "P")
{
    saltando = false;
    fuerzaSalto = 0;
    direccionX = 0;

    vidas = 3;
    salud=100;
    puntaje = 0;
    escudo=false;
    invuln= 0;

    xReal = (float)x;
    yReal = y;
    vy = 0;
    vx = 0;
    xInicio = x;
    yInicio = y;
}
void Jugador::setInicio(int nx, int ny) { xInicio = nx; yInicio = ny; }

void Jugador::colocar(int nx, int ny) {
    x = nx; y = ny;
    xReal = (float)nx; yReal = (float)ny;
    vy = 0; saltando = false;
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
    if(invuln > 0) invuln--;
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

//la flecha la crea Juego (hilo del jugador)
void Jugador::disparar() {}

void Jugador::recibirDanio(int d) {
    // todavia invulnerable: ignora el golpe
    if(invuln > 0) return;
    // el escudo absorbe
    if(escudo) { escudo = false; invuln = 30; return; }
    salud -= d;
    invuln = 20;
    if(salud <= 0) morir();
}


void Jugador::morir() {
    vidas--;
    salud = 100;
    x = xInicio; 
    y = yInicio;
    xReal = (float)xInicio; 
    yReal = (float)yInicio;
    vy = 0; 
    saltando = false;
    invuln = 40;
}

void Jugador::recogerCorazon() {
    salud += 20;
    if(salud > 100) salud = 100;
    puntaje += 10;
}

void Jugador::agregarPuntaje(int p) { 
    puntaje += p; 
}
void Jugador::activarEscudo() { 
    escudo = true; 
}

int Jugador::getVidas() const {
    return vidas;
}

int Jugador::getSalud() const {
    return salud;
}

int Jugador::getPuntaje() const {
    return puntaje;
}

bool Jugador::tieneEscudo() const{
    return escudo;
}