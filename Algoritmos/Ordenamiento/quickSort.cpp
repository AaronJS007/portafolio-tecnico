#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int, int>
#define vii vector<pair<int, int>>
const int INF = 1e9;
//es O(n*log(n))
//peor caso(n^2)

// Función para intercambiar dos valores
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Función que coloca el pivote en su posición correcta
int partition(vi arr, int low, int high) {
    int pivot = arr[high]; // pivote (último elemento)
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Algoritmo QuickSort
void quickSort(vi arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);   // subarreglo izquierdo
        quickSort(arr, pi + 1, high); // subarreglo derecho
    }
}

// Función principal
int main() {
    vi arr = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

