#include "ambiente.h"
#include "macaco.h"
#include "aguia.h"
#include "cobra.h"
#include "tigre.h"
#include "estatisticas.h"
ambiente::ambiente(parametros parametrosInstancia)//seção de inicialização de variaveis
    :macacos(parametrosInstancia.getQuantidadeMacacos()),
      tigres(parametrosInstancia.getQuantidadeTigres()),
      aguias(parametrosInstancia.getQuantidadeAguias()),
      cobras(parametrosInstancia.getQuantidadeCobras())
{
    cout<<endl<<"Preparando parametros...";

    this->parametrosInstancia = parametrosInstancia;

    cout<<"Ok";
    cout<<endl<<"Gerando campo...";

    for (int i = 0; i < DIMENSAO; ++i)
        for (int j = 0; j < DIMENSAO; ++j)
            campoAgentes[i][j] = NULL;

    cout<<"Ok";
    cout<<endl<<"Instanciando Macacos...";
    for (int i = 0; i < parametrosInstancia.getQuantidadeMacacos(); ++i)
    {
        int x = rand()%DIMENSAO;
        int y = rand()%DIMENSAO;

        localizacao pos(x,y);
        while(campoAgentes[x][y] != NULL)
        {
            x = rand()%50;
            y = rand()%50;
            pos.setX(x);
            pos.setY(y);
        }
        macacos[i].setPosicao(pos);
        macacos[i].setRaioPredadores(parametrosInstancia.getRaioPredadores());
        macacos[i].setRaioAlarmes(parametrosInstancia.getRaioAlarmes());
        campoAgentes[x][y] = &macacos[i];
    }
    cout<<"Ok";
    cout<<endl<<"Instanciando Aguias...";
    for (int i = 0; i < parametrosInstancia.getQuantidadeAguias(); ++i)
    {
        int x = rand()%DIMENSAO;
        int y = rand()%DIMENSAO;

        localizacao pos(x,y);
        while(campoAgentes[x][y] != NULL)
        {
            x = rand()%50;
            y = rand()%50;
            pos.setX(x);
            pos.setY(y);
        }
        aguias[i] = new aguia;
        aguias[i]->setPosicao(pos);
        campoAgentes[x][y] = aguias[i];
    }
    cout<<"Ok";
    cout<<endl<<"Instanciando Cobras...";
    for (int i = 0; i < parametrosInstancia.getQuantidadeCobras(); ++i)
    {
        int x = rand()%DIMENSAO;
        int y = rand()%DIMENSAO;

        localizacao pos(x,y);
        while(campoAgentes[x][y] != NULL)
        {
            x = rand()%50;
            y = rand()%50;
            pos.setX(x);
            pos.setY(y);
        }
        cobras[i] = new cobra;
        cobras[i]->setPosicao(pos);
        campoAgentes[x][y] = cobras[i];
    }
    cout<<"Ok";
    cout<<endl<<"Instanciando Tigres...";
    for (int i = 0; i < parametrosInstancia.getQuantidadeTigres(); ++i)
    {
        int x = rand()%DIMENSAO;
        int y = rand()%DIMENSAO;

        localizacao pos(x,y);
        while(campoAgentes[x][y] != NULL)
        {
            x = rand()%50;
            y = rand()%50;
            pos.setX(x);
            pos.setY(y);
        }
        tigres[i] = new tigre();
        tigres[i]->setPosicao(pos);
        campoAgentes[x][y] = tigres[i];
    }
    cout<<"Ok"<<endl;

    for (int i = 0; i < macacos.size(); ++i)
        for (int j = 0 ; j < macacos.size() ; ++j)
        {
            if(i == j)
                continue;

            QObject::connect(&macacos[i],
                             SIGNAL(alarme(agentes,localizacao,localizacao,int)),
                             &macacos[j],
                             SLOT(recebeAlarme(agentes,localizacao,localizacao,int)));

        }
    interacao=0;
    estatisticas::Tabela1<<"s"<<0;
    estatisticas::Tabela2<<"s"<<0;
    estatisticas::Tabela3<<"s"<<0;
    for (int i = 1; i < 10; ++i)
    {
        estatisticas::Tabela1<<";s"<<i;
        estatisticas::Tabela2<<";s"<<i;
        estatisticas::Tabela3<<";s"<<i;
    }
    estatisticas::Tabela1<<endl;
    estatisticas::Tabela2<<endl;
    estatisticas::Tabela3<<endl;
}

void ambiente::avancaEstado()
{
    estatisticas::Tabela1<<interacao<<macacos[estatisticas::getAmostra()].getValorTabela(0,0);
    estatisticas::Tabela2<<interacao<<macacos[estatisticas::getAmostra()].getValorTabela(1,0);
    estatisticas::Tabela3<<interacao++<<macacos[estatisticas::getAmostra()].getValorTabela(2,0);
    for (int i = 1; i < 10; ++i)
    {
        estatisticas::Tabela1<<";"<<macacos[estatisticas::getAmostra()].getValorTabela(0,i);
        estatisticas::Tabela2<<";"<<macacos[estatisticas::getAmostra()].getValorTabela(1,i);
        estatisticas::Tabela3<<";"<<macacos[estatisticas::getAmostra()].getValorTabela(2,i);
    }
    estatisticas::Tabela1<<endl;
    estatisticas::Tabela2<<endl;
    estatisticas::Tabela3<<endl;
    system("pause");
    for(macaco& monkey : macacos)
    {
        monkey.movimenta(campoAgentes);
        monkey.analisarArredores(tigres,aguias,cobras);
    }
    for(agente* inimigo : tigres)
    {
        tigre * tiger = (tigre*) inimigo;
        tiger->movimenta(campoAgentes);
    }
    for(agente* inimigo :  aguias)
    {
        aguia* engle = (aguia*) inimigo;
        engle->movimenta(campoAgentes);
    }
    for(agente* inimigo : cobras)
    {
        cobra* snake = (cobra*) inimigo;
        snake->movimenta(campoAgentes);
    }
    system("cls");
    printCampo();
}

void ambiente::printCampo()
{
    for (int i = 0; i < DIMENSAO; ++i)
    {
        for (int j = 0; j < DIMENSAO; ++j)
        {
            if(campoAgentes[i][j])
                cout<<*campoAgentes[i][j];
            else
                cout<<"-";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Numero de Cobras: "<<cobras.size()<<endl;
    cout<<"Numero de Aguia: "<<aguias.size()<<endl;
    cout<<"Numero de Tigre: "<<tigres.size()<<endl;

    cout<<"Numero de Macacos: "<<parametrosInstancia.getQuantidadeMacacos() - estatisticas::getNumeroMortes()<<endl;
    cout<<"Numero de Mortes: "<<estatisticas::getNumeroMortes()<<endl;
    cout<<"Numero de Fugas de Predadores: "<<estatisticas::getNumeroTotalEscapes()<<endl;

}
