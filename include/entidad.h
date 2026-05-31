//Nombre del archivo: entidad.h
//Descripción: Declaración de la clase Entidad, que es la clase base para Jugador y Enemigo en el juego Kid Icarus
//Autor: Abigail Escobar
//Fecha: 18/05/2026

#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <string>
//Se  declara la clase Mapa para evitar errores de compilación debido a referencias circulares entre Entidad y Mapa
class Mapa;

class Entidad {

    protected:

        int x;
        int y;
        //velocidades para movimiento suave
        int vx;
        int vy;
        //sprite para representar la entidad en pantalla
        std::string sprite;

    public:

        Entidad(int x, int y, std::string sprite);

        virtual ~Entidad() = default;

        //método para actualizar la entidad
        virtual void actualizar(Mapa& mapa) = 0;

        //Getters para obtener la posición y el sprite de la entidad
        int getX() const;
        int getY() const;
        std::string getSprite() const;
};

#endif