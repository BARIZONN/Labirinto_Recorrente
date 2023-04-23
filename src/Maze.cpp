#include <iostream>
#include "Maze.h"
using namespace std;
Maze::Maze() {
    matrix = nullptr;
    booleanMatrix = nullptr;
    matrixNumber = 0;
    mazeDimensions.first = 0;
    mazeDimensions.second = 0;
}

void Maze::allocate() {
    matrix = new char *[mazeDimensions.first];
    for (short i = 0; i < mazeDimensions.first; i++) {
        matrix[i] = new char;
    }
    booleanMatrix = new bool *[mazeDimensions.first];
    for (short i = 0; i < mazeDimensions.first; i++) {
        booleanMatrix[i] = new bool;
    }

}

void Maze::readHeader() {
    ifstream originalFile;
    string fileName, booleanFileName;

    char buffer;

    originalFile.open("dataset/input.data");

    originalFile >> buffer;
    originalFile >> buffer;

    mazeDimensions.first = buffer - '0';

    originalFile >> buffer;

    mazeDimensions.second = buffer - '0';
    originalFile.close();

}


void Maze::separateMatrix() {
    ifstream originalFile;
    string fileName, booleanFileName;

    char buffer;
    unsigned short counter = 0;

    originalFile.open("dataset/input.data");
    originalFile >> buffer;
    originalFile >> buffer;
    originalFile >> buffer;

    do {
        fileName = "dataset/matrix" + to_string(counter);
        booleanFileName = "dataset/booleanMatrix" + to_string(counter);
        ofstream output(fileName);
        ofstream booleanOutput(booleanFileName);

        for (short i = 0; i < mazeDimensions.first; i++) {
            for (short j = 0; j < mazeDimensions.first; j++) {
                originalFile >> buffer;
                output << buffer << ' ';
                booleanOutput << 0 << ' ';

            }
            output << '\n';
            booleanOutput << '\n';
        }
        counter++;
        output.close();
        booleanOutput.close();
    } while (counter != mazeDimensions.second);
    originalFile.close();
}

void Maze::getInitialPosition() {
    short xPosition, yPosition;
    srand(time(nullptr));
    matrixNumber = rand() % mazeDimensions.second;
    boy.setInitialMatrix(matrixNumber);
    xPosition = rand() % mazeDimensions.first;
    yPosition = rand() % mazeDimensions.first;
    boy.setInitialPosition(xPosition, yPosition);
}

void Maze::tryPosition(short x, short y) {
    unsigned short nextMatrix;

    if ((x < 0 || y < 0) || (x >= mazeDimensions.first || y >= mazeDimensions.first)) {
 
        nextMatrix = rand() % mazeDimensions.second;
        x = rand() % mazeDimensions.first;
        y = rand() % mazeDimensions.first;

        loadSpecificMatrix(nextMatrix);
        boy.setPosition(x, y);
        matrix[x][y] = '*';
        boy.decHp();
        boy.incDangerCounter();
        boy.incSteps();
        booleanMatrix[x][y] = true;
        return;
    } else {
        switch (matrix[x][y]) {
            case '*':
                boy.setPosition(x, y);
                boy.incItens();
                boy.decHp();
                boy.incDangerCounter();
                booleanMatrix[x][y] = true;
                boy.incSteps();
                return;
            case '0':
                boy.setPosition(x, y);
                booleanMatrix[x][y] = true;
                boy.incSteps();
                return;
            case '#':
                return;
            default:
                boy.setPosition(x, y);
                boy.incSteps();
                boy.incItens();
                matrix[x][y]--;
                booleanMatrix[x][y] = true;
                return;
        }
    }
}


void Maze::joystick() {
    unsigned short nextPosition;
    srand(time(nullptr));
    do {
        nextPosition = rand() % 8;
        switch (nextPosition) {
            case 0: 
                tryPosition(boy.getPosition().first - 1, boy.getPosition().second + 1);
                saveMatrix();
                break;
            case 1:
                tryPosition(boy.getPosition().first, boy.getPosition().second + 1);
                saveMatrix();
                break;
            case 2: 
                tryPosition(boy.getPosition().first + 1, boy.getPosition().second + 1);
                saveMatrix();
                break;
            case 3: //baixo
                tryPosition(boy.getPosition().first + 1, boy.getPosition().second);
                saveMatrix();
                break;
            case 4: //diagonal inferior esquerda
                tryPosition(boy.getPosition().first + 1, boy.getPosition().second - 1);
                saveMatrix();
                break;
            case 5: //esquerda
                tryPosition(boy.getPosition().first, boy.getPosition().second - 1);
                saveMatrix();
                break;
            case 6: //diagonal superior esquerda
                tryPosition(boy.getPosition().first - 1, boy.getPosition().second - 1);
                saveMatrix();
                break;
            case 7: //cima
                tryPosition(boy.getPosition().first - 1, boy.getPosition().second);
                saveMatrix();
                break;
        }
    } while (boy.getHp() > 0 || !(haveExploredAllMatrixes() && haveExploredAllMatrixes()));
}


void Maze::loadMatrix() {
    ifstream matrixFile, booleanMatrixFile;
    char buffer;

    matrixFile.open("dataset/matrix" + to_string(matrixNumber));
    booleanMatrixFile.open("dataset/booleanMatrix" + to_string(matrixNumber));

    for (short i = 0; i < mazeDimensions.first; i++) {
        for (short j = 0; j < mazeDimensions.first; j++) {
            if (matrixFile.eof() && booleanMatrixFile.eof()) {
                break;
            }
            matrixFile >> buffer;
            if (buffer != '\n') {
                matrix[i][j] = buffer;
            }
            booleanMatrixFile >> buffer;
            if (buffer != '\n') {
                if (buffer == '1') {
                    booleanMatrix[i][j] = true;
                } else {
                    booleanMatrix[i][j] = false;
                }
            }
        }


    }
    matrixFile.close();
    booleanMatrixFile.close();
}

void Maze::loadSpecificMatrix(unsigned short specificMatrixNumber) {
    ifstream matrixFile, booleanMatrixFile;
    char buffer;

    matrixFile.open("dataset/matrix" + to_string(specificMatrixNumber));
    booleanMatrixFile.open("dataset/booleanMatrix" + to_string(specificMatrixNumber));

    for (short i = 0; i < mazeDimensions.first; i++) {
        for (short j = 0; j < mazeDimensions.first; j++) {
            if (matrixFile.eof() && booleanMatrixFile.eof()) {
                break;
            }
            matrixFile >> buffer;
            if (buffer != '\n') {
                matrix[i][j] = buffer;
            }
            booleanMatrixFile >> buffer;
            if (buffer != '\n') {
                if (buffer == '1') {
                    booleanMatrix[i][j] = true;
                } else {
                    booleanMatrix[i][j] = false;
                }
            }
        }

        matrixNumber = specificMatrixNumber;
    }
    matrixFile.close();
    booleanMatrixFile.close();
}

void Maze::saveMatrix() {

    ofstream matrixFile, booleanMatrixFile;

    matrixFile.open("dataset/matrix" + to_string(matrixNumber));
    booleanMatrixFile.open("dataset/booleanMatrix" + to_string(matrixNumber));

    for (short i = 0; i < mazeDimensions.first; i++) {
        for (short j = 0; j < mazeDimensions.first; j++) {
            matrixFile << matrix[i][j] << ' ';
            booleanMatrixFile << booleanMatrix[i][j] << ' ';
        }
        matrixFile << '\n';
        booleanMatrixFile << '\n';
    }
    matrixFile.close();
    booleanMatrixFile.close();

}

void Maze::endGame() {
    ifstream booleanMatrixFile, matrixFile;
    ofstream outputFile;
    char buffer;
    unsigned notExploredPositionsCounter = 0;
    matrixNumber = 0;
    outputFile.open("dataset/output.data");


    do {
        matrixFile.open("dataset/matrix" + to_string(matrixNumber));
        booleanMatrixFile.open("dataset/booleanMatrix" + to_string(matrixNumber));

        for (short i = 0; i < mazeDimensions.first; i++) {
            for (short j = 0; j < mazeDimensions.first; j++) {
                if (matrixFile.eof()) {
                    break;
                }
                matrixFile >> buffer;
                outputFile << buffer << ' ';
            }
            outputFile << '\n';
        }
        outputFile << '\n';

        matrixFile.close();
        matrixNumber++;
    } while (matrixNumber < mazeDimensions.second);
    outputFile.close();

    if (haveExploredAllMatrixes() && haveWalkedToInitialPosition()) {
        cout << "O garoto voltou para a posição inicial mas não achou uma saída!"
                  << endl;
    }

    mazeDimensions.second--;
    do {
        booleanMatrixFile.open("dataset/booleanMatrix" + to_string(mazeDimensions.second));
        for (short i = 0; i < mazeDimensions.first; i++) {
            for (short j = 0; j < mazeDimensions.first; j++) {
                if (booleanMatrixFile.eof()) {
                    break;
                }
                booleanMatrixFile >> buffer;
                if (buffer == '0') {
                    notExploredPositionsCounter++;
                }
            }
        }
        booleanMatrixFile.close();
        mazeDimensions.second--;

    } while (mazeDimensions.second >= 0);
    booleanMatrixFile.close();


    cout << "Total de passos: " << boy.getStep()<< endl
              << "Total de itens consumidos: " << boy.getItens() << endl
              << "A quantidade de casas não exploradas foi de: " << notExploredPositionsCounter << endl
              << "Total de perigos encontrados: " << boy.getDangerCounter() << endl;


    delete matrix;
    delete booleanMatrix;
}

bool Maze::haveExploredAllMatrixes() {
    system("clear");
    ifstream booleanMatrixFile;
    char buffer;
    unsigned short counter = 0;
    matrixNumber = 0;

    do {
        booleanMatrixFile.open("dataset/booleanMatrix" + to_string(matrixNumber));
        for (short i = 0; i < (mazeDimensions.first * mazeDimensions.first); i++) {
            if (booleanMatrixFile.eof()) {
                break;
            }
            booleanMatrixFile >> buffer;
            if (buffer == '1') {
                counter++;
                break;
            }

        }
        booleanMatrixFile.close();
        matrixNumber++;
    } while (matrixNumber < mazeDimensions.second);
    if (counter == mazeDimensions.second) {
        return true;
    } else {
        return false;
    }
}

bool Maze::haveWalkedToInitialPosition() {
    if (boy.getPosition().first == boy.getInitialPosition().first &&
        boy.getPosition().second == boy.getInitialPosition().second && boy.getInitialMatrix() == matrixNumber) {
        return true;
    } else {
        return false;
    }
}






