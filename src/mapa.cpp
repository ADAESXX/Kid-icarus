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
//Verifica si hay limites (paredes o piso)
bool Mapa::esSolido(int x, int y) const {
    //verifica limites del mapa
    if(y < 0 || y >= nivel.size())
        return true;
    //verifica limites horizontales (paredes)
    if(x < 0 || x >= nivel[y].size())
        return true;
    //obtiene el bloque en la posición dada y verifica si es sólido (representado por '=' o '#')
    char bloque = nivel[y][x];

    return bloque == '=' || bloque == '#';
}

//devuelve el nivel actual del mapa, lo que permite a otras partes del programa acceder a la estructura del mapa para renderizarlo o realizar cálculos de colisiones
const std::vector<std::string>& Mapa::getNivel() const {
    return nivel;
}