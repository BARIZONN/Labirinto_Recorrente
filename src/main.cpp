#include <chrono>
#include <iostream>
#include "Maze.h"

using namespace std;


int main() {
    auto start = chrono::high_resolution_clock::now();
    Maze maze;
    maze.readHeader();
    maze.separateMatrix();
    maze.allocate();
    maze.getInitialPosition();
    maze.loadMatrix();
    maze.joystick();
    maze.endGame();
    auto end = chrono::high_resolution_clock::now();
    auto exec_time = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Tempo de execução: " << exec_time.count() << " milisegundos." << endl;
    return 0;
}