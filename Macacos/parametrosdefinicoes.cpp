#include "parametrosdefinicoes.h"
#include <exception>

using namespace std;

int parametros::getQuantidadeIteracoes() const
{
    return quantidadeIteracoes;
}

void parametros::setQuantidadeIteracoes(int value)
{
    quantidadeIteracoes = value;
}

parametros::parametros()
{
    quantidadeTotal = 0;
    quantidadeMacacos = 0;
    quantidadeAguias = 0;
    quantidadeCobras = 0;
    quantidadeTigres = 0;
    raioPredadores = 0;
    raioAlarmes = 0;
    quantidadeTotal = 0;
}

int parametros::getQuantidadeAguias() const
{
    return quantidadeAguias;
}

void parametros::setQuantidadeAguias(int value)
{
    if(value < 0)
    {
        erro valor_invalido("a quantidade de aguias nao pode ser menor que 0");
        throw(valor_invalido);
    }
    if(value + quantidadeTotal > MAX_AGENTES)
    {
        erro valor_invalido("a quantidade de aguias excede o limite do campo");
        throw(valor_invalido);
    }
    quantidadeTotal += value;
    quantidadeAguias = value;
}

int parametros::getQuantidadeCobras() const
{
    return quantidadeCobras;
}

void parametros::setQuantidadeCobras(int value)
{
    if(value <=0)
    {
        erro valor_invalido("a quantidade de cobras nao pode ser menor que 0");
        throw(valor_invalido);
    }
    if(value + quantidadeTotal > MAX_AGENTES)
    {
        erro valor_invalido("a quantidade de cobras excede o limite do campo");
        throw(valor_invalido);
    }
    quantidadeTotal += value;
    quantidadeCobras = value;
}

int parametros::getQuantidadeTigres() const
{
    return quantidadeTigres;
}

void parametros::setQuantidadeTigres(int value)
{
    if(value < 0)
    {
        erro valor_invalido("a quantidade de tigres nao pode ser menor que 0");
        throw(valor_invalido);
    }
    if(value + quantidadeTotal > MAX_AGENTES)
    {
        erro valor_invalido("a quantidade de tigres excede o limite do campo");
        throw(valor_invalido);
    }
    quantidadeTotal += value;
    quantidadeTigres = value;
}

int parametros::getRaioPredadores() const
{
    return raioPredadores;
}

void parametros::setRaioPredadores(int value)
{
    if(value <= 0)
    {
        erro valor_invalido("a Raio de predadores nao pode ser menor que 1");
        throw(valor_invalido);
    }
    if(value > MAX_RAIO_PREDADOR)
    {
        erro valor_invalido("o Raio de Alarme excede o limite maximo");
        throw(valor_invalido);
    }

    raioPredadores = value;
}

int parametros::getRaioAlarmes() const
{
    return raioAlarmes;
}

void parametros::setRaioAlarmes(int value)
{
    if(value <= 0)
    {
        erro valor_invalido("a Raio de Alarme nao pode ser menor que 1");
        throw(valor_invalido);
    }
    if(value > MAX_RAIO_ALARME)
    {
        erro valor_invalido("o Raio de Alarme excede o limite maximo");
        throw(valor_invalido);
    }

    raioAlarmes = value;
}

int parametros::getQuantidadeMacacos() const
{
    return quantidadeMacacos;
}

void parametros::setQuantidadeMacacos(int value)
{
    if(value <= 0)
    {
        erro valor_invalido("a quantidade de macacos nao pode ser menor que 1");
        throw(valor_invalido);
    }
    if(value + quantidadeTotal > MAX_AGENTES)
    {
        erro valor_invalido("a quantidade de macacos excede o limite do campo");
        throw(valor_invalido);
    }
    quantidadeTotal += value;
    quantidadeMacacos = value;
}



erro::erro(string descricao)
{
    this->descricao = descricao;
}

const char *erro::what() const noexcept
{
    return descricao.c_str();
}
