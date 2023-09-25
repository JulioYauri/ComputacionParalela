#include <iostream>
#include <chrono>
#include <stdlib.h>
using namespace std;
using namespace std::chrono;

const int N = 100; // tamaño de las matrices
int A[N][N]; // primera matriz
int B[N][N]; // segunda matriz
int R2[N][N]; // resultado de la multiplicación por bloques
const int sz = 10; // tamaño del bloque


void mult_bloques() {
    for(int i0 = 0; i0 < N; i0 += sz) {
        for(int j0 = 0; j0 < N; j0 += sz) {
            for(int k0 = 0; k0 < N; k0 += sz) {
                for(int i = i0; i < min(i0 + sz, N); i++) {
                    for(int j = j0; j < min(j0 + sz, N); j++) {
                        for(int k = k0; k < min(k0 + sz, N); k++) {
                            R2[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
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
        mult_bloques();
}