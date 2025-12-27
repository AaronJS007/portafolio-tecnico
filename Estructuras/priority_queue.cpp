#include <bits/stdc++.h>
#include <queue>      // Para priority_queue
#include <vector>     // Para vector
#include <functional> // Para greater (aunque no lo usas directamente)
using namespace std;
struct Comparador {
    bool operator()(int a, int b) {
        return a > b; 
    }
};

int main() {
    priority_queue<int, vector<int>,Comparador> pq;
    return 0;
}