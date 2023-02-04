#include<bits/stdc++.h>
using namespace std;

#define MAX_N 50000

int n, m, s, t;

vector<int> radj[MAX_N];
vector<int> badj[MAX_N];

void get_input() {
    int a, b, c;
    cin >> n >> m >> s >> t; s--; t--;
    for (int i=0;i<m;i++) {
        cin >> a >> b >> c; a--; b--;
        if (c == 0) {
            radj[a].push_back(b);
            radj[b].push_back(a);
            badj[a].push_back(b);
            badj[b].push_back(a);
        } else if (c == 1) {
            radj[a].push_back(b);
            radj[b].push_back(a);
        } else if (c == 2) {
            badj[a].push_back(b);
            badj[b].push_back(a);
        }
    }
}

int BFS(vector<int> adj[MAX_N]) {
    int layer[MAX_N];
    fill_n(layer, n, -1);
    list<int> queue;
    queue.push_back(s);
    layer[s] = 0;
    while (!queue.empty()) {
        int x = queue.front();
        queue.pop_front();
        if (x == t) {
            return layer[x];
        }
        for (int u : adj[x]) {
            if (layer[u] == -1) {
                layer[u] = layer[x] + 1;
                queue.push_back(u);
            }
        }
    }
    return -1;
}

void solve() {
    int min = INT_MAX;
    int r = BFS(radj);
    int b = BFS(badj);
    if (r < min && r != -1) min = r;
    if (b < min && b != -1) min = b;
    if (min != INT_MAX) cout << min << "\n";
    else cout << -1 << "\n";
}

int main()
{
    get_input();
    solve();
    return 0;
}
