#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <string>

class Mapa;

class Entidad {

protected:

    int x;
    int y;

    int vx;
    int vy;

    std::string sprite;

public:

    Entidad(int x, int y, std::string sprite);

    virtual void actualizar(Mapa& mapa) = 0;

    int getX() const;

    int getY() const;

    std::string getSprite() const;
};

#endif