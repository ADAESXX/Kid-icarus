#include "entidad.h"


Entidad::Entidad(int x, int y, std::string sprite)
    : x(x),
      y(y),
      vx(0),
      vy(0),
      sprite(sprite)
{
}

int Entidad::getX() const {

    return x;
}

int Entidad::getY() const {

    return y;
}

std::string Entidad::getSprite() const {

    return sprite;
}
