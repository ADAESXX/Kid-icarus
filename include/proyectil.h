//Nombre del programa: proyectil.h
//Descripción: Declaración de la clase Proyectil para el juego Kid Icarus
//Autor: Abigail Escobar   
//Fecha: 16/05/2026
//Estado: completo

#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <string>

class Proyectil {
    private:
    //atributos del proyectil
        int x;
        int y;
        int direccion; 
        //Componente vertical para las bolas de fuego
        int direccionY;
        int velocidad;
        bool activo;
        std::string sprite;

    public:
        //constructor para las flechas del jugador
        Proyectil(int x, int y, int direccion);
        //constructir generl (permite mov en x y y)
        Proyectil(int x, int y, int dx, int dy, const std::string& spr);
        void mover();
        int getX() const;
        int getY() const;
        bool estaActivo() const;
        void desactivar();
        std::string getSprite() const;
};

#endif