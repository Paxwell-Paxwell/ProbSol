#include<bits/stdc++.h>
using namespace std;

#define MAXN 100000

struct Edge {
    int a, b, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};



int n, m;
int a, b, w;

vector<Edge> edges;
int parent[MAXN];
int Size[MAXN];

void get_input() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        Size[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w; a--; b--;
        edges.push_back({ a, b, w });
    }
    sort(edges.begin(), edges.end());
}

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void Get_MST() {
    int total = 0;
    for (int i = 0; i < m; i++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        int rootA = find(a), rootB = find(b);
        if (rootA != rootB) {
            total += w;
            if (Size[rootA] > Size[rootB]) {
                parent[rootB] = rootA;
                Size[rootA] += Size[rootB];
            }
            else {
                parent[rootA] = rootB;
                Size[rootB] += Size[rootA];
            }
        }
    }
    cout << total << "\n";
}

int main() {
    get_input();
    Get_MST();
    return 0;
}