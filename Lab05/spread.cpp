#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100000

struct Edge {
    int a, b, w;
};

int n, m, di;
int a, b, d;

vector<int> spread;
vector<pair<int,int>> sort_spread;
vector<pair<int, int>> adjacent[MAX_N];
vector<bool> visited(MAX_N, false);
vector<Edge> all_edges;
vector<Edge> mst;

void get_input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> di;
        spread.push_back(di);
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> d; a--; b--;
        all_edges.push_back(Edge{a, b, d});
    }
}

bool cmp(Edge a, Edge b) { return a.w < b.w; }

int find(int x, vector<int> &parents) {
    if (parents[x] == x) return x;
    return parents[x] = find(parents[x], parents);
}

void kruskal() {
    sort(all_edges.begin(), all_edges.end(), cmp);  
    vector<int> parents(n);
    for (int i = 0; i < n; i++) parents[i] = i; 
    for (int i = 0; i < m; i++) {
        int a = all_edges[i].a, b = all_edges[i].b, w = all_edges[i].w;
        int pa = find(a, parents), pb = find(b, parents);
        if (pa != pb) {
            mst.push_back(Edge{a, b, w});
            adjacent[a].push_back({b, w});
            adjacent[b].push_back({a, w});
            parents[pa] = pb;
        }
    }
}


void solve() {
    int max = 0;
    for (Edge x : mst) {
        int day = (x.w % (spread[x.a] + spread[x.b]) == 0 ? x.w / (spread[x.a] + spread[x.b]) : x.w / (spread[x.a] + spread[x.b]) + 1);
        if (day > max)
            max = day;
    }
    cout << max << "\n";
}


int main() {
    get_input();
    kruskal();
    solve();
    return 0;
}
