#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define vi vector<int>
const int INF = 1e9;

// Búsqueda ternaria para encontrar el MÁXIMO en una función UNIMODAL (crece y luego decrece)
// Esto es O(log₃(n)) ≈ O(log n) pero con constante más grande

int ternary_search_max(vi arr, int n) {
    int izquierda = 0;
    int derecha = n - 1;

    while (derecha - izquierda >= 3) {  // Mientras haya al menos 3 elementos
        int mid1 = izquierda + (derecha - izquierda) / 3;
        int mid2 = derecha - (derecha - izquierda) / 3;

        if (arr[mid1] < arr[mid2])
            izquierda = mid1;  // El máximo está a la derecha
        else
            derecha = mid2;    // El máximo está a la izquierda
    }

    // Búsqueda lineal en los últimos 3 elementos
    int max_index = izquierda;
    for (int i = izquierda + 1; i <= derecha; i++) {
        if (arr[i] > arr[max_index])
            max_index = i;
    }
    return max_index;
}

// Búsqueda ternaria para encontrar el MÍNIMO en una función UNIMODAL (decrece y luego crece)
int ternary_search_min(vi arr, int n) {
    int izquierda = 0;
    int derecha = n - 1;

    while (derecha - izquierda >= 3) {
        int mid1 = izquierda + (derecha - izquierda) / 3;
        int mid2 = derecha - (derecha - izquierda) / 3;

        if (arr[mid1] > arr[mid2])
            izquierda = mid1;  // El mínimo está a la derecha
        else
            derecha = mid2;    // El mínimo está a la izquierda
    }

    int min_index = izquierda;
    for (int i = izquierda + 1; i <= derecha; i++) {
        if (arr[i] < arr[min_index])
            min_index = i;
    }
    return min_index;
}

// Versión para buscar un valor objetivo en una función UNIMODAL (más raro)
// Asume que la función primero crece hasta un pico y luego decrece

int ternary_search_value(vi arr, int n, int objetivo) {
    // Primero encontramos el pico
    int pico = ternary_search_max(arr, n);
    
    // Buscar en la parte creciente (izquierda al pico)
    int izquierda = 0;
    int derecha = pico;
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (arr[medio] == objetivo) return medio;
        if (objetivo < arr[medio]) derecha = medio - 1;
        else izquierda = medio + 1;
    }
    
    // Buscar en la parte decreciente (pico a derecha)
    izquierda = pico;
    derecha = n - 1;
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (arr[medio] == objetivo) return medio;
        if (objetivo > arr[medio]) derecha = medio - 1;  // Porque es decreciente
        else izquierda = medio + 1;
    }
    
    return -1;
}

int main() {
    // Ejemplo: arreglo UNIMODAL (crece hasta un pico, luego decrece)
    vi arr = {1, 3, 5, 7, 9, 8, 6, 4, 2};  // Pico en 9 (índice 4)
    int n = arr.size();
    
    int max_idx = ternary_search_max(arr, n);
    cout << "Máximo: " << arr[max_idx] << " en índice " << max_idx << endl;
    
    int min_idx = ternary_search_min(arr, n);
    cout << "Mínimo: " << arr[min_idx] << " en índice " << min_idx << endl;
    
    int val_idx = ternary_search_value(arr, n, 7);
    cout << "Valor 7 encontrado en índice " << val_idx << endl;
    
    return 0;
}