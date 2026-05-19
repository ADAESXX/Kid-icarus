//Nombre del programa: proyectil.h
//Descripción: Declaración de la clase Proyectil para el juego Kid Icarus
//Autor: Abigail Escobar   
//Fecha: 16/05/2026

#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <string>

class Proyectil {
    private:
    //atributos del proyectil
        int x;
        int y;
        int direccion; 
        int velocidad;
        bool activo;
        std::string sprite;

    public:
        //métodos de la clase Proyectil
        Proyectil(int x, int y, int direccion);
        void mover();
        int getX() const;
        int getY() const;
        bool estaActivo() const;
        void desactivar();
        std::string getSprite() const;
};

#endif