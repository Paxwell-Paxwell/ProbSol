#include<bits/stdc++.h>
using namespace std;

#define MAX_N 1000

int k, n, m;
vector<int> adjacent[MAX_N];
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

void bfs() {
    list<int> queue;
    queue.push_back(0);
    layer[0] = 0;

    while (!queue.empty()) {
        int x = queue.front();
        queue.pop_front();

        for (int i=0;i<adjacent[x].size();i++) {
            if (layer[adjacent[x][i]] == -1) {
                layer[adjacent[x][i]] = !layer[x];
                queue.push_back(adjacent[x][i]);
            }
            else if (layer[x] == layer[adjacent[x][i]]) {
                cout << "no\n";
                return;
            }
        }
    }
    cout << "yes\n";
}

int main() {
    cin >> k;
    for (int i=0;i<k;i++) {
        get_graph();
        bfs();
    }
    return 0;
}