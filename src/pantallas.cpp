//Nombre del archivo: pantallas.cpp
//Descripción: Implementación de las funciones para mostrar las pantallas de inicio, victoria y derrota del juego Kid Icarus    
//Autor: Abigail Escobar
//Fecha: 16/05/2026
#include <iostream>
#include <cstdlib>

#include "pantallas.h"

using namespace std;

void Pantallas::inicio(){
    system("clear");
    cout << "═══════════════════════════════════════════════════════════════════════" << endl;
    cout << endl;

    cout << "██╗  ██╗██╗██████╗     ██╗ ██████╗ █████╗ ██████╗ ██╗   ██╗███████" << endl;
    cout << "██║ ██╔╝██║██╔══██╗    ██║██╔════╝██╔══██╗██╔══██╗██║   ██║██╔════╝" << endl;
    cout << "█████╔╝ ██║██║  ██║    ██║██║     ███████║██████╔╝██║   ██║███████╗" << endl;
    cout << "██╔═██╗ ██║██║  ██║    ██║██║     ██╔══██║██╔══██╗██║   ██║╚════██║" << endl;
    cout << "██║  ██╗██║██████╔╝    ██║╚██████╗██║  ██║██║  ██║╚██████╔╝███████║" << endl;
    cout << "╚═╝  ╚═╝╚═╝╚═════╝     ╚═╝ ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝" << endl;
    cout <<endl;
    cout << "═══════════════════════════════════════════════════════════════════════" << endl;
    cout << endl;
    cout << "                    ✦  W E L C O M E  ✦" << endl;
    cout << endl;
    cout << "                El reino celestial te necesita" << endl;
    cout << endl;
    cout << "═══════════════════════════════════════════════════════════════════════" << endl;
        

}

void Pantallas::victoria() {

    system("clear");

    cout << "██╗    ██╗██╗███╗   ██╗" << endl;
    cout << "██║    ██║██║████╗  ██║╝" << endl;
    cout << "██║ █╗ ██║██║██╔██╗ ██║" << endl;
    cout << "██║███╗██║██║██║╚██╗██║" << endl;
    cout << "╚███╔███╔╝██║██║ ╚████║" << endl;
    cout << " ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝" << endl;
}

void Pantallas::derrota() {

    system("clear");
    cout << " ██████╗  █████╗ ███╗   ███╗███████╗" << endl;
    cout << "██╔════╝ ██╔══██╗████╗ ████║██╔════╝" << endl;
    cout << "██║  ███╗███████║██╔████╔██║█████╗  " << endl;
    cout << "██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  " << endl;
    cout << "╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗" << endl;
    cout << " ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝ " << endl;

    cout <<" ██████╗ ██╗   ██╗███████╗██████╗" << endl;
    cout <<"██╔═══██╗██║   ██║██╔════╝██╔══██╗" << endl;
    cout <<"██║   ██║██║   ██║█████╗  ██████╔╝" << endl;
    cout <<"██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗" << endl;
    cout <<"╚██████╔╝ ╚████╔╝ ███████╗██║  ██║" << endl;
    cout <<" ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝" << endl;

}
