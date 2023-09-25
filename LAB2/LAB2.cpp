#include <iostream> 
#include <chrono> 
#include <stdlib.h>
using namespace std; 
using namespace std::chrono;

const int N = 100; // tamaño de las matrices 
int A[N][N]; // primera matriz 
int B[N][N]; // segunda matriz
int R1[N][N]; // resultado de la multiplicación clásica
int R2[N][N]; // resultado de la multiplicacion por bloques
const int sz = 10; // tamaño del bloque 

void mult_clasica() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                R1[i][j] += A[i][k] * B[k][j];
            }
        }   
    }
}

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

// devuelve el tiempo de ejecución 
// de la función que se pase como parámetro
double test(void (*fun) (void)) {
    auto start = high_resolution_clock::now();
    (*fun)();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop-start);
    return (double)duration.count();
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
    cout << "Multiplicacion clasica, tiempo empleado:\t" << test(mult_clasica) << " milisegundos.\n";
    cout << "Multiplicacion por bloques, tiempo empleado:\t" << test(mult_bloques) << " milisegundos.\n";
}