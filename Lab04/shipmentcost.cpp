#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100000

int n, m, s, t;

vector<int> adjacent[MAX_N];

vector<int> factory;
vector<int> warehouse;
bool lwarehouse[MAX_N];
bool lfactory[MAX_N];

int shortest_dis[MAX_N];


void get_input() {
    int a, b;
    cin >> n >> m >> s >> t;
    for (int i=0;i<m;i++) {
        cin >> a >> b; a--; b--;
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }
    for (int i=0;i<s;i++) {
        cin >> a; a--;
        warehouse.push_back(a);
        lwarehouse[a] = true;
    }
    for (int i=0;i<t;i++) {
        cin >> a; a--;
        factory.push_back(a);
        lfactory[a] = true;
    }
}

int find_min_fac(int factory) {
    if (lwarehouse[factory]) {
        return 0;
        }
    int layer[n];
    fill_n(layer, n, -1);
    list<int> queue;
    queue.push_back(factory);
    layer[factory] = 0;
    while (!queue.empty()) {
        int x = queue.front();
        queue.pop_front();
        for (int node : adjacent[x]) {
            if (lwarehouse[node]) {
                return layer[x] + 1;
            }
            if (layer[node] == -1) {
                layer[node] = layer[x] + 1;
                queue.push_back(node);
            }
        }
    }
    return -1;
}

void find_min_war() {
    fill_n(shortest_dis, n, -1);

    for (int ware : warehouse) {
        //cout << "ware: " << ware + 1 << "\n";
        if (lfactory[ware]) {
            shortest_dis[ware] = 0;
        }
        int layer[n];
        fill_n(layer, n, -1);
        list<int> queue;
        queue.push_back(ware);
        layer[ware] = 0;
        while (!queue.empty()) {
            int x = queue.front();
            queue.pop_front();
            for (int node : adjacent[x]) {
                if (lfactory[node] && (shortest_dis[node] > layer[x] + 1 || shortest_dis[node] == -1)) {
                    shortest_dis[node] = layer[x] + 1;
                    //cout << "Update Shortest path at " << node << " " << shortest_dis[node] << "\n";
                }
                if (layer[node] == -1) {
                    layer[node] = layer[x] + 1;
                    queue.push_back(node);
                }
            }
        }
    }
}

void find_all_min() {
    if (t <= 5) {
        for (int x : factory) {
            cout << find_min_fac(x) << "\n";
        }
    }
    else if (s <= 5) {
        find_min_war();
        for (int x : factory) {
            cout << shortest_dis[x] << "\n";
        }
    }
}

int main() {
    get_input();
    find_all_min();
    return 0;
}