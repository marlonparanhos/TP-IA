#ifndef ORIENTACAO_H
#define ORIENTACAO_H


class orientacao
{
    int vx;
    int vy;
public:
    orientacao();
    orientacao(int vx , int vy);
    int getVx() const;
    void setVx(int value);
    int getVy() const;
    void setVy(int value);
};

#endif // ORIENTACAO_H
