//Nombre del archivo: mapa.cpp
//Descripción: Implementación de la clase Mapa para el juego Kid Icarus
//Autor: Abigail Escobar
//Fecha: 16/05/2026

#include "mapa.h"

Mapa::Mapa(int ancho, int alto, string fondo) {

    this->ancho = ancho;
    this->alto = alto;
    this->fondo = fondo;
}

int Mapa::getAncho() {
    return ancho;
}

int Mapa::getAlto() {
    return alto;
}

string Mapa::getFondo() {
    return fondo;
}