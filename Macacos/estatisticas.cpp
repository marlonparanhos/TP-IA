#include "estatisticas.h"

int estatisticas::numeroMortes = 0;
int estatisticas::numeroTotalEscapes = 0;
int estatisticas::amostra = 0;
stringstream estatisticas::Tabela1;
stringstream estatisticas::Tabela2;
stringstream estatisticas::Tabela3;


int estatisticas::getAmostra()
{
    return amostra;
}

void estatisticas::setAmostra(int value)
{
    amostra = value;
}

int estatisticas::getNumeroTotalEscapes()
{
    return numeroTotalEscapes;
}

void estatisticas::incrementaNumeroTotalEscapes()
{
    numeroTotalEscapes++;
}

int estatisticas::getNumeroMortes()
{
    return numeroMortes;
}

void estatisticas::incrementaNumeroMortes()
{
    numeroMortes++;
}
