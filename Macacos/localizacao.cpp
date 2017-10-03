#include "localizacao.h"
#include <cmath>

int localizacao::getX() const
{
    return x;
}

void localizacao::setX(int value)
{
    x = value;
}

int localizacao::getY() const
{
    return y;
}

void localizacao::setY(int value)
{
    y = value;
}

void localizacao::aplicaDirecao(orientacao direcao)
{
    if(x + direcao.getVx() < 50 && x + direcao.getVx() >= 0)
        x += direcao.getVx();
    else
        x += direcao.getVx() * -1;//inverte direção em situações de indice invalido exemplo coordenada=(0,0) direcao=(-1,0) isso invertendo temos (1,0)
    if(y + direcao.getVy() < 50 && y + direcao.getVy() >= 0)
        y += direcao.getVy();
    else
        y += direcao.getVy() * -1;
}

double localizacao::operator-(const localizacao &value) const//calcula distancia com pitagoras
{
    double x1 = x;
    double x2 = value.x;
    double y1 = y;
    double y2 = value.y;

    double aux = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
    double distancia = sqrt(aux);//usando sqrt da cmath

    return distancia;
}

localizacao::localizacao(int x, int y)
{
    this->x = x;
    this->y = y;
}
localizacao::localizacao()
{
    x = 0;
    y = 0;
}
