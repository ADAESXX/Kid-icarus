//Nombre del archivo: menu.cpp
//Descripción: Implementación de la clase Menu para el juego Kid Icarus
//Autor 1: María Renée
//Autor 2: Dulce Granados
//Fecha: 16/05/2026
//Modificaciones realizadas por: Abigail Escobar

#include <iostream>
#include <cstdlib>

#include "menu.h"

using namespace std;
// Implementación de los métodos de la clase Menu
//Menu:: sirve para indicar que el método pertenece a la clase Menu
void Menu::mostrarMenu() {

    int opcion;
    bool juegoActivo = true;

    while (juegoActivo) {

        system("clear");

        cout << "======================================" << endl;
        cout << "           KID ICARUS MENU            " << endl;
        cout << "======================================" << endl;
        cout << "1. Iniciar Juego" << endl;
        cout << "2. Instrucciones" << endl;
        cout << "3. Puntajes" << endl;
        cout << "4. Salir" << endl;
        cout << "======================================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1:
                iniciarJuego();
                break;

            case 2:
                instrucciones();
                break;

            case 3:
                mostrarPuntajes();
                break;

            case 4:
                cout << "\nSaliendo del juego..." << endl;
                juegoActivo = false;
                break;

            default:
                cout << "\nOpcion invalida." << endl;
        }
        // Espera a que el usuario presione ENTER antes de mostrar el menú nuevamente
        if (juegoActivo) {
            cout << "\nPresione ENTER para continuar...";
            cin.ignore();
            cin.get();
        }
    }
}
/////////////////////////////////////////////FALTA ESTE
void Menu::iniciarJuego() {
    //cambie cls por clear para limpiar la pantalla en sistemas Unix/Linux
    system("clear");

    cout << "Iniciando juego..." << endl;
}

void Menu::instrucciones() {

    system("clear");

    cout << "=========== INSTRUCCIONES ===========" << endl;
    cout << "A -> Mover izquierda" << endl;
    cout << "D -> Mover derecha" << endl;
    cout << "W -> Saltar" << endl;
    cout << "SPACE -> Disparar" << endl;
}

void Menu::mostrarPuntajes() {

    system("clear");

    cout << "============= PUNTAJES ==============" << endl;
    cout << "Jugador 1: 1500 puntos" << endl;
    cout << "Jugador 2: 1200 puntos" << endl;
}