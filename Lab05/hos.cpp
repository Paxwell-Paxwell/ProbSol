#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100000

bool nhos[MAX_N];
bool shos[MAX_N];

bool checker[MAX_N];

vector<int> can_go(MAX_N, 0);
vector<int> hospital;
vector<int> adjacent[MAX_N];
vector<int> safe_village;



int n, m, k, h; 
int u, v, a;

void Push(int u) {
    if (!checker[u]) {
        safe_village.push_back(u);
        checker[u] = true;
    }
}


bool compare(int a, int b) {
    if (shos[a] == true && shos[b] == false) {
        return true;
    }
    else if (shos[a] == false && shos[b] == true) {
        return false;
    }
    else {
        return a < b;
    }
}

void get_input() {
    cin >> n >> m >> k >> h;
    for (int i = 0; i < k; i++) {
        cin >> a; a--;
        hospital.push_back(a);
    }
    for (int i = 0; i < k; i++) {
        cin >> u;
        if (u) {
            shos[hospital[i]] = true;
        }
        else {
            nhos[hospital[i]] = true;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> u >> v; u--; v--;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }
    sort(hospital.begin(), hospital.end(), compare);
}

void BFS(int hospital) {
    int far = h + h * shos[hospital];
    queue<int> q;
    vector<int> layer(n, -1);
    q.push(hospital);
    layer[hospital] = 0;
    if (can_go[hospital] == -1) {
        can_go[hospital] = far;
    } else {
        if (can_go[hospital] > far) {
            return;
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (layer[u] <= far) {
            Push(u);
        }
        for (int i = 0; i < adjacent[u].size(); i++) {
            int v = adjacent[u][i];
            if (layer[v] == -1) {
                layer[v] = layer[u] + 1;
                if (can_go[v] == -1) {
                    can_go[v] = far;
                } else if (can_go[v] < far - layer[v]) {
                    can_go[v] = far - layer[v];
                } else if (can_go[v] > far - layer[v]) {
                    continue;
                }
                q.push(v);
            }
        }
    }
}

void check_safe_village() {
    for (int hospital : hospital) {
        BFS(hospital);
    }
    cout << safe_village.size() << "\n";
}

// Main function
int main() {
    get_input();
    check_safe_village();
    return 0;
}