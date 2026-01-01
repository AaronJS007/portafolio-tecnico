#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

struct Nodo {
    map<char, Nodo*> hijos;
    int cnt_prefijo = 0;
    int cnt_palabra = 0;
};

struct Trie {
    Nodo* raiz;
    int catNodos;
    int cantOP;

    Trie() { 
        raiz = new Nodo();
        catNodos=0; 
    }

    void insertar(string &s) {
        Nodo* nodo = raiz;
        for (char c : s) {
            c|=' ';
            if (!nodo->hijos.count(c)) {
                nodo->hijos[c] = new Nodo();
                catNodos++;
            }
            nodo = nodo->hijos[c];
            nodo->cnt_prefijo++;
        }
        nodo->cnt_palabra+=1;
    }

    pair<int,int> consultas(string &q){
        
        Nodo* nodo = raiz;
        ull i =0;
        
        while(i<q.length()) {
            char c = q[i] | ' ';
            if (!nodo->hijos.count(c)) return {0,0};
            i++;
            nodo = nodo->hijos[c];
        }
        return {nodo->cnt_palabra,nodo->cnt_prefijo};     
    }
    void consultas2(string &q){
        
        Nodo* nodo = raiz;
        ull i =0;
        
        while(i<q.length()) {
            char c = q[i] | ' ';
            if (!nodo->hijos.count(c)) {cout<<"0 0 \n"; return;}
            i++;
            nodo = nodo->hijos[c];
        }
        cout<<nodo->cnt_palabra<<" "<< nodo->cnt_prefijo<<"\n";     
    }

    int getCantidadNodos(){
        return catNodos;
    }

    void AuxLetrasPermutadas(string palabra,string cola,Nodo*x){

        if(palabra.empty()){
            if(x->cnt_palabra>0)cout<< cola << " ";
        }
        //caso base es cuando ya no hay letras
        unordered_set <char> usadas;
        for(ull i=0;i<palabra.size();i++){
            char c = palabra[i];
            if(!usadas.count(c)&&x->hijos.count(c)){
                AuxLetrasPermutadas(palabra.substr(0,i)+palabra.substr(i+1),cola+c,x->hijos[c]);
                usadas.insert(c);
            }
        } 
    }

    void LetrasPermutantes(string &palabra){
        if(palabra.empty()) return;
        sort(palabra.begin(),palabra.end());
        AuxLetrasPermutadas(palabra,"",raiz);
    }
};