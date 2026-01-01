#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int, int>
#define vii vector<pair<int, int>>
const int INF = 1e9;

//esto es o(n x log(n))

// Función para fusionar dos subarrays ordenados
void merge(vi& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Tamaño del subarray izquierdo
    int n2 = right - mid;    // Tamaño del subarray derecho
    
    // Crear arrays temporales
    vi L(n1), R(n2);
    
    // Copiar datos a los arrays temporales
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Índices para recorrer los subarrays
    int i = 0, j = 0, k = left;
    
    // Fusionar los arrays temporales de vuelta a arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copiar los elementos restantes de L[], si los hay
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copiar los elementos restantes de R[], si los hay
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Función principal de MergeSort
void mergeSort(vi& arr, int left, int right) {
    if (left < right) {
        // Encontrar el punto medio
        int mid = left + (right - left) / 2;
        
        // Ordenar primera y segunda mitad
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Fusionar las mitades ordenadas
        merge(arr, left, mid, right);
    }
}

// Wrapper para facilitar el uso
void mergeSort(vi& arr) {
    if (arr.size() > 1) {
        mergeSort(arr, 0, arr.size() - 1);
    }
}

// Función para imprimir el array
void printArray(const vi& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    vi arr = {38, 27, 43, 3, 9, 82, 10, 1, 56, 47};
    
    cout << "Array original: ";
    printArray(arr);
    
    mergeSort(arr);
    
    cout << "Array ordenado: ";
    printArray(arr);
    
    return 0;
}