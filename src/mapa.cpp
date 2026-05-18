//Nombre del archivo: mapa.cpp
//Descripción: Implementación de la clase Mapa para el juego Kid Icarus
//Autor: Abigail Escobar
//Fecha: 16/05/2026

#include "mapa.h"

void Mapa::cargarNivel(
    const std::vector<std::string>& nuevoNivel
) {
    nivel = nuevoNivel;
}

bool Mapa::esSolido(int x, int y) const {

    if(y < 0 || y >= nivel.size())
        return true;

    if(x < 0 || x >= nivel[y].size())
        return true;

    char bloque = nivel[y][x];

    return bloque == '=' || bloque == '#';
}

const std::vector<std::string>& Mapa::getNivel() const {

    return nivel;
}