#include <QCoreApplication>
#include "ambiente.h"
#include "parametrosdefinicoes.h"
#include "estatisticas.h"
#include <fstream>
#include <time.h>
using namespace std;
int main(int argc, char *argv[])
{
    parametros Parametros;
    srand(time(0));
    int var;
    cout<<"Forneca os parametros a seguir:"<<endl;
    cout<<"Quantidade de Macacos: ";
    cin>>var;

    try{
         Parametros.setQuantidadeMacacos(var);
    }
    catch(erro e)
    {
        cout<<e.what()<<endl;
        return 1;

    }
    cout<<"Raio dos Alarmes: ";
    cin>>var;

    try{
         Parametros.setRaioAlarmes(var);
    }
    catch(erro e)
    {
        cout<<e.what()<<endl;
        return 1;
    }
    cout<<"Raio de predadores:";
    cin>>var;

    try{
         Parametros.setRaioPredadores(var);
    }
    catch(erro e)
    {
        cout<<e.what()<<endl;
        return 1;
    }
    cout<<"Quantidade de Aguias: ";
    cin>>var;

    try{
        Parametros.setQuantidadeAguias(var);
    }
    catch(erro e)
    {
        cout<<e.what()<<endl;
    }
    cout<<"Quantidade de Cobras: ";
    cin>>var;

    try{
         Parametros.setQuantidadeCobras(var);
    }
    catch(erro e)
    {
        cout<<e.what()<<endl;
        return 1;
    }
    cout<<"Quantidade de Tigres: ";
    cin>>var;

    try{
         Parametros.setQuantidadeTigres(var);
    }
    catch(erro e)
    {
        cout<<e.what()<<endl;
        return 1;
    }
    cout<<"Quantidade de iteracoes: ";
    cin>>var;

    try{
         Parametros.setQuantidadeIteracoes(var);
    }
    catch(erro e)
    {
        cout<<e.what()<<endl;
        return 1;
    }
    cout<<"escolha um elemento para amostragem: ";
    cin>>var;

    if(var < 0 || var >= Parametros.getQuantidadeMacacos() )
    {
         cout<<"Valor invalido"<<endl;
         return 1;
    }
    estatisticas::Tabela1<<"Quantidade de Macacos:; "<<Parametros.getQuantidadeMacacos()<<";";
    estatisticas::Tabela1<<"Raio dos Alarmes:; "<<Parametros.getRaioAlarmes()<<";";
    estatisticas::Tabela1<<"Raio de predadores:;"<<Parametros.getRaioPredadores()<<";";
    estatisticas::Tabela1<<"Quantidade de Aguias:; "<<Parametros.getQuantidadeAguias()<<";";
    estatisticas::Tabela1<<"Quantidade de Cobras:; "<<Parametros.getQuantidadeCobras()<<";";
    estatisticas::Tabela1<<"Quantidade de Tigres:; "<<Parametros.getQuantidadeTigres()<<";";
    estatisticas::Tabela1<<"Quantidade de iteracoes:; "<<Parametros.getQuantidadeIteracoes()<<endl;

    estatisticas::Tabela2<<"Quantidade de Macacos:; "<<Parametros.getQuantidadeMacacos()<<";";
    estatisticas::Tabela2<<"Raio dos Alarmes:; "<<Parametros.getRaioAlarmes()<<";";
    estatisticas::Tabela2<<"Raio de predadores:;"<<Parametros.getRaioPredadores()<<";";
    estatisticas::Tabela2<<"Quantidade de Aguias:; "<<Parametros.getQuantidadeAguias()<<";";
    estatisticas::Tabela2<<"Quantidade de Cobras:; "<<Parametros.getQuantidadeCobras()<<";";
    estatisticas::Tabela2<<"Quantidade de Tigres:; "<<Parametros.getQuantidadeTigres()<<";";
    estatisticas::Tabela2<<"Quantidade de iteracoes:; "<<Parametros.getQuantidadeIteracoes()<<endl;

    estatisticas::Tabela3<<"Quantidade de Macacos:; "<<Parametros.getQuantidadeMacacos()<<";";
    estatisticas::Tabela3<<"Raio dos Alarmes:; "<<Parametros.getRaioAlarmes()<<";";
    estatisticas::Tabela3<<"Raio de predadores:;"<<Parametros.getRaioPredadores()<<";";
    estatisticas::Tabela3<<"Quantidade de Aguias:; "<<Parametros.getQuantidadeAguias()<<";";
    estatisticas::Tabela3<<"Quantidade de Cobras:; "<<Parametros.getQuantidadeCobras()<<";";
    estatisticas::Tabela3<<"Quantidade de Tigres:; "<<Parametros.getQuantidadeTigres()<<";";
    estatisticas::Tabela3<<"Quantidade de iteracoes:; "<<Parametros.getQuantidadeIteracoes()<<endl;
    estatisticas::setAmostra(var);
    ambiente mundo(Parametros);
    int i = 0;
    system("pause");
    system("cls");
    cout<<endl;
    mundo.printCampo();
    while(i++ < Parametros.getQuantidadeIteracoes())
    {
        mundo.avancaEstado();
        cout<<"Etapa: "<<i<<" de "<< Parametros.getQuantidadeIteracoes()<<endl;
    }



    ofstream tabela1("tabela1.csv");
    tabela1<<estatisticas::Tabela1.str();
    tabela1.close();

    ofstream tabela2("tabela2.csv");
    tabela2<<estatisticas::Tabela2.str();
    tabela2.close();

    ofstream tabela3("tabela3.csv");
    tabela3<<estatisticas::Tabela3.str();
    tabela3.close();
    return 0;
}

