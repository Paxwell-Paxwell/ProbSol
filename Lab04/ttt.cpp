#include<bits/stdc++.h>
using namespace std;

#define MAX_N 1000

int n, m;
vector<int> adjacent[MAX_N];
set<int> problemNode;
int layer[MAX_N];

void get_graph() {
    int u, v;
    cin >> n >> m;
    for (int i=0;i<n;i++) {
        adjacent[i].clear();
        layer[i] = -1;
    }
    for(int i=0;i<m;i++) {
        cin >> u >> v; u--; v--;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }
}

void arr_layer() {
    for (int i=0;i<n;i++) {
        cout << i+1 << " layer: " << layer[i] << "\n";
    }
}

void bfs() {
    list<int> queue;
    for (int a=0;a<n;a++) {
        if (layer[a] != -1) continue;
        queue.push_back(a);
        layer[a] = 0;
        while (!queue.empty()) {
            int x = queue.front();
            queue.pop_front();
            for (int i=0;i<adjacent[x].size();i++) {
                if (layer[adjacent[x][i]] == -1) {
                    layer[adjacent[x][i]] = !layer[x];
                    queue.push_back(adjacent[x][i]);
                }
                else if (layer[x] == layer[adjacent[x][i]]) {
                    problemNode.insert(x);
                }
            }
        }
    }
}

bool checkBypartile(int node, int adjn) {
    list<int> queue;
    int layers[n];
    for (int a=0;a<n;a++) {
        layers[a] = -1;
    }
    for (int a=0;a<n;a++) {
        if (layers[a] != -1) continue;
        queue.push_back(a);
        layers[a] = 0;
        while (!queue.empty()) {
            int x = queue.front();
            queue.pop_front();
            for (int i=0;i<adjacent[x].size();i++) {
                if ((x == node && adjacent[x][i] == adjacent[node][adjn]) || (x == adjacent[node][adjn] && adjacent[x][i] == node)) {
                    continue;
                }
                if (layers[adjacent[x][i]] == -1) {
                    layers[adjacent[x][i]] = !layers[x];
                    queue.push_back(adjacent[x][i]);
                }
                else if (layers[x] == layers[adjacent[x][i]]) {
                    return false;
                }
            }
        }
    }
    return true;
}

void findaProblem() {
    for (int x : problemNode) {
        for (int i=0;i<adjacent[x].size();i++) {
            if (checkBypartile(x, i)) {
                cout << x + 1 << " " << adjacent[x][i] + 1 << "\n";
                return;
            }
        }
    }
}

int main() {
    get_graph();
    bfs();
    findaProblem();
    return 0;
}