// Nombre del archivo: proyectil.cpp
// Descripción: Implementación de la clase Proyectil para el juego Kid Icarus
// Autor: Abigail Escobar
// Fecha: 18/05/2026
#include "proyectil.h"
//se incluyen las cabeceras necesarias para la implementación de la clase Proyectil, como la clase Mapa para interactuar con el entorno del juego
Proyectil::Proyectil(int x, int y, int direccion)
    : x(x), y(y), direccion(direccion), velocidad(1), activo(true)
{
    //el sprite del proyectil se determina por la dirección en la que se dispara, usando "->" para proyectiles que van hacia la derecha y "<-" para los que van hacia la izquierda
    sprite = (direccion > 0) ? "->" : "<-";
}

void Proyectil::mover()      { x += direccion * velocidad; }
//getters
int  Proyectil::getX() const { return x; }
int  Proyectil::getY() const { return y; }
bool Proyectil::estaActivo() const { return activo; }
//desactivar el proyectil cuando colisiona con un enemigo o un bloque sólido, lo que lo marca como inactivo para que pueda ser eliminado del juego
void Proyectil::desactivar() { activo = false; }
std::string Proyectil::getSprite() const { return sprite; }