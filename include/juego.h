//Nombre del archivo: juego.h
//Descripción: Archivo de cabecera para el juego Kid Icarus, que incluye las declaraciones de las clases Jugador, Enemigo, Mapa y Menu
//Autor 1: Abigail Escobar
//Autor 2: Dulce Granados
//Fecha: 16/05/2026
//Estado: Completo
//Modificaciones: 
    //Agregué librerías para usarlas en la lógica del juego
    //Además poloque los mecanismos de sincronización 
    //Inclui los proyectiles de Medusa (bolas de fuego)
    //inclui los items
    //Inclui el event manager
    //elimine muchos métodos inecesarios y moví algunios a privado

#ifndef JUEGO_H
#define JUEGO_H

#include "jugador.h"
#include "enemigo.h"
#include "mapa.h"
#include "proyectil.h"
#include "items.h"
#include "eventmanager.h"
//el vector se usa para almacenar múltiples enemigos y proyectiles en el juego, lo que permite gestionar dinámicamente la cantidad de entidades presentes en el mapa
#include <vector>
#include <pthread.h>
#include <semaphore.h>

class Juego {
    private:
        //atributos compartidos ente todos los hilos
        Jugador jugador;
        std::vector<Enemigo> enemigos;
        //Flechas de Pit
        std::vector<Proyectil> proyectiles;
        //Bolas de fuego de Medusa
        std::vector<Proyectil> proyectilesEnemigos;
        std::vector<Items> items;
        Mapa mapa;

        //atributos nuevos
        int nivelActual;
        int totalNiveles;
        int corazonesRecolectados;
        int enemigosDerrotados;
        //controla la frecuencia de disparo
        int cooldownMedusa;


        bool ejecutando;
        bool gano;
        bool perdio;
        bool pausado;

        //atributos para modalidad IA o humano
        bool modoIA;
        int framesIA;

        EventManager eventos;

        ////// Mecanismos de sincronizacion
        // protege TODO el estado compartido
        pthread_mutex_t   mutexEstado;
        // coordina la pausa / reanudacion  
        pthread_cond_t    condPausa;  
        // limita las flechas simultaneas (max. 5)
        sem_t             semDisparos;
        // alinea el arranque de todos los hilos
        pthread_barrier_t barreraInicio;

        // Funciones void* requeridas por pthread
        static void* hiloJugadorTramp(void* arg);
        static void* hiloEnemigosTramp(void* arg);
        static void* hiloProyectilesTramp(void* arg);
        static void* hiloEscenarioTramp(void* arg);

        // Logica de cada hilo
        // procesa entrada y fisica del jugador
        void hiloJugador();
        // mueve enemigos y dispara las bolas de Medusa
        void hiloEnemigos();
        // mueve flechas/bolas y resuelve colisiones
        void hiloProyectiles();
        // items, meta, fin de partida, cambio de nivel
        void hiloEscenario(); 

        //  Auxiliares
        void cargarNivel(int n);
        void renderizar();
        void procesarEntrada();
        void decidirIA();


    public:
        Juego();
        ~Juego();
        void iniciar(bool ia = false);
        void terminar();

        int getPuntajeFinal() const;
        int getCorazonesFinal() const;
        int getEnemigosFinal() const;
        int getVidasFinal() const;
        bool ganoPartida() const;
};

#endif