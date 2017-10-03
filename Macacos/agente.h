#ifndef AGENTE_H
#define AGENTE_H
#include "localizacao.h"
#include "orientacao.h"
#include "parametrosdefinicoes.h"
#include <QObject>
#include <iostream>
using namespace std;
enum agentes{Tigre,Aguia,Cobra,Macaco};


class agente : public QObject//pra poder fazer conexeçõe
{
    Q_OBJECT
protected:
    agentes tipo;
    char simbolo;
    localizacao posicao;
    orientacao direcao;
protected:
    void setTipo(const agentes &value);
    void setSimbolo(char value);
public:
    agente(int x = 0, int y = 0,char s = ' ');
    virtual void movimenta(agente* campoAgentes[DIMENSAO][DIMENSAO]) = 0;
    agentes getTipo() const;
    localizacao getPosicao() const;
    void setPosicao(const localizacao &value);// *
    void setPosicao(int x, int y);// **
    char getSimbolo() const;

};

ostream& operator<<(ostream& os ,const agente& a);//pra usar cout

#endif // AGENTE_H

//agente * a = new aguia;
//if(a->getTipo() == Aguia)
//{
//...
//}

/** exemplo * e **
 * agente a,b;
 *
 * a.setPosicao(0,1);
 *
 * localicacao loc(1,2_;
 *
 * a.setPosicao(loc)
 *
 * cout<<a;
 * a<<
 *
 *
 **/
