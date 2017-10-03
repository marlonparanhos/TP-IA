#include "tigre.h"

tigre::tigre(int x , int y):agente(x,y,'T')
{
    tipo = Tigre;
}
tigre::tigre(const tigre &value):agente(value.getPosicao().getX(),value.getPosicao().getY(),'T')
{
    tipo = Tigre;
}

void tigre::ataca(macaco *monkey, agente* campoAgentes[DIMENSAO][DIMENSAO], localizacao atacante)
{
    monkey->tentaDefender(tipo,campoAgentes,atacante);
}
void tigre::movimenta( agente* campoAgentes[DIMENSAO][DIMENSAO])
{
    int vx,vy;
    localizacao nova;
    int tentativas = 0;
    do
    {
        vx = 1 - rand() % 3;
        vy = 1 - rand() % 3;
        nova = posicao;

        direcao.setVx(vx);
        direcao.setVy(vy);


        nova.aplicaDirecao(direcao);

        if(tentativas++ > 30)
            return;

    }while(campoAgentes[nova.getX()][nova.getY()] != NULL && campoAgentes[nova.getX()][nova.getY()]->getSimbolo() != 'M');


    if(campoAgentes[nova.getX()][nova.getY()] != NULL)
    {
        macaco* monkey =(macaco*)campoAgentes[nova.getX()][nova.getY()];
        ataca(monkey,campoAgentes,posicao);
    }

    campoAgentes[posicao.getX()][posicao.getY()] = NULL;
    posicao.aplicaDirecao(direcao);

    campoAgentes[posicao.getX()][posicao.getY()] = this;
}
