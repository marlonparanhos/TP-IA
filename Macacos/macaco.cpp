#include "macaco.h"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <estatisticas.h>
using namespace std;

double macaco::getRaioAlarmes() const
{
    return raioAlarmes;
}

void macaco::setRaioAlarmes(double value)
{
    vivo = true;
    raioAlarmes = value;
}

void macaco::analisarArredores( vector<agente*>& tigres, vector<agente*>& aguias, vector<agente*>& cobras)
{
    if(vivo == false)
    {
        return;
    }
    for( agente* tiger : tigres)
    {
        double distancia = posicao - tiger->getPosicao();
        if(distancia <= raioPredadores)
        {
            int maior = maiorValor(predadorTigre);
            emit alarme(Tigre,posicao,tiger->getPosicao(),maior);
        }
    }
    for( agente* eagle : aguias)
    {
        double distancia = posicao - eagle->getPosicao();
        if(distancia <= raioPredadores)
        {
            int maior = maiorValor(predadorAguia);
            emit alarme(Aguia,posicao,eagle->getPosicao(),maior);
        }
    }
    for( agente* snake : cobras)
    {
        double distancia = posicao - snake->getPosicao();
        if(distancia <= raioPredadores)
        {
            int maior = maiorValor(predadorCobra);
            emit alarme(Cobra,posicao,snake->getPosicao(),maior);
        }

    }
}

double macaco::getRaioPredadores() const
{
    return raioPredadores;
}

void macaco::setRaioPredadores(double value)
{
    raioPredadores = value;
}


bool macaco::getVivo() const
{
    return vivo;
}

void macaco::setVivo(bool value)
{
    vivo = value;
}

void macaco::tentaDefender(agentes tipo,agente* campoAgentes[DIMENSAO][DIMENSAO], localizacao atacante)
{
    int indiceMaiorAguia = maiorValor(predadorAguia);
    int indiceMaiorCobra = maiorValor(predadorCobra);
    int indiceMaiorTigre = maiorValor(predadorTigre);

    agentes maiorApdtidaoDefesa;

    if(predadorAguia[indiceMaiorAguia] > predadorCobra[indiceMaiorCobra] && predadorAguia[indiceMaiorAguia] > predadorTigre[indiceMaiorTigre])
    {
        maiorApdtidaoDefesa = Aguia;
    }
    else if( predadorCobra[indiceMaiorCobra] > predadorAguia[indiceMaiorAguia] && predadorCobra[indiceMaiorCobra] > predadorTigre[indiceMaiorTigre])
    {
        maiorApdtidaoDefesa = Cobra;
    }
    else if(predadorTigre[indiceMaiorTigre] > predadorAguia[indiceMaiorAguia] && predadorTigre[indiceMaiorTigre] > predadorCobra[indiceMaiorCobra])
    {
        maiorApdtidaoDefesa = Tigre;
    }
    else//caso ele tem aptidão igual pra todos os animais escolho aleatoriamente qual o que ele irá tentar fazer.
    {
        int radomTatic = rand()%3;
        switch (radomTatic) {
        case 0:
            maiorApdtidaoDefesa = Aguia;
            break;
        case 1:
            maiorApdtidaoDefesa = Cobra;
            break;
        case 2:
            maiorApdtidaoDefesa = Tigre;
            break;
        }
    }

    if(tipo == maiorApdtidaoDefesa)
    {
        //esquiva
        campoAgentes[posicao.getX()][posicao.getY()] = NULL;
        campoAgentes[atacante.getX()][atacante.getY()] = this;
        estatisticas::incrementaNumeroTotalEscapes();
    }
    else
    {
        campoAgentes[posicao.getX()][posicao.getY()] = NULL;
        vivo = false;
        estatisticas::incrementaNumeroMortes();
    }
}

macaco::macaco(int x , int y):agente(x,y,'M')
{
    tipo = Macaco;
    double f;
    for (int i = 0; i < 10; ++i)
    {
        f = ((double) rand() / (RAND_MAX));//gerar numeros de 0 1
        predadorTigre[i] = f;
        f = ((double) rand() / (RAND_MAX));
        predadorAguia[i] = f;
        f = ((double) rand() / (RAND_MAX));
        predadorCobra[i] = f;

    }

}

double macaco::getValorTabela(int i,int j)
{
    if(!vivo)
        return -1;
    if (i == 0)
    {
        return predadorAguia[j];
    }
    else if (i == 1)
    {
        return predadorAguia[j];
    }
    else if(i == 2)
    {
        return predadorCobra[j];
    }

    return -2;

}

void macaco::movimenta( agente* campoAgentes[DIMENSAO][DIMENSAO])
{
    if(vivo == false)
    {
        return;
    }

    int vx,vy;
    localizacao nova;
    orientacao direcao;
    int tentativas = 0;
    do
    {
        if(tentativas++ > 30)
            return;
        vx = 1 - rand() % 3; // rand() % 3 -> 0 , 1 , 2
        vy = 1 - rand() % 3;
        nova = posicao;

        direcao.setVx(vx);
        direcao.setVy(vy);

        nova.aplicaDirecao(direcao);


    }while(campoAgentes[nova.getX()][nova.getY()] != NULL);//enquanto não achar um lugar vazio

    campoAgentes[posicao.getX()][posicao.getY()] = NULL;
    posicao.aplicaDirecao(direcao);

    campoAgentes[posicao.getX()][posicao.getY()] = this;

}

void macaco::mostrarVetores()
{

    cout<<"Vetor Tigre"<<endl;
    for (int i = 0; i < 10; ++i)
    {
        cout<<predadorTigre[i]<<" ";

    }
    cout<<endl;

    cout<<"Vetor Aguia"<<endl;
    for (int i = 0; i < 10; ++i)
    {
        cout<<predadorAguia[i]<<" ";
    }
    cout<<endl;

    cout<<"Vetor Cobra"<<endl;
    for (int i = 0; i < 10; ++i)
    {
        cout<<predadorCobra[i]<<" ";
    }
    cout<<endl;

}

void macaco::recebeAlarme(agentes tipoPredador, localizacao macaco, localizacao ameaca, int simbolo)
{

    double distancia = posicao - macaco;

    if(distancia <= raioAlarmes)
    {
        if(tipoPredador == Tigre)
        {
            atualizarVetor(predadorTigre,simbolo);
        }
        else if(tipoPredador == Aguia)
        {
            atualizarVetor(predadorAguia,simbolo);
        }
        else if(tipoPredador == Cobra)
        {
            atualizarVetor(predadorCobra,simbolo);
        }
    }
    else
        return;

}


int maiorValor(double vetorPredador[10])
{
    int maior = 0;
    for (int i = 1; i < 10; ++i)
        if(vetorPredador[maior] < vetorPredador[i])
            maior = i;

    return maior;
}

void atualizarVetor(double vetorPredador[], int indice)
{
    vetorPredador[indice] = vetorPredador[indice] + 0.1;//f -> f + 0.1
}
