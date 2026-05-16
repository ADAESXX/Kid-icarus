//Nombre del programa: proyectil.h
//Descripción: Declaración de la clase Proyectil para el juego Kid Icarus
//Autor: Abigail Escobar   
//Fecha: 16/05/2026

#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <string>
using namespace std;

class Proyectil {
    //Atributos del proyectil
    private:
        int x;
        int y;
        int velocidad;
        string sprite;
    //Métodos del proyectil
    public:
        //Constructor para inicializar el proyectil con su posición, velocidad y sprite
        Proyectil(int x, int y, int velocidad);
        //movimientos
        void mover();
        void colisionar();
        void desaparecer();
        //Getters para obtener la posición y el sprite del proyectil
        int getX();
        int getY();
        string getSprite();

};