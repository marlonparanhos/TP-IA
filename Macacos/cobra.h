#ifndef COBRA_H
#define COBRA_H
#include "agente.h"
#include "macaco.h"

class cobra : public agente
{
public:
    cobra(int x = 0, int y = 0);
    void movimenta( agente* campoAgentes[DIMENSAO][DIMENSAO]);
    cobra(const cobra &value);
private:
    void ataca(macaco *monkey, agente* campoAgentes[DIMENSAO][DIMENSAO], localizacao atacante);
};

#endif // COBRA_H
