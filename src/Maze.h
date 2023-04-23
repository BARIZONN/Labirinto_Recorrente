#ifndef _MAZE_H
#define _MAZE_H
#include<iostream>
#include <fstream>
#include "Boy.h"
using namespace std;
class Maze {
private:
    std::pair <short, short> mazeDimensions;
    Boy boy;
    unsigned short matrixNumber;
    char **matrix;
    bool **booleanMatrix;
public:
    Maze();

    void allocate();

    void readHeader();

    void separateMatrix();

    void loadMatrix();

    void loadSpecificMatrix(unsigned short specificMatrixNumber);

    void saveMatrix();

    void getInitialPosition();

    void joystick();

    void tryPosition(short x, short y);

    bool haveExploredAllMatrixes();

    bool haveWalkedToInitialPosition();

    void endGame();

    void print();
};

#endif 
