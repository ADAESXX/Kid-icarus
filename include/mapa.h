//Nombre del archivo: mapa.h
//Descripción: Declaración de los fondos para el juego Kid Icarus
//Autor: Abigail Escobar
//Fecha: 16/05/2026
//Estado: Completo

#ifndef MAPA_H
#define MAPA_H

#include <vector>
#include <string>

class Mapa {

    private:
        //el vector de strings representa el nivel del juego, donde cada string es una fila del mapa y cada carácter representa un bloque o espacio vacío
        std::vector<std::string> nivel;

    public:
        //métodos de la clase Mapa
        void cargarNivel(const std::vector<std::string>& nuevoNivel);
        //sirve para verificar si una posición específica en el mapa es sólida y no se puede atravesar
        bool esSolido(int x, int y) const;
        const std::vector<std::string>& getNivel() const;
};

#endif