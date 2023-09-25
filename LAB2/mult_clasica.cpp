#include <iostream>
#include <chrono>
#include <stdlib.h>
using namespace std;
using namespace std::chrono;const int N = 100; // tamaño de las matrices
int A[N][N]; // primera matriz
int B[N][N]; // segunda matriz
int R1[N][N]; // resultado de la multiplicación clásica

void mult_clasica() {
        for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                        for(int k = 0; k < N; k++) {
                                R1[i][j] += A[i][k] * B[k][j];
                        }
                }
        }
}

void fill() { // llena el arreglo x y la matriz A de valores aleatorios
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            A[i][j] = rand() % 30;
            B[i][j] = rand() % 30;
        }
    }
}

int main() {
        fill();
        mult_clasica();
}