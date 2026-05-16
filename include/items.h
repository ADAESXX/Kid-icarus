//Nombre del archivo: items.h
//Descripción: Declaración de la clase Items para el juego Kid Icarus
//Autor: Abigail Escobar
//Fecha: 16/05/2026

#ifndef ITEMS_H
#define ITEMS_H

#include <string>
using namespace std;

class Items {
    //Atributos de los items
    private:
        int x;
        int y;
        //tipo de item
            //1. Corazones para recuperar vidas
            //2. Armas para aumentar el poder de ataque
            //3. Escudos para protegerse de los enemigos
        int tipo;
        string sprite;
    //Métodos de los items
    public:
        //Constructor para inicializar el item con su posición y sprite
        Items(int x, int y, int tipo);
        //movimientos
        void usar();
        //Getters para obtener la posición y el sprite del item
        int getX();
        int getY();
        string getSprite();
        int getTipo();

};

#endif