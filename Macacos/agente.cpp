#include "agente.h"

agentes agente::getTipo() const
{
    return tipo;
}

void agente::setTipo(const agentes &value)
{
    tipo = value;
}

localizacao agente::getPosicao() const
{
    return posicao;
}

void agente::setPosicao(int x, int y)
{
    posicao.setX(x);
    posicao.setY(y);
}
void agente::setPosicao(const localizacao& value)
{
    posicao = value;
}
char agente::getSimbolo() const
{
    return simbolo;
}

void agente::setSimbolo(char value)
{
    simbolo = value;
}

agente::agente(int x , int y , char s ):posicao(x,y),simbolo(s)
{
}

ostream &operator<<(ostream &os, const agente &a)
{
        os<<a.getSimbolo();
        return os;

}
