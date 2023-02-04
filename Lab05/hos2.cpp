#include<bits/stdc++.h>
using namespace std;

#define MAX_N 1000

int n, m, h;
vector<int> adjacent[MAX_N];
vector<pair<int, int>> deg;
int mx = 0;

int cal_num(int node) {
    int count = 1;
    list<int> queue;
    int layer[n];
    fill_n(layer, n, -1);
    queue.push_back(node);
    layer[node] = 0;
    while (!queue.empty()) {
        int x = queue.front();
        queue.pop_front();
        for (int nod : adjacent[x]) {
            if (layer[nod] == -1) {
                layer[nod] = layer[x] + 1;
                queue.push_back(nod);
                if (layer[nod] <= h) {
                    count++;
                }
            }
        }
    }
    return count;
}

void get_input() {
    int a, b;
    cin >> n >> m >> h;
    // for (int i=0;i<n;i++) {
    //     deg.push_back(make_pair(0, i));
    // }
    for (int i=0;i<m;i++) {
        cin >> a >> b; a--; b--;
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
        // deg[a].first++;
        // deg[b].first++;
    }
    for (int i=0;i<n;i++) {
        int c = cal_num(i);
        if (c > mx) {
            mx = c;
        }
    }
    cout << mx << "\n";
}

int main() {
    get_input();
    return 0;
}