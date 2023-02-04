#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100000

int n, m, I;
int u, v;
//vector<int> adj[MAX_N];
vector<pair<int, int>> aadj;

//optimize this code

//check for bipartile graph even graph is not connect


bool is_bipartile(int end) {
    //cout << end << endl;
    int i;
    vector<int> adj[n];
    for (i=0;i<end;i++) {
        u = aadj[i].first, v = aadj[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(n, -1);
    for (i=0;i<n;i++) {
        if (color[i] != -1) continue;
        queue<int> q;
        color[i] = 0;
        q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}

void devide(int start, int end) {
    int half = (start + end)/2;
    //cout << start << " " << half << " " << end << "\n";
    if (end - start <= 2) {
        for (int i=0;i<=2;i++) {
            //cout << "Check@" << start + i << "\n";
            if (!is_bipartile(start + i)) {
                I = start + i - 1;
                return;
            }
        }
    }
    //cout << !is_bipartile(half) << " " << !is_bipartile(end) << "\n";
    if (!is_bipartile(half)) {
        devide(start, half);
    } 
    else if (!is_bipartile(end)) {
        devide(half, end);
    }
}


void read_input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v; u--; v--;
        aadj.push_back(make_pair(u, v));
    }
}

//write main
int main() {
    read_input();
    devide(0, m);
    cout << I << endl;
    return 0;
}

