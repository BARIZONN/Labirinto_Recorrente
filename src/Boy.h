#ifndef O_LABIRINTO_RECORRENTE_BOY_H
#define O_LABIRINTO_RECORRENTE_BOY_H

#include <utility>

class Boy {
private:
    std::pair<short, short> position, initialPosition;
    short initialMatrix;
    unsigned short hp, itens, dangerCounter, step;
public:
    Boy();
    unsigned short getHp() const;
    unsigned short getItens() const;
    unsigned short getStep() const;
    unsigned short getDangerCounter() const;
    short getInitialMatrix();
    void setInitialMatrix(short matrixNumber);
    std::pair<short, short> getPosition();
    std::pair<short, short> getInitialPosition();
    void setInitialPosition(short xAxisPosition, short yAxisPosition);
    void setPosition(short xAxisPosition, short yAxisPosition);
    void incHp();
    void decHp();
    void incDangerCounter();
    void incItens();
    void incSteps();
};


#endif //O_LABIRINTO_RECORRENTE_BOY_H
