#ifndef PARAMETROSDEFINICOES_H
#define PARAMETROSDEFINICOES_H
#include <string>
#define DIMENSAO 50
#define MAX_AGENTES 2500
#define MAX_RAIO_ALARME 2500
#define MAX_RAIO_PREDADOR 2500
using namespace std;

class erro : public exception
{
    string descricao;
public:
    erro(string descricao);
    virtual const char* what() const noexcept;
};

class parametros
{
private:
    int quantidadeIteracoes;
    int quantidadeMacacos;
    int quantidadeAguias;
    int quantidadeCobras;
    int quantidadeTigres;
    int raioPredadores;
    int raioAlarmes;
    int quantidadeTotal;
public:
    parametros();
    int getQuantidadeMacacos() const;
    void setQuantidadeMacacos(int value);
    int getQuantidadeAguias() const;
    void setQuantidadeAguias(int value);
    int getQuantidadeCobras() const;
    void setQuantidadeCobras(int value);
    int getQuantidadeTigres() const;
    void setQuantidadeTigres(int value);
    int getRaioPredadores() const;
    void setRaioPredadores(int value);
    int getRaioAlarmes() const;
    void setRaioAlarmes(int value);
    int getQuantidadeIteracoes() const;
    void setQuantidadeIteracoes(int value);
};

#endif // PARAMETROSDEFINICOES_H
