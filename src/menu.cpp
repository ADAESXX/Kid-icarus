//Nombre del archivo: menu.cpp
//Descripción: Implementación de la clase Menu para el juego Kid Icarus
//Autor 1: María Renée
//Autor 2: Dulce Granados
//Fecha: 16/05/2026
//Modificaciones realizadas por: Abigail Escobar

#include <iostream>
#include <cstdlib>
#include <limits>
#include <thread>
#include <chrono>

#include "menu.h"
#include "juego.h"

using namespace std;
// Implementación de los métodos de la clase Menu
//Menu:: sirve para indicar que el método pertenece a la clase Menu
void Menu::mostrarMenu() {

    int opcion;

    while (true) {

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

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(opcion) {

            case 1:
                iniciarJuego();
                break;

            case 2:
                instrucciones();

                cout << "\nPresione ENTER para continuar...";
                cin.get();
                break;

            case 3:
                mostrarPuntajes();

                cout << "\nPresione ENTER para continuar...";
                cin.get();
                break;

            case 4:
                cout << "\nSaliendo del juego..." << endl;
                return;

            default:
                cout << "\nOpcion invalida." << endl;

                cout << "\nPresione ENTER para continuar...";
                cin.get();
        }
    }
}
/////////////////////////////////////////////FALTA ESTE
void Menu::iniciarJuego() {
    //cambie cls por clear para limpiar la pantalla en sistemas Unix/Linux
    system("clear");

    cout << "Iniciando juego..." << endl;
    this_thread::sleep_for(chrono::seconds(2));

    system("clear");
    Juego juego;
    juego.iniciar();
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