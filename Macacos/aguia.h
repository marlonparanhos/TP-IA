#ifndef AGUIA_H
#define AGUIA_H
#include "agente.h"
#include "macaco.h"
class aguia : public agente
{
public:
    aguia(int x = 0, int y = 0);
    aguia(const aguia& value);
    void movimenta(agente* campoAgentes[DIMENSAO][DIMENSAO]);
private:
    void ataca(macaco* monkey,agente* campoAgentes[DIMENSAO][DIMENSAO],localizacao atacante);
};

#endif // AGUIA_H
