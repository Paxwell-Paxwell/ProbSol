#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100000

struct path {
    int dest;
    int special;
};

int n, m, k, h;

bool magic_school[MAX_N];
bool checker[MAX_N];
vector<int> magic_school2;
vector<path> adjacent[MAX_N];

void get_input() {
    int a, b, c;
    cin >> n >> m >> k >> h;
    for (int i=0;i<k;i++) {
        cin >> c; c--;
        magic_school[c] = true;
    }
    for (int i=0;i<m;i++) {
        cin >> a >> b >> c; a--; b--;
        adjacent[a].push_back({b, c});
        adjacent[b].push_back({a, c});
    }
}

void push(int x) {
    if (!checker[x]) {
        checker[x] = true;
        magic_school2.push_back(x);
    }
}

void BFSs(int start, int lay) {
    list<int> queue;
    int layer[n];
    fill_n(layer, n, -1);
    layer[start] = lay;
    queue.push_back(start);
    while (!queue.empty()) {
        int x = queue.front();
        queue.pop_front();
        if (layer[x] > h) {
            break;
        }
        for (auto p : adjacent[x]) {
            if (layer[p.dest] == -1) {
                layer[p.dest] = layer[x] + 1;
                if (layer[p.dest] <= h) {
                    push(p.dest);
                }
                queue.push_back(p.dest);
            }
        }
    }
}


void BFS() {
    list<int> queue;
    int layer[n];
    fill_n(layer, n, -1);
    queue.push_back(0);
    layer[0] = 0;
    push(0);
    while (!queue.empty()) {
        int x = queue.front();
        queue.pop_front();
        if (layer[x] > h) {
            break;
        }
        for (auto p : adjacent[x]) {
            if (layer[p.dest] == -1) {
                if (p.special) {
                    continue;
                }
                layer[p.dest] = layer[x] + 1;
                if (layer[p.dest] <= h) {
                    push(p.dest);
                }
                
                if (magic_school[p.dest]) {
                    BFSs(p.dest, layer[p.dest]);
                } 
                else {
                    queue.push_back(p.dest);
                }
            }
        }
    }
    cout << magic_school2.size() << "\n";
}

int main() {
    get_input();
    BFS();
    return 0;
}