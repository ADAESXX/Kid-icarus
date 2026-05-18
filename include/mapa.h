//Nombre del archivo: mapa.h
//Descripción: Declaración de los fondos para el juego Kid Icarus
//Autor: Abigail Escobar
//Fecha: 16/05/2026

#ifndef MAPA_H
#define MAPA_H

#include <vector>
#include <string>

class Mapa {

private:

    std::vector<std::string> nivel;

public:

    void cargarNivel(
        const std::vector<std::string>& nuevoNivel
    );

    bool esSolido(int x, int y) const;

    const std::vector<std::string>& getNivel() const;
};

#endif