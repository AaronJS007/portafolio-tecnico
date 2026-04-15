#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define vi vector<int>
const int INF = 1e9;

//esto es O(log(n))

int binary_search_recursive(int n, int left,int right,double error){
    double medio = (left+right)/2;
    if(abs(medio*medio-n)<= error) return medio;

    if(medio*medio > n){
            return binary_search_recursive(n, left, medio, error);
    } else {
        return binary_search_recursive(n, medio, right, error);
    }
}

int main(){
    const int e=0.0001;
    cout << "La raiz del numero 25 es: " << binary_search_recursive(25,0,25,e) <<"\n";
    return 0;
}