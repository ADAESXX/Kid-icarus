//Nombre del archivo: enemigo.h
//Descripción: Declaración de la clase Enemigo para el juego Kid Icarus
//Autor: Abigail Escobar
//Fecha: 16/05/2026


#ifndef ENEMIGO_H
#define ENEMIGO_H


#include <string>
using namespace std;

class Enemigo {
    //Atributos del enemigo
    private:
        int x;
        int y;
        //tipo de enemigo
            //1. caminantes
            //2. voladores
            //3. Bolas de fuego
            //4. Medusa
        int tipo;
        int valorEnemigo;
        string sprite;
        bool aparecido;
        int velocidad; 
    //Métodos del enemigo
    public:
        //Constructor para inicializar el enemigo con su posición y sprite
        Enemigo(int x, int y, int tipo, int valorEnemigo,bool aparecido, int velocidad);
        //movimientos
        void mover();
        void atacar();
        void morir();
        //Getters para obtener la posición y el sprite del enemigo
        int getX();
        int getY();
        int getTipo();
        int getValorEnemigo();
        string getSprite();
        bool getAparecido();
        int getVelocidad();

};
//Constructor de la clase Enemigo
#endif