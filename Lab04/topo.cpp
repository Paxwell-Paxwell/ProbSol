#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100000

int m, n;


vector<int> adjacent[MAX_N];
bool visited[MAX_N];
stack<int> storage;
bool not_topo = false;

void get_input() {
    cin >> n >> m;
    for (int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v; u--; v--;
        adjacent[u].push_back(v);
    }
}

void dfs(int u, int s) {
    visited[u] = true;
    //cout << "A: " << u+1 << endl;
    int size = adjacent[u].size();
    for(int i=0; i<size; i++) {
        int v = adjacent[u][i];
        if (v == s) 
            not_topo = true;
        if(!visited[v]) {
            dfs(v, s);
        }
    }
    //cout << "push " << u+1 << endl;
    storage.push(u+1);
}

void check_cycle() {
    for (int i=0;i<n;i++) {
        if (!visited[i]) 
            dfs(i, i);
    }
}


int main() {
    get_input();
    check_cycle();
    if (not_topo)
        cout << "no\n";
    else {
        while (!storage.empty()) {
            cout << storage.top() << "\n";
            storage.pop();
        }
    }
    return 0;
}