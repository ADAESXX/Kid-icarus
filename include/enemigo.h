//Nombre del archivo: enemigo.h
//Descripción: Declaración de la clase Enemigo para el juego Kid Icarus
//Autor: Abigail Escobar
//Fecha: 16/05/2026

//siirve para evitar que el archivo se incluya varias veces en el proyecto, lo que puede causar errores de compilación
#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "entidad.h"
#include "mapa.h"
#include <string>
#include <vector>

//herencia de la clase Enemigo a partir de la clase Entidad, lo que significa que Enemigo es un tipo de Entidad y hereda sus atributos y métodos
class Enemigo : public Entidad {

public:
    //enum para definir los tipos de enemigos que existen en el juego
    enum class TipoEnemigo {

        CAMINANTE,
        VOLADOR,
        MEDUSA
    };

private:
    //atrributos de la clase Enemigo
    TipoEnemigo tipo;
    int valorEnemigo;
    bool aparecido;
    int velocidad;
    int direccion;
    int framesMovimiento;

public:
    //constructor para inicializar el enemigo con su posición, tipo, valor, estado de aparición y velocidad
    Enemigo(
        int x,
        int y,
        TipoEnemigo tipo,
        int valorEnemigo,
        bool aparecido,
        int velocidad
    );

    //métodos de la clase Enemigo 
    //Mapa& mapa sirve para pasar una referencia al mapa del juego, lo que permite al enemigo interactuar con el entorno y detectar colisiones
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