#ifndef AGENTEMACACO_H
#define AGENTEMACACO_H
#include "agente.h"

using namespace std;
class macaco : public agente
{
    Q_OBJECT
private:
    double predadorTigre[10];
    double predadorAguia[10];
    double predadorCobra[10];
    bool vivo;
    double raioAlarmes;
    double raioPredadores;
public:
    macaco(int x = 0, int y = 0);
    double getValorTabela(int i,int j);
    void movimenta(agente* campoAgentes[DIMENSAO][DIMENSAO]);
    void mostrarVetores();
    double getRaioAlarmes() const;
    void setRaioAlarmes(double value);
    void analisarArredores(vector<agente*> &tigres, vector<agente *> &aguias, vector<agente *> &cobras);
    double getRaioPredadores() const;
    void setRaioPredadores(double value);
    bool getVivo() const;
    void setVivo(bool value);
    void tentaDefender(agentes tipo, agente* campoAgentes[DIMENSAO][DIMENSAO], localizacao atacante);
public slots:
    void recebeAlarme(agentes tipoPredador, localizacao macaco, localizacao ameaca , int simbolo);
signals:
    alarme(agentes tipoPredador, localizacao macaco, localizacao ameaca , int simbolo);
};
int maiorValor(double vetorPredador[10]);
void atualizarVetor(double vetorPredador[10],int indice);
#endif // AGENTEMACACO_H
