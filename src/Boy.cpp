//
// Created by cesar on 04/04/2023.
//

#include "Boy.h"


Boy::Boy() {
    position = {0, 0};
    initialPosition = {0, 0};
    hp = 10;
    step = 0;
    itens = 0;
    dangerCounter = 0;
    initialMatrix = 0;
}

unsigned short Boy::getHp() const {
    return hp;
}

unsigned short Boy::getItens() const {
    return itens;
}

unsigned short Boy::getStep() const {
    return step;
}

unsigned short Boy::getDangerCounter() const {
    return dangerCounter;
}

std::pair<short, short> Boy::getInitialPosition() {
    return initialPosition;
}

void Boy::setInitialPosition(short xAxisPosition, short yAxisPosition) {
    position = {xAxisPosition, yAxisPosition};
    initialPosition = {xAxisPosition, yAxisPosition};
}

std::pair<short, short> Boy::getPosition() {
    return position;
}

void Boy::setPosition(short xAxisPosition, short yAxisPosition) {
    position = {xAxisPosition, yAxisPosition};
}

void Boy::incHp() {
    if (getHp() == 10) {
        return;
    }
    hp++;
}

void Boy::decHp() {
    hp--;
}

void Boy::incItens() {
    itens++;
    if (getItens() % 4 == 0) {
        incHp();
    }
}

void Boy::incSteps() {
    step++;
}

void Boy::incDangerCounter() {
    dangerCounter++;
}

short Boy::getInitialMatrix() {
    return initialMatrix;
}

void Boy::setInitialMatrix(short matrixNumber) {
    initialMatrix = matrixNumber;
}








