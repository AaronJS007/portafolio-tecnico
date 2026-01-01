#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

struct Nodo {
    vector<pair<char, Nodo*>> hijos;
    int cnt_prefijo = 0;
    int cnt_palabra = 0;

    Nodo* buscarHijo(char c) {
        for (auto& par : hijos) {
            if (par.first == c) return par.second;
        }
        return nullptr;
    }

    void agregarHijo(char c, Nodo* hijo) {
        hijos.push_back({c, hijo});
    }
};

   int contarPalabras(Nodo* n) {
    if (!n) return 0;
    int i = n->cnt_palabra;
    for (auto& hijo : n->hijos)  i += contarPalabras(hijo.second);
    return i;
}

    int contarNodos(Nodo* n) {
    if (!n) return 0;
    int i = 1;
    for (auto& hijo : n->hijos) i += contarNodos(hijo.second);
    return i;
}

    bool compararHijos(const pair<char, Nodo*>& a, const pair<char, Nodo*>& b) {
    int Ca = contarPalabras(a.second);
    int Cb = contarPalabras(b.second);
    
    if (Ca != Cb) return Ca < Cb;
    
    int Na = contarNodos(a.second);
    int Nb = contarNodos(b.second);

    if (Na != Nb) return Na < Nb;
    
    return a.first < b.first;
}

struct Trie {
    Nodo* raiz;
    vector<char>palabra;
    int catNodos;

    Trie() { 
        raiz = new Nodo();
        catNodos=0;
    }

    pair<int,int> consultas(string &q) {
        Nodo* nodo = raiz;
        ull i = 0;
        
        while(i < q.length()) {
            char c = q[i] | ' ';
            nodo = nodo->buscarHijo(c);
            if (!nodo) return {0,0};
            i++;
        }
        return {nodo->cnt_palabra, nodo->cnt_prefijo};     
    }
   
    void insertar(string &s) {
        Nodo* nodo = raiz;
        for (char c : s) {
            c |= ' ';
            Nodo* hijo = nodo->buscarHijo(c);
            if (!hijo) {
                hijo = new Nodo();
                nodo->agregarHijo(c, hijo);
                catNodos++;
            }
            nodo = hijo;
            nodo->cnt_prefijo++;
        }
        if(nodo->cnt_palabra == 0) nodo->cnt_palabra = 1;
    }

    vector<pair<char, Nodo*>> ordenarHijos(Nodo* nodo) {
    vector<pair<char, Nodo*>> hijos_ordenados = nodo->hijos;
    sort(hijos_ordenados.begin(), hijos_ordenados.end(), compararHijos);
    return hijos_ordenados;
}

    void DFSAux(Nodo* nodo) {
        if (nodo == nullptr) return;
        
        if (nodo->cnt_palabra > 0) {
            palabra.push_back('P');
        }

        if (nodo->hijos.empty()) return;
        
        vector<pair<char, Nodo*>> hijos_ordenados = ordenarHijos(nodo);
        int total_hijos = hijos_ordenados.size();
        
        for (int i = 0; i < total_hijos; i++) {
            palabra.push_back(hijos_ordenados[i].first);
            DFSAux(hijos_ordenados[i].second);
            
            if (i < total_hijos - 1) palabra.push_back('-');
        }
        
        if (nodo != raiz) palabra.push_back('-');
    }

    void DFS() {
        palabra.clear();
        DFSAux(raiz);
        
        while (!palabra.empty() && palabra.back() == '-') palabra.pop_back();
        
        cout << palabra.size() << "\n";
        for (char op : palabra) cout << op << "\n";
    }};