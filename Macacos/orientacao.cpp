#include "orientacao.h"

int orientacao::getVx() const
{
    return vx;
}

void orientacao::setVx(int value)
{
    vx = value;
}

int orientacao::getVy() const
{
    return vy;
}

void orientacao::setVy(int value)
{
    vy = value;
}

orientacao::orientacao()
{
    vx = 0;
    vy = 0;
}

orientacao::orientacao(int vx, int vy)
{
    this->vx = vx;
    this->vy = vy;
}
