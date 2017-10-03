#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H
#include <string>
#include <sstream>
using namespace std;
class estatisticas
{
    static int numeroTotalEscapes;
    static int numeroMortes;
    static int amostra;
public:
    static int getNumeroTotalEscapes();
    static void incrementaNumeroTotalEscapes();
    static int getNumeroMortes();
    static void incrementaNumeroMortes();
    static stringstream Tabela1;
    static stringstream Tabela2;
    static stringstream Tabela3;
    static int getAmostra();
    static void setAmostra(int value);
};

#endif // ESTATISTICAS_H
