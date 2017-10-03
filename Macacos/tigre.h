#ifndef TIGRE_H
#define TIGRE_H
#include "agente.h"
#include "macaco.h"

class tigre : public agente
{
public:
    tigre(int x = 0, int y = 0);
    void movimenta( agente* campoAgentes[DIMENSAO][DIMENSAO]);
    tigre(const tigre &value);
private:
    void ataca(macaco *monkey, agente* campoAgentes[DIMENSAO][DIMENSAO], localizacao atacante);
};

#endif // TIGRE_H
