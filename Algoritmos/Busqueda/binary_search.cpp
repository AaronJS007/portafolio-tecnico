#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define vi vector<int>
const int INF = 1e9;

//esto es O(log(n))

int binary_search_in_vector(vi arr, int n, int objetivo) {
    int izquierda = 0;
    int derecha = n - 1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (arr[medio] == objetivo)
            return medio;

        if (objetivo < arr[medio])
            derecha = medio - 1;
        else
            izquierda = medio + 1;
    }

    return -1; // No encontrado
}
