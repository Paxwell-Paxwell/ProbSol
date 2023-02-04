#include <bits/stdc++.h>
using namespace std;


int n, r, x, y;
//0 0 at 0
//100 100 at 1
vector<int> adjacent[1002];
vector<pair<int, int> > node;
bool visited[1002];
int layer[1002];

void init() {
    node.push_back(make_pair(0, 0));
    node.push_back(make_pair(100, 100));
    layer[0] = 0;
}

void get_input() {
    cin >> n >> r;

    if (pow(100, 2) + pow(100, 2) <= pow(r, 2)) {
        adjacent[0].push_back(1);
        adjacent[1].push_back(0);
    }
    for (int i=0;i<n;i++) {
        cin >> x >> y;
        visited[i] = false;
        node.push_back(make_pair(x, y));
        for (int z=0;z<node.size()-1;z++) {
            if (pow(x-node[z].first, 2) + pow(y-node[z].second, 2) <= pow(r, 2)) {
                adjacent[z].push_back(node.size() - 1);
                adjacent[node.size() - 1].push_back(z);
            }
        }
    }

}
int bfs() {
    list<int> queue;
    queue.push_back(0);
    visited[0] = true;
    int count = 0;
    while (!queue.empty()) {
        int z1 = queue.front();
        queue.pop_front();
        count++;
        for (int z2=0;z2<adjacent[z1].size();z2++) {
            if (!visited[adjacent[z1][z2]]) {
                visited[adjacent[z1][z2]] = true;
                queue.push_back(adjacent[z1][z2]);
                layer[adjacent[z1][z2]] = layer[z1] + 1;
            }
            if (adjacent[z1][z2] == 1) {
                return layer[1];
                }
        }
    }
    return -1;
}

int main() {
    init();
    get_input();
    cout << bfs() << "\n";
    return 0;
}