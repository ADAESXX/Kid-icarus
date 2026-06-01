//Nombre del archivo: juego.cpp
//Descripción: Logica del juego 
//Autor 1: Abigail Escobar
//Modificaciones por: Dulce Granados 
//Fecha: 31/05/26
//Estado: Completo
//Modificaciones:
    //Agregué librerias
    //Inicialice varias variables en el contructor
    //Este si lo cambie en todo :)
#include "juego.h"
#include "pantallas.h"
#include <algorithm>
#include <ncurses.h>
#include <cstdlib>
// usleep
#include <unistd.h>
#include <string>
#include <vector>

// Mapa base: bordes de '#' a los lados y '=' arriba/abajo, interior vacio.
static std::vector<std::string> mapaBase() {
    const int W = 60, H = 17;
    std::vector<std::string> m;
    m.push_back(std::string(W, '='));
    for(int i = 1; i < H - 1; i++) {
        std::string fila(W, ' ');
        fila[0] = '#';
        fila[W - 1] = '#';
        m.push_back(fila);
    }
    m.push_back(std::string(W, '='));
    return m;
}

// "Estampa" una plataforma horizontal de '=' en la fila indicada.
static void stampPlataforma(std::vector<std::string>& m, int fila, int col, int len) {
    if(fila < 0 || fila >= (int)m.size()) return;
    for(int i = 0; i < len; i++) {
        int c = col + i;
        if(c > 0 && c < (int)m[fila].size() - 1) m[fila][c] = '=';
    }
}

//Inicializac los objetos de sincronización
Juego::Juego()
//inicializa el jugador en la posición (3, 14) con su sprite correspondiente, lo que establece el punto de partida para el jugador en el mapa del juego
    : jugador(5, 12) {
    nivelActual = 1;
    totalNiveles = 4;
    corazonesRecolectados = 0;
    enemigosDerrotados = 0;
    cooldownMedusa = 0;
    ejecutando = false;
    gano = false;
    perdio = false;
    pausado = false;
    modoIA = false;
    framesIA = 0;

    pthread_mutex_init(&mutexEstado, nullptr);
    pthread_cond_init(&condPausa, nullptr);
    // hasta 5 flechas a la vez
    sem_init(&semDisparos, 0, 5);
    // 4 hilos + el principal
    pthread_barrier_init(&barreraInicio, nullptr, 5);

}

Juego::~Juego() {
    pthread_mutex_destroy(&mutexEstado);
    pthread_cond_destroy(&condPausa);
    sem_destroy(&semDisparos);
    pthread_barrier_destroy(&barreraInicio);
}

//Cargar el nivel (se llama con el mutex ya tomado, o antes de crear los hilos)

void Juego::cargarNivel(int n) {
    nivelActual = n;
    cooldownMedusa = 0;

    // Devolver al semaforo los permisos de las flechas que sigan vivas
    // antes de limpiar, para no "perder" disparos al cambiar de nivel
    for(size_t i = 0; i < proyectiles.size(); i++) sem_post(&semDisparos);
    proyectiles.clear();
    proyectilesEnemigos.clear();
    items.clear();
    enemigos.clear();

    std::vector<std::string> m = mapaBase();
    // plataforma inicial (abajo-izquierda)
    stampPlataforma(m, 13, 3,  14);
    stampPlataforma(m, 10, 12, 15);
    stampPlataforma(m, 7,  22, 15);
    // plataforma superior (lleva a la meta)
    stampPlataforma(m, 4,  32, 19);
    // posicion de la meta 'G'
    const int gr = 3, gc = 48;
    m[gr][gc] = 'G';
    mapa.cargarNivel(m);

    // Posicion inicial del jugador, sobre la plataforma de abajo.
    const int sx = 5, sy = 12;
    jugador.setInicio(sx, sy);
    jugador.colocar(sx, sy);

    // Enemigos e items segun el nivel: a mas nivel, mas enemigos.
    using TE = Enemigo::TipoEnemigo;
    switch(n) {
        case 1:
            enemigos.push_back(Enemigo(16, 9, TE::CAMINANTE, 100, true, 1));
            enemigos.push_back(Enemigo(30, 6, TE::CAMINANTE, 100, true, 1));
            //escudo
            items.push_back(Items(20, 9, 3));
            break;
        case 2:
            enemigos.push_back(Enemigo(16, 9, TE::CAMINANTE, 100, true, 1));
            enemigos.push_back(Enemigo(30, 6, TE::CAMINANTE, 100, true, 1));
            enemigos.push_back(Enemigo(25, 4, TE::VOLADOR,   150, true, 1));
            //corazon
            items.push_back(Items(18, 9, 1));
            break;
        case 3:
            enemigos.push_back(Enemigo(16, 9, TE::CAMINANTE, 100, true, 1));
            enemigos.push_back(Enemigo(30, 6, TE::CAMINANTE, 100, true, 1));
            enemigos.push_back(Enemigo(20, 5, TE::VOLADOR,   150, true, 1));
            enemigos.push_back(Enemigo(40, 3, TE::VOLADOR,   150, true, 1));
            //Espada
            items.push_back(Items(24, 6, 2));
            //Corazon
            items.push_back(Items(35, 3, 1));
            break;
        case 4:
        default:
            //jefe final
            enemigos.push_back(Enemigo(40, 2, TE::MEDUSA,    500, true, 0));
            enemigos.push_back(Enemigo(20, 5, TE::VOLADOR,   150, true, 1));
            enemigos.push_back(Enemigo(16, 9, TE::CAMINANTE, 100, true, 1));
            //corazon
            items.push_back(Items(15, 8, 1));
            //escudo
            items.push_back(Items(28, 6, 3)); 
            break;
    }
}

//Funciones void* necesarias para pthread (libres/estáticas)
void* Juego::hiloJugadorTramp(void* arg){ 
    static_cast<Juego*>(arg)->hiloJugador();    
    return nullptr; 
}
void* Juego::hiloEnemigosTramp(void* arg){
    static_cast<Juego*>(arg)->hiloEnemigos();   
    return nullptr;
}
void* Juego::hiloProyectilesTramp(void* arg){ 
    static_cast<Juego*>(arg)->hiloProyectiles();
    return nullptr; 
}
void* Juego::hiloEscenarioTramp(void* arg){
    static_cast<Juego*>(arg)->hiloEscenario();  
    return nullptr; }

/////////////////////////////////// HILOS ///////////////////////////
//Hilo 1: jugador
void Juego::hiloJugador() {
    // espera a que todos esten listos
    pthread_barrier_wait(&barreraInicio);
    while(true) {
        pthread_mutex_lock(&mutexEstado);
        while(pausado && ejecutando) pthread_cond_wait(&condPausa, &mutexEstado);
        if(!ejecutando) { pthread_mutex_unlock(&mutexEstado); break; }

        if(modoIA) {
            // ----- MODO 2: la computadora decide las acciones de Pit -----
            // Se vacia la cola de teclado por si llegara algo, pero no se actua
            // sobre ella: el control es automatico.
            while(eventos.hayEventos()) eventos.pop();
            decidirIA();
        } 
        else {
        // Consumir todos los eventos que el hilo principal haya producido.
            while(eventos.hayEventos()) {
                Evento e = eventos.pop();
                switch(e.tipo) {
                    case EventoTipo::MOVER_IZQUIERDA: jugador.moverIzquierda(mapa); break;
                    case EventoTipo::MOVER_DERECHA:   jugador.moverDerecha(mapa);   break;
                    case EventoTipo::SALTAR:          jugador.saltar();             break;
                    case EventoTipo::DISPARAR: {
                        // SEMAFORO: solo se crea la flecha si quedan permisos (<5).
                        if(sem_trywait(&semDisparos) == 0) {
                            int dir = (jugador.getDireccionX() == 0) ? 1 : jugador.getDireccionX();
                            proyectiles.push_back(
                                Proyectil(jugador.getX() + dir, jugador.getY(), dir));
                        }
                        break;
                    }
                    case EventoTipo::SALIR:
                        ejecutando = false;
                        pthread_cond_broadcast(&condPausa);
                        break;
                }
            }
        }
        // gravedad + movimiento
        jugador.actualizar(mapa);
        pthread_mutex_unlock(&mutexEstado);
        // 60 actualizaciones por segundo mas o menos
        usleep(16000);
    }
}
//Hilo 2: enemigos
void Juego::hiloEnemigos() {
    pthread_barrier_wait(&barreraInicio);
    while(true) {
        pthread_mutex_lock(&mutexEstado);
        while(pausado && ejecutando) pthread_cond_wait(&condPausa, &mutexEstado);
        if(!ejecutando) {
             pthread_mutex_unlock(&mutexEstado); 
             break; 
        }

        for(auto& e : enemigos) {
            if(!e.estaVivo()) continue;
            e.actualizar(mapa);

            // Contacto con el jugador -> daño (la invulnerabilidad evita que se vacie la salud de golpe).
            int dx = std::abs(jugador.getX() - e.getX());
            int dy = std::abs(jugador.getY() - e.getY());
            if(dx <= 1 && dy == 0) jugador.recibirDanio(10);

            // Medusa lanza bolas de fuego hacia el jugador cada cierto tiempo.
            if(e.getTipo() == Enemigo::TipoEnemigo::MEDUSA) {
                cooldownMedusa++;
                if(cooldownMedusa >= 40) {
                    cooldownMedusa = 0;
                    proyectilesEnemigos.push_back(
                    Proyectil(e.getX(), e.getY(), 1, 0, "O"));

                    // Horizontal izquierda
                    proyectilesEnemigos.push_back(
                        Proyectil(e.getX(), e.getY(), -1, 0, "O"));

                    // Vertical arriba
                    proyectilesEnemigos.push_back(
                        Proyectil(e.getX(), e.getY(), 0, -1, "O"));

                    // Vertical abajo
                    proyectilesEnemigos.push_back(
                        Proyectil(e.getX(), e.getY(), 0, 1, "O"));
                }
            }
        }
        pthread_mutex_unlock(&mutexEstado);
        usleep(20000);
    }
}

//Hilo 3: Proyectiles
void Juego::hiloProyectiles() {
    pthread_barrier_wait(&barreraInicio);
    while(true) {
        pthread_mutex_lock(&mutexEstado);
        while(pausado && ejecutando) pthread_cond_wait(&condPausa, &mutexEstado);
        if(!ejecutando) { pthread_mutex_unlock(&mutexEstado); break; }

        // Flechas del jugador
        for(auto& p : proyectiles) {
            if(!p.estaActivo()) continue;
            p.mover();
            if(mapa.esSolido(p.getX(), p.getY())) { p.desactivar(); continue; }
            for(auto& e : enemigos) {
                if(!e.estaVivo()) continue;
                if(std::abs(p.getX() - e.getX()) <= 1 && p.getY() == e.getY()) {
                    e.morir();
                    p.desactivar();
                    enemigosDerrotados++;
                    jugador.agregarPuntaje(100);
                    items.push_back(Items(e.getX(), e.getY(), 1)); // suelta corazon
                    break;
                }
            }
        }
        // Eliminar flechas inactivas y DEVOLVER un permiso al semaforo por cada una
        for(auto it = proyectiles.begin(); it != proyectiles.end(); ) {
            if(!it->estaActivo()) { sem_post(&semDisparos); it = proyectiles.erase(it); }
            else ++it;
        }
        // Eliminar enemigos muertos
        enemigos.erase(std::remove_if(enemigos.begin(), enemigos.end(),
            [](const Enemigo& e){ return !e.estaVivo(); }), enemigos.end());

        // Bolas de fuego de los enemigos
        for(auto& f : proyectilesEnemigos) {
            if(!f.estaActivo()) continue;
            f.mover();
            if(mapa.esSolido(f.getX(), f.getY())) { f.desactivar(); continue; }
            if(std::abs(f.getX() - jugador.getX()) <= 1 && f.getY() == jugador.getY()) {
                jugador.recibirDanio(10);
                f.desactivar();
            }
        }
        proyectilesEnemigos.erase(std::remove_if(proyectilesEnemigos.begin(),
            proyectilesEnemigos.end(),
            [](const Proyectil& p){ return !p.estaActivo(); }), proyectilesEnemigos.end());

        pthread_mutex_unlock(&mutexEstado);
        usleep(20000);
    }
}

//Hilo 4: Escenario
void Juego::hiloEscenario() {
    pthread_barrier_wait(&barreraInicio);
    while(true) {
        pthread_mutex_lock(&mutexEstado);
        while(pausado && ejecutando) pthread_cond_wait(&condPausa, &mutexEstado);
        if(!ejecutando) { pthread_mutex_unlock(&mutexEstado); break; }

        // Recoger items en los que esta parado el jugador.
        for(auto it = items.begin(); it != items.end(); ) {
            if(it->getX() == jugador.getX() && it->getY() == jugador.getY()) {
                switch(it->getTipo()) {
                    case 1: jugador.recogerCorazon(); corazonesRecolectados++; break;
                    case 2: jugador.agregarPuntaje(50); break;
                    case 3: jugador.activarEscudo(); break;
                }
                it = items.erase(it);
            } else ++it;
        }

        // Llegar a la meta 'G': avanzar de nivel o ganar
        const auto& nivel = mapa.getNivel();
        int jy = jugador.getY(), jx = jugador.getX();
        if(jy >= 0 && jy < (int)nivel.size() &&
           jx >= 0 && jx < (int)nivel[jy].size() &&
           nivel[jy][jx] == 'G') {
            if(nivelActual < totalNiveles) {
                // mutex ya tomado: no rebloquea
                cargarNivel(nivelActual + 1);
            } else {
                gano = true;
                ejecutando = false;
                pthread_cond_broadcast(&condPausa);
            }
        }

        // Pierde el juego si se queda sin vidas
        if(jugador.getVidas() <= 0) {
            perdio = true;
            ejecutando = false;
            pthread_cond_broadcast(&condPausa);
        }

        pthread_mutex_unlock(&mutexEstado);
        usleep(30000);
    }
}



//Ejecución del hilo principal 
void Juego::procesarEntrada() {

    int tecla = getch();
    if (tecla == ERR) return;

    pthread_mutex_lock(&mutexEstado);

    switch (tecla) {
        case 'a':
        case 'A':
            Evento eventoIzquierda;
            eventoIzquierda.tipo = EventoTipo::MOVER_IZQUIERDA;
            eventos.push(eventoIzquierda);
            break;

        case 'd':
        case 'D':
            Evento eventoDerecha;
            eventoDerecha.tipo = EventoTipo::MOVER_DERECHA;
            eventos.push(eventoDerecha);
            break;

        case 'w':
        case 'W':
            Evento eventoSalto;
            eventoSalto.tipo = EventoTipo::SALTAR;
            eventos.push(eventoSalto);
            break;

        case ' ':
            Evento eventoDisparo;
            eventoDisparo.tipo = EventoTipo::DISPARAR;
            eventos.push(eventoDisparo);
            break;

        case 'p':
        case 'P':

            pausado = !pausado;
            if (!pausado) {
                pthread_cond_broadcast(&condPausa);
            }
            break;

        case 'q':
        case 'Q':

            ejecutando = false;
            pthread_cond_broadcast(&condPausa);
            break;
    }

    pthread_mutex_unlock(&mutexEstado);
}

//Renderizar (s ejecuta en el hilo principa, bajo mutex)

void Juego::renderizar() {
    pthread_mutex_lock(&mutexEstado);
    clear();
    const auto& nivel = mapa.getNivel();
    for(size_t y = 0; y < nivel.size(); y++)
        mvprintw((int)y, 0, "%s", nivel[y].c_str());
    for(auto& it : items)
        mvprintw(it.getY(), it.getX(), "%s", it.getSprite().c_str());
    for(auto& e : enemigos)
        if(e.estaVivo()) mvprintw(e.getY(), e.getX(), "%s", e.getSprite().c_str());
    for(auto& p : proyectiles)
        if(p.estaActivo()) mvprintw(p.getY(), p.getX(), "%s", p.getSprite().c_str());
    for(auto& f : proyectilesEnemigos)
        if(f.estaActivo()) mvprintw(f.getY(), f.getX(), "%s", f.getSprite().c_str());

    mvprintw(jugador.getY(), jugador.getX(), "%s", jugador.getSprite().c_str());

    int hud = (int)nivel.size() + 1;
    mvprintw(hud, 0,
    "Nivel: %d/%d    Puntaje: %d",
    nivelActual,
    totalNiveles,
    jugador.getPuntaje());

    mvprintw(hud + 1, 0,
    "Vidas: %d    Salud: %d",
    jugador.getVidas(),
    jugador.getSalud());

    mvprintw(hud + 2, 0,
    "Corazones: %d    Enemigos: %d",
    corazonesRecolectados,
    enemigosDerrotados);

    mvprintw(hud + 3, 0,
    "Escudo: %s",
    jugador.tieneEscudo() ? "SI" : "NO");

    mvprintw(hud + 4, 0,
    "A/D mover  W saltar  SPACE disparar  P pausa  Q salir");
    if(pausado) mvprintw((int)nivel.size() / 2, 22, "== PAUSA (P para continuar) ==");

    refresh();
    pthread_mutex_unlock(&mutexEstado);
}

//Iniciar crea los hilos, corre el bucle princiapl y hace el join de los hilos
void Juego::iniciar(bool ia) {
    // entrada no bloqueante para el juego
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);

    modoIA = ia;
    framesIA = 0;
    ejecutando = true;
    gano = false;
    perdio = false;
    pausado = false;
    corazonesRecolectados = 0;
    enemigosDerrotados = 0;


    // nivel inicial (todavia sin hilos)
    cargarNivel(1);

    pthread_t thJ, thE, thP, thS;
    pthread_create(&thJ, nullptr, hiloJugadorTramp,     this);
    pthread_create(&thE, nullptr, hiloEnemigosTramp,    this);
    pthread_create(&thP, nullptr, hiloProyectilesTramp, this);
    pthread_create(&thS, nullptr, hiloEscenarioTramp,   this);

    // BARRERA: nadie empieza a moverse hasta que los 5 hilos ya están creados
    pthread_barrier_wait(&barreraInicio);

    // Bucle principal: lee entrada y dibuja.
    while(true) {
        pthread_mutex_lock(&mutexEstado);
        bool fin = !ejecutando;
        pthread_mutex_unlock(&mutexEstado);
        if(fin) break;

        procesarEntrada();
        renderizar();
        napms(16);
    }
    //Une a todos los hilos
    pthread_join(thJ, nullptr);
    pthread_join(thE, nullptr);
    pthread_join(thP, nullptr);
    pthread_join(thS, nullptr);

    Pantallas pantallas;
    if(gano)        pantallas.victoria();
    else if(perdio) pantallas.derrota();

    nodelay(stdscr, FALSE);   // volver a entrada bloqueante
    getch();                  // esperar una tecla en la pantalla final
}

void Juego::terminar() {
    pthread_mutex_lock(&mutexEstado);
    ejecutando = false;
    pthread_cond_broadcast(&condPausa);
    pthread_mutex_unlock(&mutexEstado);
}

//Se ejecuta dentro de hiloJugador, con el mutex ya tomado
//La idea es que avance, esquive o ataque
void Juego::decidirIA() {
    framesIA++;

    const int jx = jugador.getX();
    const int jy = jugador.getY();
    const int dir = (jugador.getDireccionX() == 0) ? 1 : jugador.getDireccionX();

    bool enemigoEnLinea = false;   // hay un enemigo al frente, a la misma altura
    bool enemigoCerca   = false;   // hay un enemigo pegado (peligro de contacto)

    for(auto& e : enemigos) {
        if(!e.estaVivo()) continue;
        int dx = e.getX() - jx;
        int dy = e.getY() - jy;
        if(std::abs(dy) <= 1 && ((dir > 0 && dx > 0) || (dir < 0 && dx < 0))
           && std::abs(dx) <= 18) enemigoEnLinea = true;
        if(std::abs(dx) <= 3 && std::abs(dy) <= 1) enemigoCerca = true;
    }

    // ATACAR: dispara si hay un enemigo en linea (respetando el semaforo de 5).
    if(enemigoEnLinea && (framesIA % 3 == 0)) {
        if(sem_trywait(&semDisparos) == 0)
            proyectiles.push_back(Proyectil(jx + dir, jy, dir));
    }

    // Leer el terreno inmediato para decidir el salto.
    bool paredAdelante = mapa.esSolido(jx + dir, jy);       // bloque al frente
    bool bordeAdelante = !mapa.esSolido(jx + dir, jy + 1);  // se acaba el piso

    // SALTAR: para esquivar enemigos, sortear una pared o subir a la siguiente
    // plataforma justo al llegar a su borde. saltar() solo actua si Pit esta
    // posado, asi que es seguro invocarlo en cualquier frame.
    if(enemigoCerca || paredAdelante || bordeAdelante || (framesIA % 16 == 0))
        jugador.saltar();

    // AVANZAR: se mueve hacia la meta (a la derecha del mapa).
    jugador.moverDerecha(mapa);
}
//El menu los lee al terminar para guardarlos en la parte del menu
int  Juego::getPuntajeFinal()   const { return jugador.getPuntaje(); }
int  Juego::getCorazonesFinal() const { return corazonesRecolectados; }
int  Juego::getEnemigosFinal()  const { return enemigosDerrotados; }
int  Juego::getVidasFinal()     const { return jugador.getVidas(); }
bool Juego::ganoPartida()       const { return gano; }
