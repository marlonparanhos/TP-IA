#ifndef LOCALIZACAO_H
#define LOCALIZACAO_H
#include "orientacao.h"

class localizacao
{
    int x;
    int y;
public:
    localizacao();
    localizacao(int x , int y);
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    void aplicaDirecao(orientacao direcao);
    double operator-(const localizacao& value) const;//calcula distancia entre 2 pontos

};

#endif // LOCALIZACAO_H
/*
localizacao distacia_macaco1(1,2);
localizacao distacia_macaco1(30,7);

double distancia = distancia_macaco1 - distancia_macaco2;//operator dentro da class

double distancia = distacia_macaco1.calcula_distancia(distancia_macaco2);//usando double calcula_distancia(const localizacao& value,const localizacao& value);//dentro da classe

double distancia = calcula_distancia(distancia_macaco2);//usando double calcula_distancia(const localizacao& value) fora da classe

*/
