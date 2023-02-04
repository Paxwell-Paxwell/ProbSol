#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100000

int m, n;

vector<int> adjacent[MAX_N];
bool visited[MAX_N];
stack<int> storage;

void get_input() {
    for (int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v; u--; v--;
        adjacent[u].push_back(v);
    }
}

void dfs(int u) {
    visited[u] = true;
    int size = adjacent[u].size();
    for(int i=0; i<size; i++) {
        int v = adjacent[u][i];
        if(!visited[v]) {
            dfs(v);
        }
    }
    storage.push(u+1);
}

void check_cycle() {
    for (int i=0;i<n;i++) {
        if (!visited[i]) 
            dfs(i);
    }
}


int main() {
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        get_input();
        check_cycle();
        while (!storage.empty()) {
            cout << storage.top();
            if (storage.size() != 1)
                cout << " ";
            storage.pop();
            }
        cout << "\n";
        for (int i=0;i<n;i++) {
            adjacent[i].clear();
            visited[i] = false;
        }
    }
    return 0;
}