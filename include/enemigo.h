//Nombre del archivo: enemigo.h
//Descripción: Declaración de la clase Enemigo para el juego Kid Icarus
//Autor: Abigail Escobar
//Fecha: 16/05/2026


#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "entidad.h"
#include "mapa.h"
#include <string>
#include <vector>

class Enemigo : public Entidad {

public:

    enum class TipoEnemigo {

        CAMINANTE,
        VOLADOR,
        MEDUSA
    };

private:

    TipoEnemigo tipo;

    int valorEnemigo;

    bool aparecido;

    int velocidad;

    int direccion;

    int framesMovimiento;

public:

    Enemigo(
        int x,
        int y,
        TipoEnemigo tipo,
        int valorEnemigo,
        bool aparecido,
        int velocidad
    );

    void actualizar(Mapa& mapa) override;

    void mover(Mapa& mapa);

    void atacar();

    void morir();

    TipoEnemigo getTipo() const;

    int getValorEnemigo() const;

    bool getAparecido() const;

    int getVelocidad() const;
};

#endif