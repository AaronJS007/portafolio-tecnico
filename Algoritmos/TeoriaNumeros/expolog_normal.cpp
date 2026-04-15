#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define vi vector<int>
const int INF = 1e9;

long long powRecursive(long long base, long long exponente, long long acumulador = 1) {
    if (exponente == 0) return acumulador;
    
    if (exponente & 1) {
        // Si es impar, multiplicar acumulador por base
        return powRecursive(base * base, exponente >> 1, acumulador * base);
    } else {
        // Si es par, solo elevar base al cuadrado
        return powRecursive(base * base, exponente >> 1, acumulador);
    }
}

// Función para exponenciación logarítmica con módulo
long long pow_mod_iterativo(long long base, long long exponente, long long mod) {
    if (mod == 1) return 0;  // Cualquier número módulo 1 es 0
    
    long long resultado = 1;
    base %= mod;  // Reducir base módulo mod primero
    
    while (exponente > 0) {
        // Si el exponente es impar, multiplicar por la base actual
        if (exponente & 1) {
            resultado = (resultado * base) % mod;
        }
        
        // Elevar al cuadrado la base
        base = (base * base) % mod;
        
        // Dividir el exponente entre 2
        exponente >>= 1;
    }
    
    return resultado;
}


int main(){
    cout<<"2 elevado a la 22: "<< powRecursive(2,22,1);
    return 0;
}