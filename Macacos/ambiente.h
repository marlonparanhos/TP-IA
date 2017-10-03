#ifndef AMBIENTE_H
#define AMBIENTE_H
#include "agente.h"
#include "aguia.h"
#include "cobra.h"
#include "macaco.h"
#include "tigre.h"
#include "parametrosdefinicoes.h"


class ambiente
{
    int interacao;
    parametros parametrosInstancia;
    agente* campoAgentes[DIMENSAO][DIMENSAO];
    vector<macaco> macacos;
    vector<agente*> tigres;
    vector<agente*> aguias;
    vector<agente*> cobras;
public:
    ambiente(parametros parametrosInstancia);
    void avancaEstado();
    void printCampo();
};

#endif // AMBIENTE_H
