#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100000

int n, m, k;
int a, b;
vector<pair<int, int>> seq;
vector<int> adjacent[MAX_N];
vector<int> adjacent2[MAX_N];
bool mk[MAX_N];

void get_input() {
    cin >> n >> m >> k;
    for (int i=0;i<m;i++) {
        cin >> a >> b; a--; b--;
        seq.push_back(make_pair(a, b));
        adjacent2[a].push_back(b);
        adjacent2[b].push_back(a);
    }
    for (int i=0;i<n;i++) {
        if (adjacent2[i].size() >= k) {
            mk[i] = true;
        }
    }
    for (auto s : seq) {
        if (!(mk[s.first] || mk[s.second])) {
            adjacent[s.first].push_back(s.second);
            adjacent[s.second].push_back(s.first);
        }
    }
}

bool is_Bipartile() {
    vector<int> layer(n, -1);
    list<int> queue;
    for (int i=0;i<n;i++) {
        if (layer[i] != -1) continue;
        queue.push_back(i);
        layer[i] = 0;
        while (!queue.empty()) {
            int u = queue.front(); queue.pop_front();
            for (int v : adjacent[u]) {
                if (layer[v] == -1) {
                    layer[v] = !layer[u];
                    queue.push_back(v);
                }
                if (layer[v] == layer[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}

//print adjacent list
void print_adjacent() {
    for (int i=0;i<n;i++) {
        cout << i + 1 << ": ";
        for (int j=0;j<adjacent[i].size();j++) {
            cout << adjacent[i][j] + 1 << " ";
        }
        cout << "\n";
    }
}

void solve() {
    cout << (is_Bipartile() ? "yes" : "no") << "\n";
}

int main() {
    get_input();
    //print_adjacent();
    solve();
    return 0;
}