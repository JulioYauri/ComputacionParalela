#include <iostream> 
#include <iomanip> 
#include <stdlib.h>
#include <chrono> 
#include <cstring> 
using namespace std; 
using namespace std::chrono; 

const int MAX = 50;
double x[MAX], y[MAX], A[MAX][MAX]; 

// primer par de bucles
void first_loop() {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) y[i] += A[i][j] * x[j];
    }
}   

// segundo par de bucles
void second_loop() {
    for(int j = 0; j < MAX; j++) {
        for(int i = 0; i < MAX; i++) y[i] += A[i][j] * x[j];
    }
}

// devuelve el tiempo de ejecución 
// de la función que se pase como parámetro
double test(void (*fun) (void)) {
    auto start = high_resolution_clock::now();
    (*fun)();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    return (double)duration.count();
}

void fill() { // llena el arreglo x y la matriz A de valores aleatorios
    for(int i = 0; i < MAX; i++) {
        x[i] = rand() % 30;
        for(int j = 0; j < MAX; j++) {
            A[i][j] = rand() % 30;
        }
    }
}

int main() {
    fill();
    cout << fixed << setprecision(5);
    cout << "Tiempos cuando MAX = " << MAX << ":\n"; 
    memset(y, 0, sizeof(y)); 
    cout << "Primer par de bucles:\t" << test(first_loop) << "\n"; 
    memset(y, 0, sizeof(y)); 
    cout << "Segundo par de bucles:\t" << test(second_loop) << "\n"; 
}