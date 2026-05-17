//Nombre del archivo: pantallas.cpp
//Descripción: Implementación de las funciones para mostrar las pantallas de inicio, victoria y derrota del juego Kid Icarus    
//Autor 1: María Renée
//Autor 2: Dulce Granados
//Fecha: 16/05/2026
//Modificaciones realizadas por: Abigail Escobar
#include "menu.h"
#include "pantallas.h"
#include <thread>
#include <chrono>

using namespace std;
int main() {

    Pantallas pantallas;
    pantallas.inicio();

    this_thread::sleep_for(chrono::seconds(3));

    Menu menu;
    menu.mostrarMenu();

    return 0;
}