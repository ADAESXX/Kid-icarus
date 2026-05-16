//Nombre del archivo: mapa.h
//Descripción: Declaración de los fondos para el juego Kid Icarus
//Autor: Abigail Escobar
//Fecha: 16/05/2026

#ifndef MAPA_H
#define MAPA_H

#include <string>
using namespace std;

class Mapa {
    //Atributos del mapa
    private:
        int ancho;
        int alto;
        string fondo;
    //Métodos del mapa
    public:
        //Constructor para inicializar el mapa con su tamaño y fondo
        Mapa(int ancho, int alto, string fondo);
        //Getters para obtener el tamaño y el fondo del mapa
        int getAncho();
        int getAlto();
        string getFondo();
};
//Constructor de la clase Mapa
#endif
